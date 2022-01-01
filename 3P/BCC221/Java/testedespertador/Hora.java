public class Hora {
    private int h, m, s;
    public Hora() {
        this(0, 0, 0);
    }

    public Hora(int h, int m, int s) {
        setH(h);
        setM(m);
        setS(s);
    }

    public Hora(Hora h) {
        this(h.getH(), h.getM(), h.getS());
    }

    public void setH(int hora) {
        h = hora > 0 && hora < 24 ? hora : 0;
    }

    public int getH() {
        return h;
    }

    public void setM(int minutos) {
        m = minutos > 0 && minutos < 60 ? minutos : 0;
    }

    public int getM() {
        return m;
    }

    public void setS(int segundos) {
        s = segundos > 0 && segundos < 60 ? segundos : 0;
    }

    public int getS() {
        return s;
    }

    public String toUniversalString() {
        return String.format("%02d:%02d:%02d", getH(), getM(), getS());
    }
}
