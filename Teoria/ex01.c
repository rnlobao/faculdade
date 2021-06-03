#include <stdio.h>
#include <stdlib.h>

float* reverso(int n, float* v);

int main() {
    int tamanhodovetor = 6;
    float *valoresdovetor;
    for (int i = 0; i < tamanhodovetor; i++) {
        valoresdovetor[i] = i;
    }
    for (int i = 0; i < tamanhodovetor; i++) {
        printf("%f", valoresdovetor[i]);
    }
    float vetoraocontrario = *reverso(tamanhodovetor, valoresdovetor);
    printf("E DEPOISSS: \n");
    for (int i = 0; i < tamanhodovetor; i++) {
        printf("%f", valoresdovetor[i]);
    }
    return 0;
}


float* reverso(int n, float* v) {
    float *contrario = (float*) malloc(n*sizeof(float));
    if (contrario == NULL) {
        printf("Sem memoria");
        return NULL;
    }
    int k = 0;
    for (int i = n; i >= 0; i--) {
        contrario[k] = v[i];
        k++; 
    }
    return contrario;
}