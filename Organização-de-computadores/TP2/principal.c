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

    int cachehit;
    int cachemiss;

    //para escolher quem fica caso a cache encha vamos ter que escolher quem fica conforme:
    int prioridadeimportancia; // + importante
    int prioridadeidade; // - importante
    int soma; //apanhado do score da posicao da cache
} blocodememoria;

void iniciaram (blocodememoria *ram);
void iniciacache1 (blocodememoria *cache1);
void iniciacache2 (blocodememoria *cache2);
void iniciacache3 (blocodememoria *cache3);
void inicialerinstrucoes (instrucao *instrucao);
void maquinainterpretada (blocodememoria *cache1, blocodememoria *cache2,
                        blocodememoria *cache3, instrucao *instrucao, blocodememoria *ram);
int retornarovalorbuscado (blocodememoria *cache1, blocodememoria *cache2, blocodememoria *cache3, int endereco);
int definen (blocodememoria *cache1, blocodememoria *cache2, blocodememoria *cache3, int n);



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


    for (int i = 0; i < tamdasinstrucoes; i++) {
        if (lerinstrucoes[i].opcode == 1) {
            printf("Soma: %d + %d = %d\n", lerinstrucoes[i].end1, lerinstrucoes[i].end2, lerinstrucoes[i].end3);
        }
        else {
            printf("Subtracao: %d - %d = %d\n", lerinstrucoes[i].end1, lerinstrucoes[i].end2, lerinstrucoes[i].end3);
        }
    }



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
        instrucao[i].opcode = rand() % 3; //estamos gerando instrucoes aleatorias pro opcode processar 
        instrucao[i].end1 = rand() % tamanhoram; //os enderecoes das intrucoes foram passados de acordo com valores aleatorios que foram sorteados no inicia ram
        instrucao[i].end2 = rand() % tamanhoram;
        instrucao[i].end3 = rand() % tamanhoram;
    }
}


void maquinainterpretada (blocodememoria *cache1, blocodememoria *cache2, blocodememoria *cache3, instrucao *instrucao, blocodememoria *ram) {
    for (int i = 0; i < tamdasinstrucoes; i++) {
        if (instrucao[i].opcode == 1) { //soma
            //Como buscar os valores:
            int n = retornarovalorbuscado(cache1, cache2, cache3, instrucao[i].end1);
            int k = retornarovalorbuscado(cache1, cache2, cache3, instrucao[i].end2);
            ram[instrucao[i].end3].conteudo = n + k;
        }
        if (instrucao[i].opcode == 2) { //subtracao
            int n = retornarovalorbuscado(cache1, cache2, cache3, instrucao[i].end1);
            int k = retornarovalorbuscado(cache1, cache2, cache3, instrucao[i].end2);
            ram[instrucao[i].end3].conteudo = n - k;
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
            int n = definen(cache1, cache2, cache3, 1); //estamos escolhendo aqui qual posicao do cache1 vai ser apagado pra gente passar o da cache2 pra ca
            cache1[n] = cache2[j];  //transferindo o conteudo da cache2 pra posicao menos relevante da cache1

            cache2[j].conteudo = rand() % 100000;
            cache2[j].endereco = n + ((rand() % 10) * -1) - 1;

            retornarovalorbuscado (cache1, cache2, cache3, endereco);
            //Agora precismos definir em qual posicao cache1[??] vai ser apagada
            //precisamos trazer o valor da cache2 pra cache1 e apagar na cache 2
            //de acordo com as hierarquias definidas la
        }
    }
    for (int k = 0; k < tamcache3; k++) {
        if (cache3[k].endereco == endereco && cache3[k].refresh == 1) {
            int n = definen(cache1, cache2, cache3, 2);
            cache2[n] = cache3[k];  //transferindo o conteudo da cache3 pra posicao menos relevante da cache2

            cache3[k].conteudo = rand() % 100000;
            cache3[k].endereco = n + ((rand() % 10) * -1) - 1;

            retornarovalorbuscado (cache1, cache2, cache3, endereco);
        }
    }
}

int definen (blocodememoria *cache1, blocodememoria *cache2, blocodememoria *cache3, int n) {
    int soma1 = 0;
    int valor1, valor2;
    if (n == 1) {
        for (int i = 0; i < tamcache1; i++) {
            valor1 = cache1[i].prioridadeimportancia * 100000;
            valor2 = cache1[i].prioridadeidade * 10;
            cache1[i].soma = valor1 + valor2;
        }
        int menor = cache1[0].soma;
        for (int j = 0; j < tamcache1; j++) {
            if (cache1[j].soma < menor) {
                menor = cache1[j].soma;
            }
        }
        int posicaonacachesubstituivel;
        for (int i = 0; i < tamcache1; i++) {
            if (cache1[i].soma == menor) {
                posicaonacachesubstituivel = i;
            }
        }
        return posicaonacachesubstituivel; //oq tiver menor prioridade vai ser o apagado
    }

    if (n == 2) {
        for (int i = 0; i < tamcache2; i++) {
            valor1 = cache2[i].prioridadeimportancia * 100000;
            valor2 = cache2[i].prioridadeidade * 10;
            cache2[i].soma = valor1 + valor2;
        }
        int menor = cache2[0].soma;
        for (int j = 0; j < tamcache2; j++) {
            if (cache2[j].soma < menor) {
                menor = cache2[j].soma;
            }
        }
        int posicaonacachesubstituivel;
        for (int i = 0; i < tamcache2; i++) {
            if (cache2[i].soma == menor) {
                posicaonacachesubstituivel = i;
            }
        }
        return posicaonacachesubstituivel;
    }
    
    else {
        for (int i = 0; i < tamcache3; i++) {
            valor1 = cache3[i].prioridadeimportancia * 100000;
            valor2 = cache3[i].prioridadeidade * 10;
            cache3[i].soma = valor1 + valor2;
        }
        int menor = cache3[0].soma;
        for (int j = 0; j < tamcache3; j++) {
            if (cache3[j].soma < menor) {
                menor = cache3[j].soma;
            }
        }
        int posicaonacachesubstituivel;
        for (int i = 0; i < tamcache3; i++) {
            if (cache3[i].soma == menor) {
                posicaonacachesubstituivel = i;
            }
        }
        return posicaonacachesubstituivel;
    }
    
}

//preciso atribuir valores pra prioridade de importancia e de idade;
//trazer da ram pra cache3
//cache miss e quando tira da ram
//cache hit eq aundo tira das caches