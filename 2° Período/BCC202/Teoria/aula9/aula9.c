//a lista é basicamente uma TAD para representar um conjunto de dados
//pode ser criado usando vetores ou ponteiros
//podems ser feitas algumas operações com elas


#define INICIO 0
#define MAXTAM 1000

typedef struct {
    int chave
} TItem; //aqui voce pode adicionar outras variáveis, da forma aqui temos os itens que vao ser usados na lista

typedef struct {
    TItem item [MAXTAM]; //vetor estático de tamanho maxtam
    int primeiro, ultimo;
} TLista;

