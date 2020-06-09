#include <stdlib.h>
#include <stdio.h>

#define BUFFERSIZE 256 
#define ORDER 3
#define INTFIELD 10
#define STRFIELD 16
#define PAGESIZE 3*INTFIELD+3*ORDER*INTFIELD-2
#define PAGEFREESPACE BUFFERSIZE-PAGESIZE
#define STUDENTSIZE 2*INTFIELD+3*STRFIELD

typedef struct STUDENT STUDENT;
struct STUDENT{
	int numUSP;
	char name[STRFIELD];
	char surname[STRFIELD];
	char course[STRFIELD];
	float grade;
} ;
int main(void){
    STUDENT st;
    FILE*dataFile=fopen("data.dat","r");
	// fseek(dataFile,0*STUDENTSIZE,SEEK_SET);
	// fscanf(dataFile,"%d%s%s%s%f",&st.numUSP,st.name,st.surname,st.course,&st.grade);
	// printf("\n%d|%s|%s|%s|%f\n",st.numUSP,st.name,st.surname,st.course,st.grade);

	printf("begginign %d\n",ftell(dataFile));
	fseek(dataFile,0,SEEK_END);
	printf("end %d\n",ftell(dataFile));
	// fseek(dataFile,0,SEEK_SET);
	for(int i = 0; i<6 ; i++){
		fseek(dataFile,i*66,SEEK_SET);
		printf("ftell position %d\n",ftell(dataFile));
		// fscanf(dataFile,"%d%s%s%s%f",&st.numUSP,st.name,st.surname,st.course,&st.grade);
		fscanf(dataFile,"%d",&st.numUSP);
		// fscanf(dataFile,"%s",st.name);
		// fscanf(dataFile,"%s",st.surname);
		// fscanf(dataFile,"%s",st.course);
		// fscanf(dataFile,"%f",&st.grade);

		// printf("\n%d|%s|%s|%s|%f\n",st.numUSP,st.name,st.surname,st.course,st.grade);
		printf("numsup %d\n",st.numUSP);
	}
	printf("student size %d\n",STUDENTSIZE);

    return 0;
}