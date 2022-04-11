#include "corretor.h"
#include<stdio.h>

int main()
{
    TADalunos *A;
    int ordem;
    int s;
    int p;

    lerOrdem(&ordem);
    A = alocaAlunos(A, ordem);
    lerAlunos(A, ordem);
    s = contandocorretos(A, ordem);
    p = tempototal(A, ordem);
    printsaida(s, p);
    A = desalocaAlunos(A);
    
    return 0;//nao remova
}