# ifndef pilha_h
# define pilha_h

typedef char Item;

typedef struct celula {
    Item item;
    struct celula *prox;
} Celula;

typedef struct {
    Celula *cabeca;
    int tamanho;
} Pilha;

//Inicializa a lista
void Pilha_Inicia(Pilha *pilha);
//Retorna se a lista esta vazia
int Pilha_EhVazia(Pilha *pilha);
// Insere um item no inicio da lista
int Pilha_Push(Pilha *pilha, Item item);
// Retira o primeiro item da lista
int Pilha_Pop(Pilha *pilha, Item *item);
// Remove cada elemento de uma lista e libera a memória
void Pilha_Esvazia(Pilha *pilha);
# endif
