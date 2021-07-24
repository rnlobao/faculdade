#ifndef maquina_h
#define maquina_h

#define TAM_RAM 1000
#define TAM_CACHEL1 32
#define TAM_CACHEL2 48
#define TAM_CACHEL3 64
#define NRO_INSTRUCOES 20000
#define NRO_OPERACOES 2
#define RAND_MEMORIA 1000

#define ANSI_BOLD "\x1b[1m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_YELLOW "\e[0;33m"
#define ANSI_RESET "\x1b[0m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define TAB_HOR "\u2501" // ━
#define TAB_VER "\u2503" // ┃
#define TAB_TL "\u250F"  // ┏
#define TAB_TR "\u2513"  // ┓
#define TAB_BL "\u2517"  // ┗
#define TAB_BR "\u251B"  // ┛

typedef struct
{
    int opCode;
    int addressOne;
    int addressTwo;
    int addressThree;
} unidade_Instrucao;

typedef struct
{
    int tag;
    int data;
} blocoMemoria;

void iniciarMemoria(blocoMemoria *Memoria, int tam_Memoria, int boolean_Cache);
void iniciarInstrucoes(unidade_Instrucao *Instrucoes);
blocoMemoria buscarMemoria(blocoMemoria *cacheL1, blocoMemoria *cacheL2, blocoMemoria *cacheL3, blocoMemoria *RAM, int memory_Adress, int *cacheHit, int *cacheMiss, int *LRU_L1, int *LRU_L2, int *LRU_L3, int *custoTotal);
void levarMemoria(blocoMemoria addressThree, int memory_Address, blocoMemoria *RAM);
void atualizar_LRU(int *LRU_L1, int *LRU_L2, int *LRU_L3);
void maquinaInterpretada(blocoMemoria *cacheL1, blocoMemoria *cacheL2, blocoMemoria *cacheL3, blocoMemoria *RAM, unidade_Instrucao *vetorInstrucao, int *cacheHit, int *cacheMiss, int *LRU_L1, int *LRU_L2, int *LRU_L3, int *custoTotal);
void imprimirMemoria(blocoMemoria *Memoria, int tam_Memoria);
void imprimirRelatorio(int *cacheHit, int *cacheMiss, int *custoTotal);

int somarInteiros(int contentOne, int contentTwo);
int subtrairInteiros(int contentOne, int contentTwo);
int multiplicarInteiros(int contentOne, int contentTwo);
int dividirInteiros(int contentOne, int contentTwo);
int sqrtInteiros(int contentOne);
int calcularPitagoras(int contentOne, int contentTwo);
int calcularArea(int contentOne, int contentTwo);
int calcularFatorial(int contentOne);
int calcularExponencial(int contentOne, int contentTwo);

#endif