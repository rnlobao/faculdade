# ifndef ordenacao_h
# define ordenacao_h

int *desalocaVetor(int *vetor);
int *alocaVetor(int *vetor, int n);
void preenchervalores(int *vetor, int n);

void ordenacao(int *vetor, int n, int *movimentos);
void mergesort(int *vetor, int l, int r, int *movimentos);
void merge(int *vetor, int l, int m, int r, int *movimentos);

# endif
