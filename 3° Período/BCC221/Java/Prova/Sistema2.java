import java.util.Vector;

public class Sistema2 {
    
    private Vector <Desmpregado> desempregados;
    private Vector <Vagas> vagas;
    private String nomeDoDesempregado;

    public Sistema(Vector <Desmpregado> desempregados, Vector <Vagas> vagas, String nomeDoDesempregado) {
        this.desempregados = desempregados;
        this.vagas = vagas;
        this.nomeDoDesempregado = nomeDoDesempregado;
    }
    private Vector <Vagas> aptasACandidatar = new Vector<Vagas>();
    public <Vagas> vagasDisponiveis() {
        for (Desemoregado base : desempregados) {
            if (base.getNome().equals(nomeDoDesempregado)) {
                for (Vagas disponiveis : vagas) {
                    if (disponiveis.getSkills().equals(base.getSkills())) {
                        aptasACandidatar.add(disponiveis);
                    }
                }
            }
        }
        return Arryas.sort(aptasACandidatar.getRemuneracao());
    }
    
}
