#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>

#define ITERACOES 100

typedef struct 
{
    int saldo;
} tipoThread;

void *soma(void *t)
{
    tipoThread *aux = (tipoThread*)t;
    aux->saldo += 1;
    pthread_exit(0);
}

void *subtrai(void *t)
{
    tipoThread *aux = (tipoThread*)t;
    aux->saldo -= 1;
    pthread_exit(0);
}

void *imprimir(void *t)
{
    tipoThread *aux = (tipoThread*)t;
    printf( "[T:%d] Saldo = %d\n", (int)pthread_self(), aux->saldo);
    pthread_exit(0);
}

int main()
{
    tipoThread *t = (tipoThread *)malloc(sizeof(tipoThread));
    t->saldo = 100;
    int numThreads;

    do 
    {
        printf("Numero de threads: ");
        scanf("%d", &numThreads);

    } while (numThreads % 2 != 0);

    pthread_t tSum, tSub, tImp;
    
    for (int i = 0; i < (numThreads * ITERACOES); i++)
    {
        pthread_create(&tSum, NULL, soma, (void *)t);
        pthread_create(&tSub, NULL, subtrai, (void *)t);
        pthread_create(&tImp, NULL, imprimir, (void *)t);
    }

    return 0;
}