//Ex 10
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
    int somaDosDivisores = 0;
    for (int i = 1; i <= numeroPositivo; i++) {
        if (numeroPositivo % i == 0 && i != numeroPositivo) {
            somaDosDivisores += i;
            printf("%d + ", i);
        }
    }
    printf("= %d\n", somaDosDivisores);
    return 0;
}