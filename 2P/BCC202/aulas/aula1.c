//O operador & significa: endereço de, aplicado a variáveis, resulta no endereço da posição da memória
//reservada para a variável

//O operador * significa: conteúdo de, aplicado a variáveis do tipo ponteiro, acessa o conteúdo do 
//endereço de memória armazenada pela variável do ponteiro

//Usando o *p voce pega o conteúdo de p, que no caso é o valor que voce atribuiu. 
//ponteiro armazena o endereço de memória de uma variável


#include <stdio.h>

int main() {
    int a = 5, b = 7;
    troca(&a, &b); //tem que passar o endereço de a e b
    printf("\n%d %d", a, b);

    return 0;
}

void troca (int *px, int *py) {
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
}


