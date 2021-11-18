# ifndef arvoreb_h
# define arvoreb_h
#include "contimpri.h"

typedef struct TipoPagina *TipoApontador;

typedef struct TipoPagina {
    short n;    //representa a quantidade de posiçpes preenchidas no meu vetor r
    TipoRegistro  r[MM];
    TipoApontador p[MM + 1];
    
} TipoPagina ;

void inicializaArvoreB (TipoApontador arvore);

void criaArvoreB(FILE *arqReg, TipoApontador *ap, int quantidade, int *contComp, int *contTrans);

int pesquisaArvoreB (TipoRegistro *x, TipoApontador ap, int *contComp, int *contTrans);

void insereArvoreB(TipoRegistro Reg, TipoApontador *ap, int *contComp, int *contTrans);

void InsRecu (TipoRegistro Reg, TipoApontador ap, short *cresceu, TipoRegistro *regRetorno, TipoApontador *apRetorno, int *contComp, int *contTrans);

void InsereNaPagina (TipoApontador ap, TipoRegistro Reg, TipoApontador apDir, int *contComp, int *contTrans);

# endif
