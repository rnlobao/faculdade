public class TesteDespertador {
    public static void main(String args[]) {
        Despertador d = new Despertador();
        d.setAtual(14, 56, 20);
        d.setAlarme(18, 15, 0);

        System.out.println("Hora atual: " + d.getHoraAtual());
        System.out.println("Alarme: " + d.getAlarme());
    }
}
