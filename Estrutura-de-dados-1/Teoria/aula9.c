#define INICIO 0
#define MAXTAM 1000

typedef struct {
    int chave;
} TItem;

typedef struct {
    TItem item[MAXTAM];
    int primeiro, ultimo;
} TLista;