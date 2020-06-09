#include <stdlib.h>
#include <stdio.h>

#define BUFFERSIZE 256 
#define ORDER 3
#define INTFIELD 10
#define STRFIELD 16
#define PAGESIZE 3*INTFIELD+3*ORDER*INTFIELD-2
#define PAGEFREESPACE BUFFERSIZE-PAGESIZE
#define STUDENTSIZE (2*INTFIELD+3*STRFIELD)

typedef struct STUDENT STUDENT;
struct STUDENT{
	int numUSP;
	char name[STRFIELD];
	char surname[STRFIELD];
	char course[STRFIELD];
	float grade;
} ;
typedef struct PAGE PAGE;
struct PAGE{ // indexFile page, not dataFile page
	int isparent;
	int pagerrn;
	int nkeys;
	int *keys;
	int *rrns;
	int *children;
	void *freespace;
} ;
PAGE *createEmptyIndexPage(){
	PAGE *pg = (PAGE*) calloc(1,sizeof(PAGE));
	pg->keys = (int*) calloc(ORDER,sizeof(int));
	pg->rrns = (int*) calloc(ORDER,sizeof(int));
	pg->children = (int*) calloc(ORDER+1,sizeof(int));
    return pg;
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
int main(void){
    PAGE*pg = createEmptyIndexPage();   
    printPage(pg);

    return 0;
}