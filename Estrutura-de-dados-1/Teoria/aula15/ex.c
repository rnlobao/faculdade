void quicksort (int *v, int inicio, int fim) {
    int pivo;
    if (fim > inicio) {
        pivo = particiona(v, inicio, fim);
        quicksort(v, inicio, pivo-1);
        quicksort(v, pivo+1, fim);
    }
}

int particiona (int *v, int inicio, int final) {
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = final;
    pivo = v[inicio];
    while (esq<dir) {
        while(v[esq] <= pivo)
            esq++;
        while(v[dir] > pivo)
            dir--;
        if (esq < dir) {
            aux = v[esq];
            v[esq] = v[dir];
            v[dir] = aux;
        }
    }
    v[inicio] = v[dir];
    v[dir] = pivo;
    return dir;
}