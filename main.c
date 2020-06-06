#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <btree.c>

int main(void){

    STUDENT st[] = {
        {11,"jonathan","joestar","DD",1.1},
        {12,"joseph","joestar","DD",2.2},
        {13,"jotaro","kujo","DD",3.3},
        {14,"josuke","joestar","DD",4.4},
        {15,"giorno","giovana","DD",5.5},
        {16,"jolyne","kujo","DD",6.6},
    };

    FILE *indexHeader = bringFile("index_header.dat");
    FILE *indexFile = bringFile("index.dat");
    FILE *dataFile = bringFile("data.dat");
    BTREE *tree = loadIndexHeader(indexHeader);

    printf("* before insertStudent\n");
    PAGE *pg = createEmptyIndexPage();
    insertStudent(dataFile,indexFile,tree,pg,&st[0]);
    insertStudent(dataFile,indexFile,tree,pg,&st[1]);
    insertStudent(dataFile,indexFile,tree,pg,&st[2]);
    insertStudent(dataFile,indexFile,tree,pg,&st[3]);
    printPage(pg);

    


    storeIndexHeader(indexHeader,tree);
    fclose(indexHeader);
    fclose(indexFile);
    return 0;
}