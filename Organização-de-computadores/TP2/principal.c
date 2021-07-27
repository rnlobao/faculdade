#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tamanhoram 1000
#define tamcache1 16
#define tamcache2 32
#define tamcache3 64
#define tamdasinstrucoes 5000



typedef struct {
    int opcode;
    int end1; //operacao
    int end2; //operacao
    int end3; //resultado
} instrucao;

typedef struct {
    int endereco;
    int conteudo;
    int refresh;

    //para escolher quem fica caso a cache encha vamos ter que escolher quem fica conforme:
    int prioridadeimportancia; // + importante
    int prioridadeidade; // - importante
} blocodememoria;

int main() {
    blocodememoria ram [tamanhoram];
    blocodememoria cache1[tamcache1];
    blocodememoria cache2 [tamcache2];
    blocodememoria cache3 [tamcache3];

    iniciaram(ram);
    iniciacache1(cache1);
    iniciacache2(cache2);
    iniciacache3(cache3);

    instrucao lerinstrucoes[tamdasinstrucoes];

    inicialerinstrucoes(lerinstrucoes);




    return 0;
}


//primeira funcao que inicia as memorias:
//no bloco nao usamos identificadores convencionais para nao confundir ram com cache...
//Nas funcoes que iniciam vamos preencher as memorias com valores aleatorizados.
void iniciaram (blocodememoria *ram) {
    srand(time(NULL));
    for (int i = 0; i < tamanhoram; i++) {
        ram[i].endereco = i; //ta dando uma tag pro local, tipo identificador
        ram[i].conteudo = rand() % 100000; //aqui dando valores aleatorios pra fazer as contas
        ram[i].refresh = 1; //Serve para manter alinhados os valores da cache1 com a ram, pra nao ter blocos o mesmo com valores diferentes
    }
    
}

void iniciacache1 (blocodememoria *cache1) {
    srand(time(NULL));
    for (int i = 0; i < tamcache1; i++) {
        cache1[i].endereco = (i + 1) * -1; //nao pode ser igual o i da cache para nao pegar os mesmos identificadores
        cache1[i].conteudo = rand() % 100000;
        cache1[i].refresh = 0; //pra saber que quando inicia a cache nenhum valor ainda foi inputado
    }
}

void iniciacache2 (blocodememoria *cache2) {
    srand(time(NULL));
    for (int i = 0; i < tamcache2; i++) {
        cache2[i].endereco = (i + 1) * -1; //nao pode ser igual o i da cache para nao pegar os mesmos identificadores
        cache2[i].conteudo = rand() % 100000;
        cache2[i].refresh = 0;
    }
}

void iniciacache3 (blocodememoria *cache3) {
    srand(time(NULL));
    for (int i = 0; i < tamcache3; i++) {
        cache3[i].endereco = (i + 1) * -1; //nao pode ser igual o i da cache para nao pegar os mesmos identificadores
        cache3[i].conteudo = rand() % 100000;
        cache3[i].refresh = 0;
    }
}

void inicialerinstrucoes (instrucao *instrucao) {
    srand(time(NULL));
    for (int i = 0; i < tamdasinstrucoes; i++) {
        instrucao[i].opcode = rand() % 1; //estamos gerando instrucoes aleatorias pro opcode processar 
        instrucao[i].end1 = rand() % tamanhoram; //os enderecoes das intrucoes foram passados de acordo com valores aleatorios que foram sorteados no inicia ram
        instrucao[i].end2 = rand() % tamanhoram;
        instrucao[i].end3 = rand() % tamanhoram;
    }
}


void maquinainterpretada (blocodememoria *cache1, blocodememoria *cache2, blocodememoria *cache3, instrucao *instrucao, blocodememoria *ram) {
    for (int i = 0; i < tamdasinstrucoes; i++) {
        if (instrucao[i].opcode = 0) { //soma
            //Como buscar os valores:
            

        }
        if (instrucao[i].opcode = 1) { //subtracao

        }
    }
}

int retornarovalorbuscado (blocodememoria *cache1, blocodememoria *cache2, blocodememoria *cache3, int endereco) { //endereco que vamos buscar, ele esta
    for (int i = 0; i < tamcache1; i++) {
        if (cache1[i].endereco == endereco && cache1[i].refresh == 1) {
            return cache1[i].conteudo;
        }
    }
    for (int j = 0; j < tamcache2; j++) {
        if (cache2[j].endereco == endereco && cache2[j].refresh == 1) {
            cache1[] //precisamos trazer o valor da cache2 pra cache1 e apagar na cache 2 de acordo com as hierarquias definidas la
        }
    }
}