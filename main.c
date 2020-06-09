#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <btree.c>

int main(void){

    STUDENT sts[] = {
{35, "Alice","_Alice","AA",0.14},
{65, "Miguel","_Miguel","AA",8.09},
{23, "Sophia","_Sophia","AA",9.95},
{109, "Arthur","_Arthur","CC",8.66},
{138, "Helena","_Helena","BB",7.53},
{99, "Bernardo","_Bernardo","BB",1.99},
{129, "Valentina","_Valentina","BB",6.83},
{159, "Heitor","_Heitor","BB",3.38},
{74, "Laura","_Laura","AA",8.38},
{31, "Davi","_Davi","CC",2.67},
{36, "Isabella","_Isabella","BB",4.17},
{43, "Lorenzo","_Lorenzo","CC",9.59},
{170, "Manuela","_Manuela","AA",0.33},
{27, "Théo","_Théo","BB",7.87},
{66, "Júlia","_Júlia","BB",8.79},
{120, "Pedro","_Pedro","BB",9.28},
{122, "Heloísa","_Heloísa","AA",3.58},
{60, "Gabriel","_Gabriel","BB",8.69},
{115, "Luiza","_Luiza","CC",3.25},
{139, "Enzo","_Enzo","CC",4.75},
{86, "Maria Luiza","_Maria Luiza","AA",2.56},
{171, "Matheus","_Matheus","BB",5.30},
{145, "Lorena","_Lorena","CC",1.87},
{143, "Lucas","_Lucas","AA",2.88},
{44, "Lívia","_Lívia","AA",0.49},
{96, "Benjamin","_Benjamin","BB",6.45},
{53, "Giovanna","_Giovanna","AA",7.30},
{133, "Nicolas","_Nicolas","CC",7.49},
{68, "Maria Eduarda","_Maria Eduarda","AA",0.37},
{154, "Guilherme","_Guilherme","CC",1.87},
{167, "Beatriz","_Beatriz","AA",6.12},
{156, "Rafael","_Rafael","BB",9.79},
{103, "Maria Clara","_Maria Clara","CC",7.68},
{84, "Joaquim","_Joaquim","BB",1.14},
{98, "Cecília","_Cecília","AA",4.68},
{48, "Samuel","_Samuel","BB",6.13},
{158, "Eloá","_Eloá","AA",1.91},
{92, "Enzo Gabriel","_Enzo Gabriel","AA",6.15},
{152, "Lara","_Lara","AA",4.55},
{117, "João Miguel","_João Miguel","BB",0.44},
{148, "Maria Júlia","_Maria Júlia","CC",3.64},
{93, "Henrique","_Henrique","BB",4.98},
{25, "Isadora","_Isadora","CC",6.55},
{140, "Gustavo","_Gustavo","AA",2.12},
{67, "Mariana","_Mariana","CC",1.37},
{121, "Murilo","_Murilo","CC",9.34},
{172, "Emanuelly","_Emanuelly","CC",5.77},
{169, "Pedro Henrique","_Pedro Henrique","CC",6.85},
{56, "Ana Júlia","_Ana Júlia","AA",9.69},
{141, "Pietro","_Pietro","BB",2.10},
{63, "Ana Luiza","_Ana Luiza","BB",5.43},
{146, "Lucca","_Lucca","AA",2.48},
{126, "Ana Clara","_Ana Clara","BB",3.91},
{26, "Felipe","_Felipe","AA",9.93},
{102, "Melissa","_Melissa","BB",4.28},
{173, "João Pedro","_João Pedro","AA",2.44},
{24, "Yasmin","_Yasmin","BB",5.40},
{49, "Isaac","_Isaac","CC",6.43},
{59, "Maria Alice","_Maria Alice","AA",0.03},
{37, "Benício","_Benício","CC",4.10},
{119, "Isabelly","_Isabelly","AA",0.55},
{111, "Daniel","_Daniel","BB",6.08},
{105, "Lavínia","_Lavínia","BB",3.31},
{163, "Anthony","_Anthony","CC",4.00},
{107, "Esther","_Esther","AA",5.55},
{166, "Leonardo","_Leonardo","CC",3.45},
{165, "Sarah","_Sarah","BB",0.19},
{89, "Davi Lucca","_Davi Lucca","AA",8.41},
{124, "Elisa","_Elisa","CC",1.62},
{54, "Bryan","_Bryan","BB",2.32},
{75, "Antonella","_Antonella","BB",6.66},
{61, "Eduardo","_Eduardo","CC",2.78},
{85, "Rafaela","_Rafaela","CC",4.69},
{155, "João Lucas","_João Lucas","AA",6.77},
{76, "Maria Cecília","_Maria Cecília","CC",2.84},
{95, "Victor","_Victor","AA",3.06},
{81, "Liz","_Liz","BB",3.72},
{30, "João","_João","BB",5.37},
{70, "Marina","_Marina","CC",8.38},
{87, "Cauã","_Cauã","BB",6.04},
{101, "Nicole","_Nicole","AA",8.81},
{147, "Antônio","_Antônio","BB",9.67},
{34, "Maitê","_Maitê","CC",1.64},
{164, "Vicente","_Vicente","AA",3.50},
{40, "Isis","_Isis","CC",1.24},
{20, "Caleb","_Caleb","AA",5.79},
{128, "Alícia","_Alícia","AA",7.47},
{110, "Gael","_Gael","AA",7.76},
{83, "Luna","_Luna","AA",6.33},
{46, "Bento","_Bento","CC",7.86},
{69, "Rebeca","_Rebeca","BB",4.47},
{79, "Caio","_Caio","CC",2.25},
{161, "Agatha","_Agatha","AA",1.72},
{153, "Emanuel","_Emanuel","BB",3.21},
{39, "Letícia","_Letícia","BB",9.90},
{73, "Vinícius","_Vinícius","CC",8.05},
{104, "Maria-","_Maria-","AA",9.21},
{136, "João Guilherme","_João Guilherme","CC",7.04},
{149, "Gabriela","_Gabriela","AA",6.79},
{21, "Davi Lucas","_Davi Lucas","BB",4.39},
{52, "Ana Laura","_Ana Laura","CC",8.03},
{55, "Noah","_Noah","CC",5.05},
{144, "Catarina","_Catarina","BB",7.66},
{88, "João Gabriel","_João Gabriel","CC",7.97},
{100, "Clara","_Clara","CC",3.61},
{82, "João Victor","_João Victor","CC",7.17},
{41, "Ana Beatriz","_Ana Beatriz","AA",0.52},
{57, "Luiz Miguel","_Luiz Miguel","BB",8.16},
{116, "Vitória","_Vitória","AA",9.91},
{135, "Francisco","_Francisco","BB",6.30},
{71, "Olívia","_Olívia","AA",4.99},
{94, "Kaique","_Kaique","CC",1.85},
{33, "Maria Fernanda","_Maria Fernanda","BB",8.61},
{113, "Otávio","_Otávio","AA",3.16},
{168, "Emilly","_Emilly","BB",6.81},
{72, "Augusto","_Augusto","BB",6.12},
{62, "Maria Valentina","_Maria Valentina","AA",0.34},
{162, "Levi","_Levi","BB",0.77},
{127, "Milena","_Milena","CC",0.84},
{28, "Yuri","_Yuri","CC",8.50},
{29, "Maria Helena","_Maria Helena","AA",6.33},
{160, "Enrico","_Enrico","CC",2.82},
{58, "Bianca","_Bianca","CC",5.85},
{22, "Thiago","_Thiago","CC",7.35},
{64, "Larissa","_Larissa","CC",7.92},
{112, "Ian","_Ian","CC",9.40},
{78, "Mirella","_Mirella","BB",4.33},
{50, "Victor Hugo","_Victor Hugo","AA",2.39},
{118, "Maria Flor","_Maria Flor","CC",3.73},
{131, "Thomas","_Thomas","AA",3.65},
{150, "Allana","_Allana","BB",0.45},
{108, "Henry","_Henry","BB",3.54},
{51, "Ana Sophia","_Ana Sophia","BB",7.55},
{130, "Luiz Felipe","_Luiz Felipe","CC",9.88},
{114, "Clarice","_Clarice","BB",2.88},
{90, "Ryan","_Ryan","BB",8.42},
{42, "Pietra","_Pietra","BB",4.72},
{47, "Arthur Miguel","_Arthur Miguel","AA",2.95},
{91, "Ana Lívia","_Ana Lívia","CC",3.73},
{151, "Raul","_Raul","CC",0.74},
{125, "Eduarda","_Eduarda","AA",8.16},
{137, "Pedro Miguel","_Pedro Miguel","AA",9.05},
{132, "Mariah","_Mariah","BB",6.89},
{134, "Luiz Henrique","_Luiz Henrique","AA",3.18},
{32, "Stella","_Stella","AA",6.60},
{142, "Luan","_Luan","CC",0.82},
{80, "Ana","_Ana","AA",3.44},
{38, "Erick","_Erick","AA",8.75},
{123, "Gabrielly","_Gabrielly","BB",4.14},
{77, "Martin","_Martin","AA",7.46},
{97, "Sophie","_Sophie","CC",1.77},
{45, "Bruno","_Bruno","BB",4.66},
{157, "Carolina","_Carolina","CC",6.06},
{106, "Rodrigo","_Rodrigo","CC",8.20},



    };

    FILE *indexHeader = bringFile("index_header.dat");
    FILE *indexFile = bringFile("index.dat");
    FILE *dataFile = bringFile("data.dat");
    BTREE *tree = loadIndexHeader(indexHeader);

    PAGE *pg = createEmptyIndexPage();
    int TAM = 40;
    for(int i = 0; i<TAM ; i++){
        insertStudent(dataFile,indexFile,tree,pg,&sts[i]);
        // getchar();
    }
    printf("_______search____\n");
    // int result =_search(indexFile,tree,11);
    // printf("root %d\n",tree->root);
    // printf("results %d\n",result);
    // getStudent(dataFile,result);
    int result;
    for(int i = 0; i<TAM ; i++){
        result = _search(indexFile,tree,sts[i].numUSP);
        // printf("\nlocation %d\n",result);
        // getchar();
        if(result>=0){
            getStudent(dataFile,result);
        }
    }

    storeIndexHeader(indexHeader,tree);
    fclose(indexHeader);
    fclose(indexFile);
    return 0;
}
//test dataFile
    // STUDENT *st = NULL;
    // for(int i = 0; i<22 ; i++){
    //     st = &sts[i];
    //     fseek(dataFile,0,SEEK_END);
    //     fprintf(dataFile,"%-*d%-*s%-*s%-*s%-8.2f",INTFIELD, st->numUSP,STRFIELD, st->name,STRFIELD, st->surname,STRFIELD, st->course, st->grade);

    // }
    // for(int i = 0; i<22 ; i++){
        // search = searchStudentByKey(indexFile,tree,pg,st[i].numUSP);
        // printf("returned key %d\n",search);
        // getStudent(dataFile,i);
    // }
    // printf("student size %d\n",STUDENTSIZE);