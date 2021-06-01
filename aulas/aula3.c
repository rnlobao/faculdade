//Alocação dinamica: 
//Quando voce aloca, voce tem que desalocar. 
//para alocar: malloc()
//desalocar: free()
//rertorna ponteiro




#include <stdio.h>
#include <stdlib.h>

int main() {
    int *minhaidade;
    minhaidade = (int*) malloc(sizeof(int)); //alocando espaço pra um inteiro no programa
    
    int *variasidades;
    variasidades = (int*) malloc(3*sizeof(int)); //alocando para um vetor com 3 espaços

    if (variasidades == NULL) {
        printf("Memoria insuficiente");
        return 1;
    } //boa pratica para ver se tem memória no espaço

    free(minhaidade); //desalocando a memória
    minhaidade = NULL; //boa prática
    free(variasidades);
    variasidades = NULL;

    //realocando um espaço que talvez nao precisou de td ou precisa de mais:
    variasidades = (int*) realloc(variasidades, 4*sizeof(int));

    //alocando agora uma matriz transformada em vetor:
    int *idadesepeso;
    idadesepeso = (int*) malloc(2*2*sizeof(int)); //matriz 2 por 2 obviamente

    //alocando uma matriz propriamente dita, 3x2:
    int *num1num2;
    num1num2 = (int**) malloc(3*sizeof(int*));
    for (int i = 0; i < 3; i++) {
        num1num2[i] = (int*) malloc(2*sizeof(int));
    }
    //liberando a memoria com matriz.
    for (int i = 0; i < 3; i++) {
        free(num1num2[i]);
    }
    free(num1num2);

    
    return 0;
}