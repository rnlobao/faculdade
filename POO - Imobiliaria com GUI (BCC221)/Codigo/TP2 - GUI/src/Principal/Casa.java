package Principal;

public class Casa extends Imovel{

    private int andares;
    private boolean sala_jantar; 
    public Casa (){}

    public Casa (int id, float valor, String proprietario, String rua, String bairro, String cidade, int numero, int quartos, int banheiros, int andares, boolean sala_jantar) {    
        super (id, valor, proprietario, rua, bairro, cidade, numero, quartos, banheiros);
        this.andares = andares;
        this.sala_jantar = sala_jantar;
    }

    public int getAndares() {
        return andares;
    }

    
    public void setAndares(int andares) {
        this.andares = andares;
    }

    
    public boolean getSala_jantar() {
        return sala_jantar;
    }

   
    public void setSala_jantar(Boolean sala_jantar) {
        this.sala_jantar = sala_jantar;
    }

    public String toString(){

        return String.format("%sCasa: Numero de andares = %d\n%s", super.toString(), getAndares(), "----- \n");
    }
}
