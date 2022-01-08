import java.util.Vector;

public class Desempregado extends Pessoa {
    private Vector <String> skill;
    public Desempregado(String nome, int idade, int tempo, Vector <String> skill) {
        super(nome, idade);
        setDesempregado(tempo, skill);
    }

    public void setDesempregado(Vector <String> skill) {
        this.skill = skill;
    }
}
