# ifndef arvore_h
# define arvore_h


typedef long TChave;

typedef struct {
    long int num;
} TItem ;

typedef struct No {
    TItem item;
    struct No *esq, *dir;
} TNo ;

typedef TNo *TArvore;

void TArvore_Inicia (TNo **pRaiz);
void TArvore_Insere_Raiz (TNo **pRaiz , TItem x);
int TArvore_Insere (TNo *pRaiz , TItem x);
TNo *TNo_Cria (TItem x);
void Prefixa(TNo *p);
void Infixa(TNo *p);
void Posfixa(TNo *p);

# endif
