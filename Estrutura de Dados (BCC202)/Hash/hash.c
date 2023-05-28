#include "hash.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void TLista_Inicia(TLista *pLista){
	pLista->pPrimeiro = (TCelula*) malloc (sizeof (TCelula));
	pLista->pUltimo = pLista->pPrimeiro;
	pLista->pPrimeiro->pProx = NULL;
}

int TLista_EhVazia(TLista *pLista){
	return (pLista->pPrimeiro == pLista->pUltimo);
}

int TLista_Insere(TLista *pLista , TItem x){
	pLista->pUltimo->pProx = (TCelula*)malloc(sizeof(TCelula));
	pLista->pUltimo = pLista->pUltimo->pProx;
	pLista->pUltimo->item = x;
	pLista->pUltimo->pProx = NULL;
	return 1;
}

void THash_Inicia(THash *hash, int nro_listas){
	hash->v = (TLista*) malloc(sizeof(TLista) * nro_listas);
	hash->n = 0;
	hash->nro_listas = nro_listas;

	for (int i = 0; i < nro_listas; i++){
		TLista_Inicia(&hash->v[i]);
	}
}

int THash_H(THash *hash, TChave chave){
	return (chave % hash->nro_listas) ;
}

TCelula *THash_PesquisaCelula(THash *hash, TChave chave){
	int i = THash_H(hash, chave);
	TCelula * aux;
	
	if (TLista_EhVazia(&hash->v[i])){
		return NULL; 
	}
	aux = hash->v[i].pPrimeiro;
	while (aux->pProx->pProx != NULL && chave != aux->pProx->item.chave){
		aux = aux -> pProx ;
	}
	if  ((chave == aux->pProx->item.chave)){ 
		return aux ;
	}
	else{
		return NULL; 
	}
}

int THash_Insere (THash *hash, TItem x){
	if (THash_PesquisaCelula(hash, x.chave) == NULL) {
		TLista_Insere(&hash->v[THash_H(hash, x.chave)], x);
		hash->n++;
		return 1;
	}
	else {
		return 0;	
	}
}

void Disponibiliza(THash *hash, int *n, int *c){
	TItem aux;
	for (int i = 0; i<*c; i++){
		scanf("%d", &aux.chave);
		THash_Insere(hash, aux);
	}
}

void Imprime(TLista *pLista) {
	if (TLista_EhVazia(pLista)){
		printf("\\");
		printf("\n");
	}
	else {
		TCelula *atual;
		atual = pLista->pPrimeiro->pProx;

	    while(atual != pLista->pUltimo) {
	        printf("%d -> ", atual->item.chave);
	        atual = atual->pProx;
	    }

	    printf("%d -> \\", atual->item.chave);
		printf("\n");
	}
}
