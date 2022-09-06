#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>

void menu();
int saldo = 0;

void* somar() {
    saldo += 100;
}

void* subtrair() {
    saldo -= 100;
}

void* printarSaldo() {
    printf("Seu saldo atual eh: %d\n", saldo);
}

int main()
{
    int comandoParaSair = 4;
    int comandoDado;
    //Printando o menu
    menu();
    do {
        scanf("%d", &comandoDado);
        pthread_t tDeSoma, tDeSubtracao, tDePrint;
        if (comandoDado == 1) {
            pthread_create(&tDeSoma, NULL, &somar, NULL);
            printf("Acontecendo a soma na thread: %lu \n", pthread_self());
            pthread_join(tDeSoma, NULL);
        }
    
        else if (comandoDado == 2) {
            pthread_create(&tDeSubtracao, NULL, &subtrair, NULL);
            printf("Acontecendo a subtracao na thread: %lu \n", pthread_self());
            pthread_join(tDeSubtracao, NULL);
        }
    
        else if (comandoDado == 3) {
            pthread_create(&tDePrint, NULL, &printarSaldo, NULL);
            printf("Acontecendo o print na thread: %lu \n", pthread_self());
            pthread_join(tDePrint, NULL);
        }
        
        else if (comandoDado == 4) {
            pthread_exit(&tDeSoma);
            pthread_exit(&tDeSubtracao);
            pthread_exit(&tDePrint);
        }
    
    } while (comandoDado != 4);
    return 0;
}

void menu() {
    printf("\n");
    printf("Digite 1 para somar 100\n");
    printf("Digite 2 para subtrair 100\n");
    printf("Digite 3 para imprimir o saldo\n");
    printf("Digite 4 para sair\n");
    printf("Valor inicial de saldo: 0\n");
}
