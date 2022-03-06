#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define DULJINA 10
#define BRCLAN 10

void ShellSort_Hibbard(char **A, int N, int smjer){
	int i, j, korak, exp = 2;
	char *pom;
	while(exp<=N){
		exp*=2;
	}
	exp /= 2;
	if(smjer == 0)
		for (korak = exp-1; korak > 0; korak = exp-1, exp /=2){
			for (i = korak; i < N; ++i){
				pom = A[i];
				for (j = i; j >= korak&&strcmp(A[j - korak],pom)>0; j -= korak){
					A[j] = A[j - korak];
				}
				A[j] = pom;
			}
		}
	else
		for (korak = exp-1; korak > 0; korak = exp-1, exp /=2){
			for (i = korak; i < N; ++i){
				pom = A[i];
				for (j = i; j >= korak&&strcmp(A[j - korak],pom)>0; j -= korak){
					A[j] = A[j - korak];
				}
				A[j] = pom;
		}
	}
}

int main(void){
	char **A;
	int n, i, smjer;
	do{
		printf("Unesite broj clanova (<=%d) > ", BRCLAN);
		scanf("%d", &n);
	}while(n>BRCLAN);
	A = malloc(n*sizeof(*A));
	printf("\nUnesite clanove niza: ");
	getchar();
	for(i=0;i<n;i++){
		A[i] = malloc(DULJINA+1);
		gets(A[i]);
	}
	printf("\nOdaberite nacin sortiranja ( 0 - silazno, 1 - uzlazno): ");
	scanf("%d", &smjer);
	ShellSort_Hibbard(A, n, smjer);
	for(i=0;i<n;i++)
		printf("\nClan %d: %s", i+1, A[i]);
	free(A);
	return 0;
	
}