import java.util.Vector;

public class Sistema {
    private Vector <Desmpregado> desempregados;
    private Vector <Vagas> vagas;
    private int idSelecionado;
    private String bairroSelecionado;

    public Sistema(Vector <Desmpregado> desempregados, Vector <Vagas> vagas, int id, String bairroSelecionado) {
        this.desempregados = desempregados;
        this.vagas = vagas;
        this.id = id;
        this.bairroSelecionado = bairroSelecionado;
    }
    private Vector <Desmpregado> desempregadosMesmoBairro = new Vector<Desempregado>();
    public <Desempregado> mesmoBairro(Vector <Desempregado> pessoas) {
        for (Vector <Desempregado> base : desempregados) {
            if (base.getBairro().equals(bairroSelecionado)) {
                desempregadosMesmoBairro.append(base);
            }
        }
        return Arrays.sort(desempregadosMesmoBairro.getIdade);
    }

    public <Desempregado> listados(int id) {
        for (Vector <Vagas> base : vagas) {
            if (base.getId() == idSelecionado) {
                return mesmoBairro(desempregados);
            }
        }
    }
}
