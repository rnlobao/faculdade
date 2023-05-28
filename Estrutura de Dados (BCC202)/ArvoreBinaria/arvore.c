#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
//Robson Novato 20.1.4018
void TArvore_Inicia (TNo **pRaiz) {
    *pRaiz = NULL;
}

void TArvore_Insere_Raiz (TNo **pRaiz , TItem x) {
    if (*pRaiz == NULL) {
        *pRaiz = TNo_Cria(x);
        return;
    }
     TArvore_Insere(*pRaiz, x);
}

int TArvore_Insere (TNo *pRaiz , TItem x) {
    if (pRaiz == NULL) {
        return -1;
    } 

    if (x.num < pRaiz->item.num) {
        if (pRaiz->esq == NULL) {
            pRaiz->esq = TNo_Cria(x);
            return 1;
        }
        return TArvore_Insere(pRaiz->esq, x);
    }
    if (x.num > pRaiz->item.num) {
        if (pRaiz->dir == NULL) {
            pRaiz->dir = TNo_Cria(x);
            return 1;
        }
        return TArvore_Insere(pRaiz->dir, x);
    }
    return 0;           
}

TNo *TNo_Cria (TItem x) {
    TNo *aux = (TNo*) malloc (sizeof(TNo));
    aux->item = x;
    aux->esq = NULL;
    aux->dir = NULL;
    return aux;
}

void Prefixa(TNo *p) {
    if (p == NULL) {
        return;
    } 
    printf("%ld ", p->item.num);
    Prefixa(p->esq);
    Prefixa(p->dir);
}

void Infixa(TNo *p) {
   if (p == NULL) {
       return;
   }
    Infixa(p->esq);
    printf("%ld ", p->item.num);
    Infixa(p->dir);
}

void Posfixa(TNo *p) {
    if (p == NULL) {
        return;
    }
    Posfixa(p->esq);
    Posfixa(p->dir);
    printf("%ld ", p->item.num);
}
