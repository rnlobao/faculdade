public abstract class Pessoa {
    private String nome;
    private int idade;

    public Pessoa(String nome, int idade) {
        setPessoa(nome, idade);
    }

    public void setPessoa(String nome, int idade) {
        this.nome = nome;
        this.idade = idade;
    }
}
