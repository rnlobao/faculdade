#include "corretor.h"
#include<stdio.h>

typedef struct {
    char letra;
    int tempo;
    char situacao[9];
} Alunos;


int main()
{
    int ordem;
    lerOrdem(&ordem);
    lerStruct();

    
    return 0;//nao remova
}