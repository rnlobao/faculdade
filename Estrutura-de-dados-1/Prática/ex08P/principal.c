#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
	int *vetor;
	int n, movimentos;

	while(scanf("%d", &n), n){
		vetor = alocaVetor(vetor, n);
		preenchervalores(vetor, n);
		movimentos = 0;
		ordenacao(vetor, n, &movimentos);
		if (movimentos % 2 == 0) {
			printf("Carlos\n");
		}
		else {
			printf("Marcelo\n");
		}
		desalocaVetor(vetor);
	}

	return 0;
}
