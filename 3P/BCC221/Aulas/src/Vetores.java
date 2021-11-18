public class Vetores {
    public static void main (String args[]) {
        int j[];
        j = new int [12];
        //tem um length pra ver o tamanho do vetor
        int vet[] = {1, 2, 3, 4 ,5 ,6, 1, 2, 3, 4, 5, 6};
        for (int i : vet) {
            System.out.printf("%d ", i);
            //for aprimorado para nao cair em uma posição nula
        }

        //Declarando matrizes:
        int a[][] = {{1, 2}, {3, 4, 5}};
        int b[][] = new int [3][4];
        int c[][] = new int [2][]; //fala quantas colunas tem depois, ou seja cria so 2 linhas
        c[0] = new int[5]; // cria 5 colunas pra linha 0
        c[1] = new int[3]; // cria 3 colunas pra linha 1
    }
}