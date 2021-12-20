package Diario;
import java.util.Scanner;

public class DriverGradeBook {
    public static void main (String args[]) {
        GradeBook meuDiario = new GradeBook();
        GradeBookWithGettersSetters meuDiarioSG = new GradeBookWithGettersSetters();

        Scanner entrada = new Scanner(System.in);
        String nome;
        System.out.println("Digite o nome do curso: ");
        nome = entrada.nextLine(); //vai ler a linha
        meuDiario.displayMessage(nome);

        meuDiarioSG.setCouseName(nome);
        meuDiarioSG.displayMessage();
    }
}
//A gente pode passar varios parametros, n parametros, para isso usamos o (double... numeros)
//classes publicas tem que ficar em arquivos diferentes.
