#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// #include "btree.h"

#define BUFFERSIZE 256 
#define ORDER 3
#define INTFIELD 8
#define STRFIELD 16
#define PAGESIZE 3*INTFIELD+3*ORDER*INTFIELD-2
#define PAGEFREESPACE BUFFERSIZE-PAGESIZE
#define STUDENTSIZE 2*INTFIELD+3*STRFIELD

typedef struct STUDENT STUDENT;
typedef struct PAGE PAGE;
typedef struct BTREE BTREE;

struct STUDENT{
	int numUSP;
	char name[STRFIELD];
	char surname[STRFIELD];
	char course[STRFIELD];
	float grade;
} ;

struct PAGE{ // indexFile page, not dataFile page
	int isparent;
	int pagerrn;
	int nkeys;
	int *keys;
	int *rrns;
	int *children;
	void *freespace;
} ;

struct BTREE {
	int last_page_rrn; // n de paginas/ nos 
	int last_data_rrn; // arquivo de dados
	int height;
	int root;
};

FILE *bringFile(char* fileName) {
    FILE* file= fopen(fileName, "r+");

    if (file == NULL){
        file = fopen(fileName, "w");
        fclose(file);
	    file = fopen(fileName, "r+");
	}
    return file;
}

BTREE *loadIndexHeader(FILE*file){
	// guarda o cabecalho da btree, contem as especificacoes, da arvore,  
	// retorna a arvore B
	BTREE *tree = NULL;
	fseek(file,0,SEEK_END);
	int fileEnd = ftell(file);
	if(fileEnd == 0){
		tree = (BTREE*) calloc(1,sizeof(BTREE));
		printf("\nfile was empty\n");
	}
	else{
		tree = (BTREE*) malloc(sizeof(BTREE));
		fseek(file,0,SEEK_SET);
		fscanf(file,"%d%d%d%d",&tree->last_page_rrn,&tree->last_data_rrn,&tree->height,&tree->root);
	}
	return tree;
}

void storeIndexHeader(FILE*file,BTREE*tree){
	fseek(file,0,SEEK_SET);
	fprintf(file,"%-*d %-*d %-*d %-*d ",INTFIELD, tree->last_page_rrn,INTFIELD, tree->last_data_rrn,INTFIELD, tree->height,INTFIELD, tree->root);
}

PAGE *createEmptyIndexPage(){
	PAGE *pg = (PAGE*) calloc(1,sizeof(PAGE));
	pg->keys = (int*) calloc(ORDER,sizeof(int));
	pg->rrns = (int*) calloc(ORDER,sizeof(int));
	pg->children = (int*) calloc(ORDER+1,sizeof(int));
	// pg->freespace = (void*) calloc(1,PAGEFREESPACE);
	return pg;
}

PAGE *getIndexPage(FILE*file,PAGE*pg,int pos){
	fseek(file,pos*BUFFERSIZE,SEEK_SET);
	fscanf(file,"%d%d%d", &pg->isparent, &pg->pagerrn, &pg->nkeys);
	for(int i = 0; i<pg->nkeys; i++){
		fscanf(file,"%d",&pg->keys[i]);
	}
	for(int i = 0; i<pg->nkeys ; i++){
		fscanf(file,"%d",&pg->rrns[i]);
	}
	for(int i = 0; i<pg->nkeys ; i++){
		fscanf(file,"%d",&pg->children[i]);
	}
	// ultima childern
	fscanf(file,"%d",&pg->children[pg->nkeys]);
	return pg;
}

void storeIndexPage(FILE*file, PAGE *pg){
	fseek(file,pg->pagerrn*BUFFERSIZE,SEEK_SET);
	fprintf(file,"%-*d%-*d%-*d",INTFIELD, pg->isparent,INTFIELD, pg->pagerrn,INTFIELD, pg->nkeys);
	for(int i = 0; i<pg->nkeys ; i++){
		fprintf(file,"%-*d",INTFIELD,pg->keys[i]);
	}
	for(int i = 0; i<pg->nkeys ; i++){
		fprintf(file,"%-*d",INTFIELD,pg->rrns[i]);
	}
	for(int i = 0; i<pg->nkeys ; i++){
		fprintf(file,"%-*d",INTFIELD,pg->children[i]);
	}
	// registrar ultima child rrn
	fprintf(file,"%-*d",INTFIELD, pg->children[pg->nkeys]);
	fprintf(file,"%*s",PAGEFREESPACE,"");
}

