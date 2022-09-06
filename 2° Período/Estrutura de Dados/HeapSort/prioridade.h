# ifndef prioridade_h
# define prioridade_h

typedef struct{
<<<<<<< Updated upstream
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
=======
	int tempousado;
	int id;
	int valortempo;
} TipoCaixa;

TipoCaixa *alocaVetor(TipoCaixa *heap, int n);
TipoCaixa *desalocaVetor(TipoCaixa *heap);
void Heap_Constroi(TipoCaixa *heap, int n);
void Heap_Refaz(TipoCaixa *heap, int esq, int dir);
>>>>>>> Stashed changes
# endif
