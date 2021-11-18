#ifndef asi_h
#define asi_h

#include "contimpri.h"

#define ITENSPAGINA 8
#define MAXTABELA 125000

typedef struct{
    int posicao;
    int chave;
} tipoIndice ;

int pesquisaSequencial(tipoIndice tab[] , int quantidade, TipoRegistro* item , FILE* arqReg , int situ,int *comp ,int *trans);
TipoRegistro pesquisaSequencialIndexada(TipoRegistro *r,int tam, FILE* arq , int situ,int *comp ,int *trans , int *flag );
#endif