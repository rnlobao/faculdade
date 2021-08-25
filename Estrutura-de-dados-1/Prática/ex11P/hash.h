# ifndef hash_h
# define hash_h

typedef int TChave;

typedef struct {
	TChave chave;
} TItem;

typedef struct celula {
	struct celula *pProx;
	TItem item;
} TCelula;

typedef struct {
	TCelula *pPrimeiro , *pUltimo;
} TLista;

typedef struct {
	int n; 
	int nro_listas; 
	TLista *v; 
} THash ;

void TLista_Inicia(TLista *pLista);
int TLista_EhVazia(TLista *pLista);
int TLista_Insere(TLista *pLista , TItem x);
void THash_Inicia(THash *hash, int nro_listas);
int THash_H(THash *hash, TChave chave);
TCelula *THash_PesquisaCelula(THash *hash, TChave chave);
int THash_Insere (THash *hash, TItem x);
void Disponibiliza(THash *hash, int *n, int *c);
void Imprime(TLista *pLista);


# endif
