# ifndef prioridade_h
# define prioridade_h

typedef struct{
	int time;
	int index;
	int timeused;
} TipoCaixa;

//Manter como especificado
TipoCaixa *alocaVetor(TipoCaixa *heap, int n);

//Manter como especificado
TipoCaixa *desalocaVetor(TipoCaixa *heap);

void leitor(TipoCaixa *heap, int n);

//Manter como especificado
void Heap_Constroi(TipoCaixa *heap, int n);

//int Heap_Refaz(TipoCaixa *heap, int n);
void Heap_Refaz(TipoCaixa *heap, int esq, int dir);

void imprime(TipoCaixa *heap, int n);
# endif
