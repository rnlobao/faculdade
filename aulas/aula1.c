//O operador & significa: endereço de, aplicado a variáveis, resulta no endereço da posição da memória
//reservada para a variável

//O operador * significa: conteúdo de, aplicado a variáveis do tipo ponteiro, acessa o conteúdo do 
//endereço de memória armazenada pela variável do ponteiro

//Usando o *p voce pega o conteúdo de p, que no caso é o valor que voce atribuiu. 

#include <stdio.h>

int main() {
    int k;
    int *p;
    p = &k; //p recebe o endereço de a (o p está apontando pra a, sempre que mudar o p o a muda)
    *p = 8; //conteúdo de p alterado pra 8 e consequentemente alterando o conteúdo de a
    printf("O valor de a: %d", k);



    int a = 5, b = 7;
    troca(&a, &b); //tem que passar o endereço de a e b
    printf("\n%d %d", a, b);

    return 0;
}

//exercício que troca:
void troca (int *px, int *py) {
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
}
