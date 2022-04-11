//Ex 9
#include <stdio.h>

int main() {
    int numeroPositivo;
    do {
        printf("Digite um numero inteiro positivo: ");
        scanf("%d", &numeroPositivo);
        if (numeroPositivo < 0) {
            printf("Invalido!\n");
        }
    } while(numeroPositivo < 0);

    printf("Divisores: ");
    for (int i = 1; i <= numeroPositivo; i++) {
        if (i == numeroPositivo) {
            printf("%d.\n", i);
        }
        if (numeroPositivo % i == 0) {
            printf("%d, ", i);
        }
    }
    return 0;
}