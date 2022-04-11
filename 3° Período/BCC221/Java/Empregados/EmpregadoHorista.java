public class EmpregadoHorista extends Empregado {
    private double valor;
    private double horas;

    public EmpregadoHorista(String nome, String sobrenome, String doc, double valor, double horas) {
        super(nome, sobrenome, doc);
        setEmpregadoHorista(valor, hora);
    }

    public void setEmpregadoHorista(double valor, double hora) {
        this.valor = valor;
        this.horas = hora;
    }

    public double salario() {
        if (horas <= 40) {
            return valor * horas;
        }
        else {
            return 40*valor+(horas-40)*valor*1,5;
        }
    }

    public String toString() {
        return String.format("%s\n%s: %.2f\n%s: &.2f", super.toString(), "Horas trabalhadas", horas, "Valor por hora", valor);
    }
}
