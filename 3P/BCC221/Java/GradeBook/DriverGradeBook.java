import java.util.Scanner;

public class DriverGradeBook {
    public static void main(String args[]) {
        GradeBook meuDiario = new GradeBook(); //enquanto nao da um new a variavel é uma referencia nao um objeto
        Scanner entrada = new Scanner(System.in);
        String nome;
        System.out.println("Digite o nome do curso: ");
        nome = entrada.nextLine();
        meuDiario.setCourseName(nome);
        meuDiario.displayMessage();
    }
}
