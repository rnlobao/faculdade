#include <stdio.h>

void bubblesort(int *v, int n);
void selectionsort(int *v, int n);
void insertionsort(int *v, int n);

int main() {
    int sequencia[7] = {3, 4, 9, 2, 5, 1, 8};
    int k = 7;
    bubblesort(sequencia, k);
    printf("\n");
    selectionsort(sequencia, k);
    printf("\n");
    insertionsort(sequencia, k);
    return 0;
}

void bubblesort(int *v, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n - i; j++) {
            if (v[j] < v[j-1]) {
                int aux = v[j];
                v[j] = v[j-1];
                v[j-1] = aux;
            }
        }
    }
    for (int i = 0; i < 7; i++) {
        printf("%d ", v[i]);
    }
}

void selectionsort(int *v, int n) {
    int min;
    for (int i = 0; i < n; i++) {
        min = i;
        for (int j = i+1; j < n; j++) {
            if (v[j] < v[min]) {
                min = j;
            }
        }
        int aux = v[i];
        v[i] = v[min];
        v[min] = aux;
    }
    for (int i = 0; i < 7; i++) {
        printf("%d ", v[i]);
    }
}

void insertionsort(int *v, int n) {
    int aux;
    int j;
    for (int i = 1; i < n; i++) {
        aux = v[i];
        j = i - 1;
        while (j >= 0 && aux < v[j]) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = aux;
    }
    for (int i = 0; i < 7; i++) {
        printf("%d ", v[i]);
    }
}