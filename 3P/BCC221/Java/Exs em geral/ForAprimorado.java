public class ForAprimorado {
    public static void main (String args[]) {
        int vet[] = {1, 1, 3, 4, 55, 67};
        for (int i : vet) {
            System.out.printf("%d\n", i);
        }
        
        //Declaração de algumas matrizes
        int a[][] = {{1, 2, 3}, {3, 4, 5}};
        int b[][] = new int [3][4]; //Alocação de memória dinamica
        int c[][] = new int[2][3]; //cria duas linhas
        c[0] = new int[5]; // cria 5 colunas para a linha 0
        c[1] = new int[2]; //cria 2 colunas para a linha 1
    }
}
