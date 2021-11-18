import java.util.*;

public class leituraHasInt {
    //hasNext retorna um Bool para saber se tem algum elemento a ser lido
    public static void main(String args[]) {
        String s = "Hello world! \n 23";
        Scanner scanner = new Scanner(s);
        System.out.println("" + scanner.hasNext());
        System.out.println("" + scanner.nextLine());
        System.out.println("" + scanner.hasNextInt());
    } 
}
