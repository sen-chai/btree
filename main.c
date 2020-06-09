#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <btree.c>
#include <populate.h>

int main(void){

    FILE *indexHeader = bringFile("index_header.dat");
    FILE *indexFile = bringFile("index.dat");
    FILE *dataFile = bringFile("data.dat");
    BTREE *tree = loadIndexHeader(indexHeader);

    PAGE *pg = createEmptyIndexPage();
    STUDENT st;
    int command, search, register_position,key;
    command, search, register_position,key = 0;
    int only_once_populate = 1;
	do {
		printf("Insira numero da opreacao: \n\t* 1 .Gravar\n\t* 2 .Pesquisar nUSP\n\t* 3 .Popular Automaticamente chaves[20-200]~aprox. estao ocupadas\n\t* 0 .Finalizar\n\n");
		scanf("%d",&command);
		if (command == 1) {
            enterStudent(&st);
            register_position = searchStudentByKey(indexFile,tree,st.numUSP);
            if(register_position != -1){
                printf("Chave ja Existe, operacao cancelada \n");
                continue;
            }
            insertStudent(dataFile,indexFile,tree,pg,&st);
		}
		else if (command ==2 ) {
            printf("\nDigite chave a ser pesquisada:");
            scanf("%d",&key);
            printf("procurando chave %d\n",key);
            register_position = searchStudentByKey(indexFile,tree,key);
            if(register_position==-1){
                printf("Chave nao existe, busca cancelada\n");
            }
            else{
                printf("Resultado da Busca:\n");
                getStudent(dataFile,register_position);
            }
		}
        else if(command ==3 && only_once_populate){
            for(int i = 0; i< populate_size; i++){
                insertStudent(dataFile,indexFile,tree,pg,&sts[i]);
            }
            only_once_populate =0;
            printf("Insercao automatica realizada\n\n");
        }
        else{
            break;
        }
	} while(command> 0);    

    storeIndexHeader(indexHeader,tree);
    fclose(indexHeader);
    fclose(indexFile);
    fclose(dataFile);
    free_page(&pg);
    return 0;
}