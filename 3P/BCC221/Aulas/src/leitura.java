import java.util.*;

public class leitura {
    public static void main (String args[]) {
        Scanner entrada = new Scanner (System.in);
        int n1, n2, soma;
        System.out.println("Primeiro numero: ");
        n1 = entrada.nextInt();
        System.out.println("Segundo numero: ");
        n2 = entrada.nextInt();
        soma = n1+n2;
        System.out.printf("A soma eh %d\n", soma);
    }
}



