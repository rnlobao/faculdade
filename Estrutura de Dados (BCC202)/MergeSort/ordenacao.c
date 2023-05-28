#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *alocaVetor(int *vetor, int n){
	vetor = (int *) malloc (n * sizeof(int));
	return vetor;
}

int *desalocaVetor(int *vetor){
	free(vetor);
	return vetor;
}

void preenchervalores(int *vetor, int n){
	int aux;
 	for (int i = 0; i <n; i++){
 		scanf("%d", &aux);
 		if(aux != 0){
 			vetor[i] = aux;

 		}else{
 			break;
 		}
	}
}

void ordenacao(int *vetor, int n, int *movimentos){
	mergesort(vetor, 0, n-1, movimentos);
}

void mergesort(int *vetor, int l, int r, int *movimentos) {
	int m;
	if(l < r) {
		m = (l + r) / 2;
		mergesort(vetor, l, m, movimentos);
		mergesort(vetor, m+1, r, movimentos);
		merge(vetor, l, m, r, movimentos);
	}
}


void merge(int *vetor, int l, int m, int r, int *movimentos) {
	int size_l = m - l + 1;
	int size_r = r - m;


	int *vet_l = malloc (size_l * sizeof (int)) ;
	int *vet_r = malloc (size_r * sizeof (int)) ;


	for(int i=0; i<size_l; i++){
		vet_l[i] = vetor[i+l];
	}
	for(int j=0; j<size_r; j++){
		vet_r[j] = vetor[m + j + 1];
	}

	int i=0;
	int j=0;


	for (int k=l; k<=r; k++){
		if(i==size_l){
			vetor[k] = vet_r[j++];
		}else if(j ==  size_r){
			vetor[k] = vet_l[i++];
		}else if(vet_l[i] <= vet_r[j]){
			vetor[k] = vet_l[i++];
		}else{
			vetor[k] = vet_r[j++];
			*movimentos = *movimentos + size_l - i;
		}
	}

	free(vet_l);
	free(vet_r);
}