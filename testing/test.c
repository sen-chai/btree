#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define FIELD 8
#define PAGESIZE 256
#define PAGEFREESPACE PAGESIZE-10*FIELD

typedef struct{
    int a;
    char c[16];
} dd;

typedef struct{
    int *a;
} cc;
int main()
{
    dd s[] ={
        {1,"str"},
        {2,"hello"}
    };
    printf("%d\n",s[0].a);

    // printf( ":%-*d:\n", FIELD, 1234567);
    printf( ":%-*d: :%-*d:\n", FIELD, 1234567, FIELD, 4321);

    // WORKING !!!
    printf("float:%*.2f:\n",FIELD, 1.23);
    printf( ":%-*s: %-*s%-*s%-8.2f:\n", 15, "#########################",16,"hello",16,"mama",1.23);
    // dot on string will fill just the ammout specified, that is dynamicly
    printf("spaces\n");
    printf(":%*s:",10,"");
    // WORKING !!!

    // specify the precision dynamically
    printf( "%.*s\n", 10, "******************************************");
    printf( "%.*s\n", 15, "******************************************");

    printf("%d",PAGEFREESPACE);
    cc temp;
    temp.a = (int*) calloc(4,sizeof(int));
    // temp.a = [1,2,3];
    free(temp.a);
    printf("\n");
    int a[5] = {1,2,3,4,5};
    int b[5] = {6,7,8,9,0};

    memcpy(&a[2],&a[0],4*sizeof(int));
    for(int i = 0; i<5 ; i++)
        printf("%d ",a[i]);
    
    int c = 0;
    printf("\n%d",a[c++]);
    printf("\n%d\n",c);

    printf("%d\n",11+(int)1/2);

    dd *memory = (dd*) calloc(1,sizeof(dd));
    memory->a = 123;

    printf("passed %p\n",memory);

    dd *usesame(dd *memory){
        memory->a = 321;
        printf("got %p\n",memory);
        return memory;
    }
    memory = usesame(memory);
    printf("returned %p\n",memory);
    return 0;
}
