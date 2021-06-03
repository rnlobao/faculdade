//Usando structs dinamicamente

#include <stdio.h>

typedef struct {
    int x;
    int y;
} Ponto;


int main() {
    int valor1, valor2;
    Ponto *pt = (Ponto*) malloc(sizeof(Ponto)); //o nome da variavel é pt
    if (pt == NULL) {
        printf("Memoria insuficiente!");
        exit(1);
    }

    pt->x = valor1;
    pt->y = valor2;

    free(pt);


    return 0;
}