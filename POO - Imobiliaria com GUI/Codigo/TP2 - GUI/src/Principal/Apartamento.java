package Principal;

public class Apartamento extends Imovel{

    private int andar; 
    private float taxa_condominio;
    private boolean elevador;
    private boolean sacada;

    public Apartamento(){}

    public Apartamento(int id, float valor, String proprietario, String rua, String bairro, String cidade, int numero, int quartos, int banheiros, int andar, float taxa_condominio, Boolean elevador, Boolean sacada){

        super(id, valor, proprietario, rua, bairro, cidade, numero, quartos, banheiros);

        this.andar = andar;
        this.taxa_condominio = taxa_condominio;
        this.elevador = elevador;
        this.sacada = sacada;
    }

    public int getAndar() {
        return andar;
    }

    public void setAndar(int andar) {
        this.andar = andar;
    }

    public float getTaxa_condominio() {
        return taxa_condominio;
    }

    public void setTaxa_condominio(float taxa_condominio) {
        this.taxa_condominio = taxa_condominio < 0 ? 0 : this.taxa_condominio;;
    }

    public boolean getElevador() {
        return elevador;
    }

    public void setElevador(boolean elevador) {
        this.elevador = elevador;
    }

    public boolean getSacada() {
        return sacada;
    }


    public void setSacada(boolean sacada) {
        this.sacada = sacada;
    }

    public String toString(){

        String existeOuNaoelevador;

        if(getElevador()){

            existeOuNaoelevador = "Existe elevador!!";
        }

        else {

            existeOuNaoelevador = "NÃO existe elevador!!";
        }

        return String.format("%sApartamento: %s\n%s" , super.toString(), existeOuNaoelevador, "----- \n");
    }

}
