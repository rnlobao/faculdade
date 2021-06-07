#include <stdio.h>
#include <stdlib.h>

float* reverso(int n, float* v);

int main() {
    int tamanhodovetor;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanhodovetor);
    float *valoresdovetor;
    valoresdovetor = (float*) malloc(tamanhodovetor * sizeof(float));
    if (valoresdovetor == NULL) {
        printf("Sem memoria");
        return NULL;
    }
    float *vetoraocontrario;
    for (int i = 0; i < tamanhodovetor; i++) {
        printf("Digite um valor: ");
        scanf("%f", &valoresdovetor[i]);
    }
    vetoraocontrario = reverso(tamanhodovetor, valoresdovetor);
    for (int j = 0; j < tamanhodovetor; j++) {
        printf("%.1f\n", vetoraocontrario[j]);
    }
    free(valoresdovetor);
    free(vetoraocontrario);
    return 0;
}

float* reverso(int n, float* v) {
    float *contrario ;
    contrario = (float*) malloc(n*sizeof(float));
    if (contrario == NULL) {
        printf("Sem memoria");
        return NULL;
    }
    for (int k = 0; k < n; k++) {
        contrario[k] = v[(n-1)-k];
    }
    return contrario;
}