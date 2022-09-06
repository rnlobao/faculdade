package Principal;

public class Chacara extends Imovel{
    private boolean salao_festa;
    private boolean salao_jogos;
    private boolean campo_futebol;
    private boolean churrasqueira;
    private boolean piscina;

    public Chacara (){}

    public Chacara (int id, float valor, String proprietario, String rua, String bairro, String cidade, int numero, int quartos, int banheiros, Boolean salao_festa, Boolean salao_jogos, Boolean campo_futebol, Boolean churrasqueira, Boolean piscina){

        super(id, valor, proprietario, rua, bairro, cidade, numero, quartos, banheiros);
        this.salao_festa = salao_festa;
        this.salao_jogos = salao_jogos;
        this.campo_futebol = campo_futebol;
        this.churrasqueira = churrasqueira;
        this.piscina = piscina;
    }

    public Boolean getSalao_festa() {
        return salao_festa;
    }

    public void setSalao_festa(Boolean salao_festa) {
        this.salao_festa = salao_festa;
    }

    public Boolean getSalao_jogos() {
        return salao_jogos;
    }

    public void setSalao_jogos(Boolean salao_jogos) {
        this.salao_jogos = salao_jogos;
    }

    public Boolean getCampo_futebol() {
        return campo_futebol;
    }

    public void setCampo_futebol(Boolean campo_futebol) {
        this.campo_futebol = campo_futebol;
    }

    public Boolean getChurrasqueira() {
        return churrasqueira;
    }

    
    public void setChurrasqueira(Boolean churrasqueira) {
        this.churrasqueira = churrasqueira;
    }

    
    public Boolean getPiscina() {
        return piscina;
    }

   
    public void setPiscina(Boolean piscina) {
        this.piscina = piscina;
    }

    public String toString(){

        String existeOuNaoPiscina;
        
        if(getPiscina()){

            existeOuNaoPiscina = "Existe piscina!!";
        }

        else{

            existeOuNaoPiscina = "NÃO existe piscina!!";
        }

        return String.format("%sChacara: %s\n%s", super.toString(), existeOuNaoPiscina, "----- \n");
    }

}

