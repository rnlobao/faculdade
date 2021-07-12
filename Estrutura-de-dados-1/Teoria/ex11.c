void TPilha_inicia (Pilha**) {
    Pilha->prox = NULL;
    tam=0;
}

void TPilha_EhVazia(Pilha**) {
     if (Pilha->prox == NULL)
        return 1;
    else
        return 0;
}

void TPilha_Push(Pilha* int) (
    TPilha *novo = TPilha* malloc(sizeof(TPilha));
    novo->prox = NULL;

    if (TPilha_EhVazia(Pilha)) {
        Pilha->prox=novo;
    }
    
    else{
        TPilha *tmp = Pilha->prox;
        while(tmp->prox != NULL)
        tmp = tmp->prox;
        tmp->prox = novo;
    }
    tam++;
)

int TPilha_Pop (Pilha*) {
    if(Pilha->prox == NULL){
        printf("PILHA ja vazia\n\n");
        return NULL;
    }
    else{
        TPilha *ultimo = Pilha->prox,
        *penultimo = Pilha;

        while(ultimo->prox != NULL){
            penultimo = ultimo;
            ultimo = ultimo->prox;
        }

    penultimo->prox = NULL;
    tam--;
    return ultimo;
}
}