void printPage(PAGE *pg){
	printf("isparent:%-*dpagerrn:%-*dnkeys:%-*d\n",INTFIELD, pg->isparent,INTFIELD, pg->pagerrn,INTFIELD, pg->nkeys);
	for(int i = 0; i<pg->nkeys ; i++){
		printf("%-*d",INTFIELD,pg->keys[i]);
	}
	for(int i = 0; i<pg->nkeys ; i++){
		printf("%-*d",INTFIELD,pg->rrns[i]);
	}
	for(int i = 0; i<pg->nkeys ; i++){
		printf("%-*d",INTFIELD,pg->children[i]);
	}
	printf("%-*d",INTFIELD, pg->children[pg->nkeys]);
}

void printStudent(STUDENT st){
	printf("\n%d|%s|%s|%s|%f\n",st.numUSP,st.name,st.surname,st.course,st.grade);
}

int searchStudentByKey(FILE*file,BTREE*tree, PAGE*pg, int key){
	printf("%d\n",pg->nkeys);
	for(int i = 0; i<pg->nkeys ; i++){
		if(pg->keys[i]==key) return pg->rrns[i]; // achou a chave
		if(pg->isparent){ 
			if(key < pg->keys[i] ){ // necessidade de procurar proxima pagina
				pg = getIndexPage(file,pg,pg->children[i]);
			}
			else if(i==pg->nkeys-1 && key>pg->keys[i]){ // ultimo estudante da pagina 
				pg = getIndexPage(file,pg,pg->children[i+1]);
			}
			return searchStudentByKey(file,tree,pg,key);
		}
	}
	return -1; // not found
}

void enterStudent(STUDENT*st){
	// check the max values, if the char passes, files might break
	// printf("Insira os dados na seguinte Ordem:\n \t 1.numUSP \t 2.Nome \t 3.Sobrenome  \t 4.Curso  \t 5.nota \n");
	// printf("Numero USP: " );scanf("%d",&aluno.numUSP);
	// printf("\nNome: " );scanf("\n%[^\n\r]",aluno.nome);
	// printf("\nSobrenome: " );scanf("\n%[^\n\r]",aluno.sobrenome);
	// printf("\nCurso: " );scanf("\n%[^\n\r]",aluno.curso);
	// printf("\nNota: " );scanf("%e",&aluno.nota);
	// return STUDENT;
}

int insertKeyToPage(BTREE*tree,PAGE*pg,int key){
	// insercao da chave em pagina usando insertion sort
	// retorna 1 ou 0, se tiver lotacao total (overflow) ou nao
	if(pg->isparent) {
		printf("* Tried inserting on a parent\n");
		return;
	}
	for(int i = 0; i<pg->nkeys ; i++){
		if(key<pg->keys[i]){
			// deslocar insercao a esquerda
			memcpy(&pg->keys[i+1],&pg->keys[i],(pg->nkeys-i)*sizeof(int));
			memcpy(&pg->rrns[i+1],&pg->rrns[i],(pg->nkeys-i)*sizeof(int));
			pg->keys[i] = key;
			pg->rrns[i] = tree->last_data_rrn++;
			pg->nkeys++;
			return 1;
		}
	}
	pg->keys[pg->nkeys] = key;
	pg->nkeys++;
	pg->rrns[pg->nkeys] = tree->last_data_rrn++;
	return 0;
}
int promote(PAGE*parent,int prom_key,int prom_rrn,int child){
	// insere valores do overflow
	// OBS todos os vetores tem expaco extra para comportar overflow, facilitando organizacao
	for(int i = 0; i<parent->nkeys ; i++){
		if(prom_key<parent->keys[i]){
			// deslocar insercao a esquerda
			memcpy(&parent->keys[i+1],&parent->keys[i],(parent->nkeys-i)*sizeof(int));
			memcpy(&parent->rrns[i+1],&parent->rrns[i],(parent->nkeys-i)*sizeof(int));
			parent->keys[i] = prom_key;
			parent->rrns[i] = prom_rrn; 

			// children tem comportamento diferente dos demais
			memcpy(&parent->children[i+2],&parent->children[i+1],(parent->nkeys-i)*sizeof(int));
			parent->children[i+1] = child;

			parent->nkeys++;
			return 1;
		}
	}
	return 0;
}

