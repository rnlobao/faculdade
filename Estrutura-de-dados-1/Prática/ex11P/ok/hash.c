#include "hash.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//Manter como especificado
void TLista_Inicia(TLista *pLista){
	pLista->pPrimeiro = (TCelula*) malloc (sizeof (TCelula));
	pLista->pUltimo = pLista->pPrimeiro;
	pLista->pPrimeiro->pProx = NULL;
}

//Manter como especificado
int TLista_EhVazia(TLista *pLista){
	return (pLista->pPrimeiro == pLista->pUltimo);
}

//Manter como especificado
int TLista_Insere(TLista *pLista , TItem x){
	pLista->pUltimo->pProx = (TCelula*)malloc(sizeof(TCelula));
	pLista->pUltimo = pLista->pUltimo->pProx;
	pLista->pUltimo->item = x;
	pLista->pUltimo->pProx = NULL;

	return 1;
}

//Manter como especificado
void THash_Inicia(THash *hash, int nro_listas){
	hash->v = (TLista*) malloc(sizeof(TLista) * nro_listas);
	hash->n = 0;
	hash->nro_listas = nro_listas;

	for (int i = 0; i < nro_listas; i++){
		TLista_Inicia(&hash->v[i]);
	}
}

//Manter como especificado
int THash_H(THash *hash, TChave chave){
	//printf("soma = %d\nnro = %d\nmod = %d\n", soma, hash->nro_listas, soma % hash->nro_listas);
	return (chave % hash->nro_listas) ;
}

//Manter como especificado
TCelula *THash_PesquisaCelula(THash *hash, TChave chave){
	int i = THash_H(hash, chave);
	//printf("posicao %d\n", i);
	TCelula * aux;
	
	if (TLista_EhVazia(&hash->v[i])){
		//printf("linha %d vazia\n", i);
		return NULL; // pesquisa sem sucesso
	}
	aux = hash->v[i].pPrimeiro;

	while (aux->pProx->pProx != NULL && chave != aux->pProx->item.chave){
		aux = aux -> pProx ;
	}
	if  ((chave == aux->pProx->item.chave)){ 
		//printf("linha 61 com a chave %d",chave);
		return aux ;
	}
	else{
		//printf("linha %d nao ta vazia, mas a chave e unica\n", i);
		return NULL ; // pesquisa sem sucesso
	}
}

//Manter como especificado
int THash_Insere (THash *hash, TItem x){
	if (THash_PesquisaCelula(hash, x.chave) == NULL) {
		//printf("inserindo %d na linha %d\n", x.chave, THash_H(hash, x.chave));
		TLista_Insere(&hash->v[THash_H(hash, x.chave)], x);
		hash->n++;
		return 1;
	}else{
		return 0;	
	}
}

void Leitor(THash *hash, int *n, int *c){
	//printf("Iniciando LEITOR\n");
	TItem aux;

	for (int i = 0; i<*c; i++){
		scanf("%d", &aux.chave);
		//printf("LIDO CHAVE no%d == %d\n", i+1, aux.chave);
		THash_Insere(hash, aux);
	}
}

void Imprime(THash *hash, int n){
	

}

void TLista_Imprime(TLista *pLista) {
	if (TLista_EhVazia(pLista)){
		printf("\\");
	}else{
		TCelula *atual;
		atual = pLista->pPrimeiro->pProx;

	    while(atual != pLista->pUltimo) {
	        printf("%d -> ", atual->item.chave);
	        atual = atual->pProx;
	    }

	    printf("%d -> \\", atual->item.chave);
	}
}