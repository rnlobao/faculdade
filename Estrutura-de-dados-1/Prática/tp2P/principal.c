#include "ordenacao.h"
#include <stdio.h>

/*
Em ordem, eu crio o tipo abstrato de dado para guardar os dados e o tam para o tamanho, leio através da função
O pontuar vai dar um score para cada medalha, como se fosse um peso. Dai entra em um loop que organiza o score,
ou seja, coloca os que tem score maior na frente dos que estão com menor, trocando com um SelectionSort.
O confere repetido vai passar por cada item e ver se em sua volta tem algum item que tem o score igual, se sim
ele atribui um valor a uma variável, esse valor é o valor em ASCII da sua primeira letra, quanto menor melhor.
O que tiver o menor valor ganha 1 ponto no score e sobe, fazendo assim criar uma ordem alfabética. Depois é
printada a TAD e desalocada.
--Robson Novato Lobão // 20.1.4018--
*/

int main() {
    TADpaises *p;
    int tam;

    lerTam(&tam);
    p = alocaPaises(p, tam);
    lerPaises(p, tam);
    p = pontuar(p, tam);
    for (int i = 0; i < tam; i++) {
        p = organizascore(p, tam);
        p = confererepetido(p, tam);
        p = organizascore(p, tam);
    }
    printatad(p, tam);
    p = desalocaPaises(p);
    return 0;
}