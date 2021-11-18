import javax.swing.JOptionPane;

public class SomaComCaixaDeMensagem {
    public static void main(String args[]) {
        String firstNumber;
        String secondNumber;
        int number1;
        int number2;
        int sum;

        firstNumber = JOptionPane.showInputDialog("Numero 1:");
        secondNumber = JOptionPane.showInputDialog("Numero 2: ");


        number1 = Integer.parseInt(firstNumber);
        number2 = Integer.parseInt(secondNumber);
        sum = number1+number2;
        JOptionPane.showMessageDialog(null, "A soma eh: " + sum, "Results", JOptionPane.PLAIN_MESSAGE);
        //tem ERROR_MESSAGE, INFORMATION_MESSAGE, WARNING_MESSAGE, QUESTION_MESSAGE E PLAIN_MESSAGE
        //Basicamente mostra o iconezin que vai usar

        //cuidado com soma de variavel, pode concatenar cadeias
        System.exit(0);
    }
}
