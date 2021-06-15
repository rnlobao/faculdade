# ifndef duende_h
# define duende_h

//COMPLETAR O NOME DA ESTRUTURA
typedef struct ??? TADduende;
//COMPLETAR O NOME DA ESTRUTURA
typedef struct ??? TADtime;
//Manter como especificado
void lerQuantidade(int *qtd);
//Manter como especificado
TADduende *alocaDuendes(TADduende *D, int qtd);
//Manter como especificado
TADtime *alocaTimes(TADtime *T, int qtd);
//Manter como especificado
TADduende *desalocaDuendes(TADduende *D);
//Manter como especificado
TADtime *desalocaTimes(TADtime *T);
//Manter como especificado
void lerDuendes(TADduende *D, int qtd);
//Manter como especificado
void escalarTimes(TADduende *D, TADtime *T, int qtd);
//Manter como especificado
int proximoMaisVelho(TADduende *D, int qtd);
//Manter como especificado
void printTimes(TADtime *T, int qtd);
# endif
