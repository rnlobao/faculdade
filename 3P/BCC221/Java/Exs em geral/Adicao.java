import java.util.Scanner;

public class Adicao {
    public static void main(String args[]) {
        Scanner entrada = new Scanner(System.in);
        int numero1, numero2, soma;
        System.out.println("Informe o primeiro inteiro: ");
        numero1 = entrada.nextInt();
        System.out.println("Informe o segundo inteiro: ");
        numero2 = entrada.nextInt();
        soma = numero1 + numero2;
        System.out.printf("A soma eh %d\n", soma);
    }
}
