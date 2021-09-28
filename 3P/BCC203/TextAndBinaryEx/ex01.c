#include <stdio.h>
#include <stdlib.h>
#define N 50

typedef struct {
    int matricula;
    char nomes[29];
    float nota1, nota2, nota3;
    int faltas;
} Alunos;

int main() {
    FILE *arq;
    int result;
    Alunos alunos[50];

    arq = fopen("alunos.txt", "r");

    if (arq == NULL){
        printf("Problemas no arquivo\n");
        return;
    }

    for (int i = 0; i < N; i++) {
        result = fscanf(arq, "%d %s %f %f %f %d", alunos[i].matricula, alunos[i].nomes, alunos[i].nota1, alunos[i].nota2, alunos[i].nota3, alunos[i].faltas);
    }
    printf("%d", alunos[0].matricula);

}