void rootOverflow(PAGE *new_parent,PAGE*newpg,PAGE*pg){
	if(root_overflow){
		PAGE *newpg = createEmptyIndexPage();

		PAGE *new_parent = createEmptyIndexPage();
		new_parent->isparent = 1;
		new_parent->pagerrn = ++tree->last_page_rrn;
		splitParent(new_parent,newpg,pg);

	}
	// update root
}
void overflow(FILE*indexFile,BTREE *tree,PAGE*pg,int height,int parent_tracks[]){
	// lida com splits e overflows de folhas e parents que nao sejma root
	// height: ordem de parent_tracks eh do parent mais proximo do filho para a raiz, por isso height inicia do zero, queremos recuperar o lastro de parents
	PAGE *newpg = createEmptyIndexPage();
	// split de folhas
	int half, newpg->nkeys = (int) pg->nkeys/2;
	if(pg->nkeys%2 == 0) newpg->nkeys--;
	// quando o original for par, newpg split tera um elemento a menos
	for(int i = 0; i<newpg->nkeys ; i++){
		newpg->keys[i] = pg->keys[half+i];
		newpg->rrns[i] = pg->rrns[half+i];
		// poderia zerar o valor das chaves e rrns mas vou deixa-los como lixo
	}
	newpg->pagerrn = ++tree->last_page_rrn;
	storeIndexPage(indexFile,newpg);
	free(newpg);

	pg->nkeys = half;
	storeIndexPage(indexFile,pg);

	int promoted_key = pg->keys[half];
	int promoted_rrn = pg->rrns[half];
	int pg_overflow = 0;
	int root_overflow = 0;
	getIndexPage(indexFile,pg, parent_tracks[height++]);
	promote(pg,promoted_key,promoted_rrn,newpg->pagerrn);
	if(pg->pagerrn == tree->root){
		root_overflow =1;
	}
}

BTREE insertStudent(FILE *dataFile, FILE*indexFile, BTREE *tree,PAGE*pg, STUDENT *st){
	pg = getIndexPage(indexFile,pg,tree->root) ;
	int key = st->numUSP;
	int rrn = searchStudentByKey(indexFile,tree,pg,key);
	if( rrn != -1){
		// Valor ja existe e sera atualizado
		printf("* Update Student value");
	}
	else {
		// eoncontrar pagina folha correta
		int parent_tracks[tree->height];
		int depht = tree->height;
		// lastro de quais parents foram percorridos, ordenados inversamente a trajetoria percorrida
		pg = getIndexPage(indexFile,pg,tree->root);
		printf("got page _%d_\n",pg->pagerrn);
		while(pg->isparent){
			printf("* found a parent\n");
			for(int i = 0; i<pg->nkeys ; i++){
				if(key < pg->keys[i] ){ // necessidade de procurar proxima pagina
					parent_tracks[--depht] = pg->pagerrn;
					pg = getIndexPage(indexFile,pg,pg->children[i]);
					break;
				}
				else if(i==pg->nkeys-1){
					parent_tracks[--depht] = pg->pagerrn;
					pg = getIndexPage(indexFile,pg,pg->children[pg->nkeys]);
				}
			}
		}
		int overflow = insertKeyToPage(pg,st->numUSP,tree);
		storeIndexPage(indexFile,pg);
		// insercao em arquivo de dados
		fseek(dataFile,0,SEEK_END);
		fprintf(dataFile,"%-*d%-*s%-*s%-*s%-8.2f",INTFIELD, st->numUSP,STRFIELD, st->name,STRFIELD, st->surname,STRFIELD, st->course, st->grade);

		if(pg->nkeys >= ORDER){ // esta cheio
			// leafOverflow(indexFile,tree,pg,0,parent_tracks);
		}
		else {

		}
	}
}
