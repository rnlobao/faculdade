#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#define READ  0
#define WRITE 1

void menu();

int main()
{
    int comandoParaSair = 4;
    int comandoDado = 0;
    //Printando o menu
    menu();
    
    //Criando as pipes, comunicação entre as operacoes e o saldo
    int operacoes[2];
    int saberSaldo[2];
    
    if (pipe(operacoes) < 0 || pipe(saberSaldo) < 0){
        printf("Pipe nao foi criada.\n");
        exit(1);
    } 
    
    //Inicializando o valor do saldo na pipe, na posicao 1 que é para escrita, e ja visualizando se foi
    //Realizado com sucesso a operacao de inicializacao
    int comecandoComZero = 0;
    if (write(saberSaldo[WRITE], &comecandoComZero, sizeof(int)) == -1){
        printf("Erro ao escrever no pipe.\n");
        exit(1);
    }
    
    
    //Criacao do espaco para rodar diferentes processos, um para realizar o print do saldo, para soma e subtracao
    //Inspiracao: https://www.youtube.com/watch?v=94URLRsjqMQ
    int filho1 = fork(); 
    int filho2 = fork();
    
    if (filho1 < 0 || filho2 < 0){
        printf("Erro ao criar fork.\n");
        exit(1);
    }
    
    if (filho1 == 0) {
        if (filho2 == 0) {
            int comandoRecebidoDaPipePrincipal, saldo;
            do {
                read(operacoes[READ], &comandoRecebidoDaPipePrincipal, sizeof(int));
                if (comandoRecebidoDaPipePrincipal == 1) {
                    read(saberSaldo[READ], &saldo, sizeof(int));
                    printf("Pipe de soma: %d\n", getpid());
                    saldo += 100;
                    write(saberSaldo[WRITE], &saldo, sizeof(int));
                }
                else {
                    write(operacoes[WRITE], &comandoRecebidoDaPipePrincipal, sizeof(int));
                }
            } while (comandoRecebidoDaPipePrincipal != 4);
        }
        else {
            int comandoRecebidoDaPipePrincipal, saldo;
            do {
                read(operacoes[READ], &comandoRecebidoDaPipePrincipal, sizeof(int));
                if (comandoRecebidoDaPipePrincipal == 2) {
                    read(saberSaldo[READ], &saldo, sizeof(int));
                    printf("Pipe de subtracao: %d\n", getpid());
                    saldo -= 100;
                    write(saberSaldo[WRITE], &saldo, sizeof(int));
                }
                else {
                    write(operacoes[WRITE], &comandoRecebidoDaPipePrincipal, sizeof(int));
                }
            } while (comandoRecebidoDaPipePrincipal != 4);
        }
    } else {
        if (filho2 == 0) {
            //...
        } else {
            int saldo;
            do {
                scanf("%d", &comandoDado);
                if (comandoDado == 3) {
                    read(saberSaldo[READ], &saldo, sizeof(int));
                    printf("Pid que mostra o saldo: %d\n", getpid());
                    printf("Saldo: %d\n", saldo);
                    write(saberSaldo[WRITE], &saldo, sizeof(int));
                } else {
                    write(operacoes[WRITE], &comandoDado, sizeof(int));
                }
            
                if (comandoDado == 4) {
                    kill(filho1, SIGKILL);
                    kill(filho2, SIGKILL);
                    exit(0);
                }
            } while (comandoDado != comandoParaSair);
        }
    }
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
