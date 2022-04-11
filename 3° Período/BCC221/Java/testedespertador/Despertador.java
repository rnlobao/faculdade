public class Despertador {
    boolean ligado;
    Hora alarme, horaAtual;

    public Despertador() {
        alarme = new Hora();
        horaAtual = new Hora();
    }

    public void setAlarme(int h, int m, int s) {
        alarme.setH(h);
        alarme.setM(m);
        alarme.setS(s);
    }

    public void setAtual(int h, int m, int s) {
        horaAtual.setH(h);
        horaAtual.setM(m);
        horaAtual.setS(s);
    }

    public String getAlarme() {
        return alarme.toUniversalString();
    }

    public String getHoraAtual() {
        return horaAtual.toUniversalString();
    }
}
