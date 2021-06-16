#include "corretor.h"
#include<stdio.h>

int main()
{
    TADalunos *A;
    int ordem;

    lerOrdem(&ordem);
    A = alocaAlunos(A, ordem);
    lerAlunos(A, ordem);

    A = desalocaAlunos(A);
    

    
    return 0;//nao remova
}