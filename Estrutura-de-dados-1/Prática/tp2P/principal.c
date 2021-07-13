#include "ordenacao.h"
#include <stdio.h>

int main() {
    TADpaises *p;
    int tam;

    lerTam(&tam);
    p = alocaPaises(p, tam);
    lerPaises(p, tam);
    p = pontuar(p, tam);
    p = confererepetido(p, tam);
    p = organizascore(p, tam);
    



    printatad(p, tam);
    p = desalocaPaises(p);
    return 0;
}