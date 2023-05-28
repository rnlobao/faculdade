#include "sortCollection.h"

#define IMPRIMIR_INDICES false

void printResult(int **m, int n, double *time);
void liberarMatriz (int **m, int n);
int **criarMatriz (int n, int m);

/* 
    ./sort n
*/

int main (int argc, char* argv[]) {
    srand(time(NULL));
    clock_t start, end;
    double time[3];
    int n = atoi(argv[1]);
    int **arr = criarMatriz(3, n);

    for (int i = 0 ; i < n ; i++) 
        arr[0][i] = arr[1][i] = arr[2][i] = rand () % n;

    start = clock();
    mergeSort(arr[0], 0, n);
    end = clock();
    time[0] = ((double) (end - start)) / CLOCKS_PER_SEC;

    start = clock();
    radixSort(arr[1], n);
    end = clock();
    time[1] = ((double) (end - start)) / CLOCKS_PER_SEC;

    start = clock();
    selectionSort(arr[2], n);
    end = clock();
    time[2] = ((double) (end - start)) / CLOCKS_PER_SEC;

    printResult(arr, n, time);
    liberarMatriz(arr, 3);
    return 0;
}

void printResult(int **arr, int n, double *time) {
    const char *metodos [3] = {"Merge Sort", "Radix Sort", "Selection Sort"};
    for (int i = 0; i < 3 ; i++) {
        if (IMPRIMIR_INDICES) {
            for(int j = 0; j < n; j++) {
                printf("[%d] : %d\n", j, arr[i][j]);
            }
        }
        printf("Método : %s - Tempo Total: %fs\n", metodos[i], time[i]);
    }
}

int **criarMatriz (int n, int m){
    int **matriz;
    matriz = (int**) malloc (n * sizeof(int*));
    
    for (int i = 0; i < n; i++)
        matriz[i] = (int*) malloc (m * sizeof(int));

    return matriz;
}

void liberarMatriz (int **m, int n){
    for (int i = 0; i < n; i++)
        free (m[i]);
    
    free (m);
}
