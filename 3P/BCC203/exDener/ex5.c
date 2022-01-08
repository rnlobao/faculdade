//Ex 5
#include <stdio.h>

int main() {
    int n;
    do {
        printf("Digite um valor n: ");
        scanf("%d", &n);
        if (n <= 0) {
            printf("Digite um valor maior que 0!\n");
        }
    } while (n <= 0);
    
    int t1 = 0, t2 = 1;
    int proximoTermo = t1 + t2;
    printf("Serie de fibonacci: %d, %d, ", t1, t2);
    for (int i = 3; i <= n; i++) {
        if (i == n) {
            printf("%d.\n", proximoTermo);
        }
        else {
            printf("%d, ", proximoTermo);
            t1 = t2;
            t2 = proximoTermo;
            proximoTermo = t1 + t2;
        }
        
    }
    return 0;
}