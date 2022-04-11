public abstract class Empregado {
    private String nome;
    private String sobrenome;
    private String documento;
    public Empregado(String nome, String sobrenome, String documento) {
        setEmpregado(nome, sobrenome, documento);
    }

    public void setEmpregado(String nome, String sobrenome, String documento) {
        this.nome = nome;
        this.sobrenome = sobrenome;
        this.documento = documento;
    }

    public String toString() {
        return String.format("\n%s: %s\n%s: %s\n%s: %s", "Nome", nome, "sobrenome", sobrenome, "documento", documento);
    }
    
    public abstract double salario();
}
