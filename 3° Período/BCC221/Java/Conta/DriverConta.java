import java.util.Scanner;

public class DriverConta {
    public static void main (String args[]) {
        Scanner input = new Scanner(System.in);
        Conta c1 = new Conta();
        Conta c2 = new Conta("Leonaro", 1500.56); //preencheu via construtor

        System.out.print("Difite nome: ");
        String nome = input.nextLine();
        System.out.print("Digite o saldo: ");
        double saldo = input.nextDouble();

        c1.setNome(nome);
        c1.setSaldo(saldo);

        c1.print();
        c2.print();
    }
}
