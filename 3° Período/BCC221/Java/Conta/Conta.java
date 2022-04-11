public class Conta {
    private String nome;
    private double saldo;

    public Conta() {
    }

    public Conta(String nome, double saldo) {
        setNome(nome);
        setSaldo(saldo);
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getNome() {
        return nome;
    }

    public void setSaldo(double saldo) {
        this.saldo = saldo > 0 ? saldo : 0;
    }

    public double getSaldo() {
        return saldo;
    }

    public void deposita (double valor) {
        double tmp = getSaldo();
        setSaldo(tmp+valor);
    }

    public void print() {
        System.out.println("Nome: " + getNome() + "\nSaldo: " + getSaldo());
    }
}
