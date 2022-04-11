#include <stdio.h>

int main() {
    int v[7], aux, min;
    for (int i = 0; i < 7; i++) {
        scanf("%d", &v[i]);
        printf("%d ", v[i]);
    }
    printf("\n"); 
    for (int i = 0; i < 7; i++) {
        min = i;
        for (int j = i+1; j < 7; j++) {
            if(v[j] < v[min]) 
                min = j;
        }
        aux = v[i];
        v[i] = v[min];
        v[min] = aux;
        for (int k = 0; k < 7; k++) 
            printf("%d ", v[k]);
         printf("\n");  
    }
       
    return 0;

}