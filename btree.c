#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// #include "btree.h"

#define PAGESIZE 256 
#define STUDENTFIELD 16
#define INTFIELD 8
#define ORDER 3

typedef struct STUDENT STUDENT;
typedef struct PAGE PAGE;
typedef struct BTREE BTREE;

struct STUDENT{
	int numUSP;
	char name[STUDENTFIELD];
	char surname[STUDENTFIELD];
	char course[STUDENTFIELD];
	float grade;
} ;

struct PAGE{
	int isleaf;
	int pagerrn;
	int nkeys;
	int *keys;
	int *rrns;
	int *children;
	void *freespace;
} ;

struct BTREE {
	int quant;
	int lastpagerrn;
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

BTREE *loadBtreeHeader(FILE*file){
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
		fscanf(file,"%d%d%d%d",&tree->quant,&tree->lastpagerrn,&tree->height,&tree->root);
	}
	return tree;
}

void storeBtreeHeader(FILE*file,BTREE*tree){
	fseek(file,tree->root*PAGESIZE,SEEK_SET);
	fprintf(file,"%d %d %d %d ",tree->quant,tree->lastpagerrn,tree->height,tree->root);
}

PAGE *firstPageLoad(FILE*file,BTREE*tree){
	PAGE *pg = NULL;
	fseek(file,0,SEEK_END);
	int fileEnd = ftell(file);
	if(fileEnd == 0){
		pg = (PAGE*) calloc(1,sizeof(PAGE));
		printf("\nfile was empty\n");
	}
	else{
		pg = (PAGE*) malloc(sizeof(PAGE));
		fseek(file,tree->root*PAGESIZE,SEEK_SET);
		fscanf(file,"%d%d%d",&pg->isleaf,&pg->pagerrn,&pg->nkeys);
		for(int i = 0; i<pg->nkeys ; i++){
			fscanf(file,"%d%d%d",&pg->keys[i],&pg->rrns[i],&pg->children[i]);
		}
		fscanf(file,"%d",&pg->children[pg->nkeys]);
	}
	return pg;
}

int *getPage(FILE*file,BTREE*tree,PAGE*pg,int pos){
	fseek(file, pos*PAGESIZE, SEEK_SET);
	fscanf(file,"%d%d%d", &pg->isleaf, &pg->pagerrn, &pg->nkeys);
	for(int i = 0; i<pg->nkeys ; i++){
		fscanf(file,"%d%d%d",&pg->keys[i],&pg->rrns[i],&pg->children[i]);
	}
	fscanf(file,"%d",&pg->children[pg->nkeys]);
}

void storePage(FILE*file,BTREE*tree,PAGE*pg){
	
}

int searchStudentRRN(PAGE *n, int key){
	for(int i = 0; i<n->nkeys ; i++){
		if(n->keys[i]==key) return n->rrns[i];
		if(!n->isleaf){ // is parent
			if(key < n->keys[i] ){
				n = n->children[i];
				n = loadPage;
				if(key > n->keys[i]){ // PAGE's last student
					n = n->children[i+1];
				}
				searchStudentRRN(n,key);
			}
		}
	}
	return -1;
}
void printStudent(STUDENT s){
	printf("\n%d|%s|%s|%s|%f\n",s.numUSP,s.name,s.surname,s.course,s.grade);
}

STUDENT enterStudent(){
	// printf("Insira os dados na seguinte Ordem:\n \t 1.numUSP \t 2.Nome \t 3.Sobrenome  \t 4.Curso  \t 5.nota \n");
	// printf("Numero USP: " );scanf("%d",&aluno.numUSP);
	// printf("\nNome: " );scanf("\n%[^\n\r]",aluno.nome);
	// printf("\nSobrenome: " );scanf("\n%[^\n\r]",aluno.sobrenome);
	// printf("\nCurso: " );scanf("\n%[^\n\r]",aluno.curso);
	// printf("\nNota: " );scanf("%e",&aluno.nota);
}
	
BTREE insertStudent(FILE *file, BTREE *tree, STUDENT s){
}