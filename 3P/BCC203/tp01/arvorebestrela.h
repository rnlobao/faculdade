#ifndef arvorebestrela_h
#define arvorebestrela_h

#include "contimpri.h"

typedef struct TipoPaginaB* TipoApontadorB;

typedef enum {Interna, Externa} TipoIntExt;

typedef struct TipoPaginaB{
    TipoIntExt Pt;
    union {
        struct { //Pagina interna
            int ni;
            TChave ri[MM];
            TipoApontadorB pi[MM + 1];
        } U0;
        struct { //Pagina externa (folha)
            int ne;
            TipoRegistro re[2 * MM];
        } U1;
    } UU;
}TipoPaginaB;

void inicializaArvoreBEstrela(TipoApontadorB arvore);

int pesquisaArvoreBEstrela(TipoRegistro *x, TipoApontadorB *ap, int *contComp, int *contTrans);

void criaArvoreBEstrela(FILE *arqReg, TipoApontadorB *ap, int quantidade, int *contComp, int *contTrans);

void insereArvoreBEstrela(TipoRegistro Reg, TipoApontadorB *ap, int *contComp, int *contTrans);

void insrecuBEstrela(TipoRegistro Reg, TipoApontadorB ap, short *cresceu, TipoRegistro *RegRetorno, TipoApontadorB *ApRetorno, int *contComp, int *contTrans);

void insereNapaginaEstrela(TipoApontadorB ap, TipoRegistro Reg, TipoApontadorB apDir, int *contComp, int *contTrans);

#endif