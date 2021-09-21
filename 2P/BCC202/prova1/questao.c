int imprimir (int *array, int inteiro) {
    int inteiro = len(array);
    if (inteiro == -1) {
        return 0;
    }
    return imprimir(array, inteiro - 1);
}



