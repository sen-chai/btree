#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <btree.c>

int main(void){

    STUDENT st[] = {
        {1,"jonathan","joestar","DD",1.1},
        {2,"joseph","joestar","DD",2.2},
    };
    printStudent(st[0]);
    printStudent(st[1]);

    FILE *indexHeader = bringFile("index_header.dat");
    FILE *indexFile = bringFile("index.dat");
    BTREE *tree = loadBtreeHeader(indexHeader);
    storeBtreeHeader(indexHeader,tree);

    fclose(indexHeader);
    fclose(indexFile);
    return 0;
}