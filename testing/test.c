#include <stdlib.h>
#include <stdio.h>

#define FIELD 8

typedef struct{
    int a;
    char c[16];
} dd;

int main()
{
    dd s[] ={
        {1,"str"},
        {2,"hello"}
    };
    printf("%d\n",s[0].a);

    // printf( ":%-*d:\n", FIELD, 1234567);
    printf( ":%-*d: :%-*d:\n", FIELD, 1234567, FIELD, 4321);
    printf( ":%*s:\n", 15, "*");

    // specify the precision dynamically
    printf( "%.*s\n", 10, "******************************************");
    printf( "%.*s\n", 15, "******************************************");
    return 0;
}
