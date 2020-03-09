#include <stdio.h>
#include <stdlib.h>
#define ROWS 3
#define COLUMNS 7

void fjaFix1(int fixMat[ROWS][COLUMNS]);
void fjaFix2(int *fixMat);
void fjaDyn(int **dynMat);

/*Usporedba deklariranja, pridodjeljivanja vrijednosti, koristenja, i slanja u funkcije
staticki deklarirane "fiksne" matrice i dinamicki alocirane matrice, bez ikakvih pomocnih pointera.*/
int main()
{
    int i, j, k=0;

    int fixMat[ROWS][COLUMNS]; /*deklaracija fiksnih matrica je kraca*/

    int** dynMat = (int**) malloc(ROWS*sizeof(int*));
    for(i=0;i<ROWS;i++){
        dynMat[i] = (int*) malloc(COLUMNS*sizeof(int));
    }/*deklaracija i zauzimanje memorije dinamickih matrica je kompliciranija, ali kasnije ce biti lakse*/

    for(i=0;i<ROWS;i++){ /*dodjeljivanje vrijednosti eementima fiksne matrice*/
        for(j=0;j<COLUMNS;j++){

            fixMat[i][j]=k++;
            /*ili*/
            // *(&fixMat[0][0]+i*COLUMNS+j)=k++;
            /*ili*/
            // *(*fixMat+i*COLUMNS+j)=k++;

            /*ajmo rec da nije pre strasno*/
        }
    }
    k=0;
    for(i=0;i<ROWS;i++){ /*dodjeljivanje vrijednosti elementima dinamicke matrice*/
        for(j=0;j<COLUMNS;j++){

            dynMat[i][j]=k++;
            /*ili*/
            // *(*(dynMat+i)+j)=k++;

            /*sto se mene tice, bolje!*/
        }
    }
    printf("u mainu fiksna:\n");
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLUMNS;j++){

            printf("%d\t", fixMat[i][j]);
            /*ili*/
            //printf("%d\t", *((*fixMat)+i*COLUMNS+j));
            /*ili*/
            //printf("%d\t", *(&fixMat[0][0]+i*COLUMNS+j));
        }
        printf("\n");
    }
    printf("u mainu dinamicka:\n");
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLUMNS;j++){

            printf("%d\t", dynMat[i][j]);
            /*ili*/
            //printf("%d\t", *(*(dynMat+i)+j));
            /*ili*/
            //printf("%d\t", *(dynMat[i]+j));
        }
        printf("\n");
    }
    /*dva RAZLICITA nacina slanja fiksne matrice u funkcije*/
    fjaFix1(fixMat);
    fjaFix2(&fixMat[0][0]); /*ili fjaFix2(fixMat[0]);*/

    /*slanje dinamicke matrice u funkciju*/
    fjaDyn(dynMat);
    return 0;
}
void fjaFix1(int fixMat[ROWS][COLUMNS]) /*ili (int (*fixMat)[COLUMNS]) ili (int fixMat[][COLUMNS])*/
{
    int i, j;
    printf("u fjaFix1:\n");
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLUMNS;j++){
            printf("%d\t", fixMat[i][j]);
            /*ili*/
            //printf("%d\t", *((*fixMat)+i*COLUMNS+j));
            /*ili*/
            //printf("%d\t", *(&fixMat[0][0]+i*COLUMNS+j));

            /*je li ovo kopija matrice ili prava matrica?*/
            if(fixMat[i][j]%3==0) fixMat[i][j]=555;
            /*u fjaFix2 ce se vidjeti da ovo nije bila kopija, nego stvarno prava matrica*/
        }
        printf("\n");
    }
}
void fjaFix2(int *fixMat)
{
    int i, j;
    printf("u fjaFix2:\n");
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLUMNS;j++){

            printf("%d\t", *(fixMat+i*COLUMNS+j));
            /*ovo NE radi: printf("%d\t", fixMat[i][j]); compiler valjda pojma nema sto je to jer funkcija dobije obican pointer*/
        }
        printf("\n");
    }
}
void fjaDyn(int **dynMat)
{
    int i,j;
    printf("u fjaDyn:\n");
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLUMNS;j++){

            printf("%d\t", dynMat[i][j]);
            /*ili*/
            //printf("%d\t", *(dynMat[i]+j));
            /*ili*/
            //printf("%d\t", *(*(dynMat+i)+j)); /*ovo cak i preporucam*/

        }
        printf("\n");
    }
    /*po meni je dinamicka matrica i ovakva funkcija najbolja, lagani dvostruki pointer, i lagano pristupanje elementima*/
}

/*AMDG*/
