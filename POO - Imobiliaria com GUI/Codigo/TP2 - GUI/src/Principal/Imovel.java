package Principal;

import java.lang.Comparable;

public class Imovel implements Comparable<Imovel> {
    private int id;
    private float valor;
    private String proprietario; 
    private String rua;
    private String bairro;
    private String cidade;
    private int numero;
    private int quartos; 
    private int banheiros;

    public Imovel (){}

    public Imovel(int id, float valor, String prop, String rua, String bairro, String cidade, int numero, int quartos, int banheiros){
        this.id = id;
        this.valor = valor;
        this.proprietario = prop;
        this.rua = rua;
        this.bairro = bairro;
        this.cidade = cidade;
        this.numero = numero;
        this.quartos = quartos;
        this.banheiros = banheiros;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id < 1 ? 0 : this.id;;
    }

    public float getValor() {
        return valor;
    }

    public void setValor(float valor) {
        this.valor = valor < 0 ? 0 : this.valor;;
    }

    public String getProprietario() {
        return proprietario;
    }

    public void setProprietario(String proprietario) {
        this.proprietario = proprietario;
    }

    public String getRua() {
        return rua;
    }

    public void setRua(String rua) {
        this.rua = rua;
    }

    public String getBairro() {
        return bairro;
    }

    
    public void setBairro(String bairro) {
        this.bairro = bairro;
    }

    public String getCidade() {
        return cidade;
    }

    public void setCidade(String cidade) {
        this.cidade = cidade;
    }

    public int getNumero() {
        return numero;
    }

    public void setNumero(int numero) {
        this.numero = numero < 0 ? 0 : this.numero;
    }

    public int getQuartos() {
        return quartos;
    }

    public void setQuartos(int quartos) {
        this.quartos = quartos < 0 ? 0 : this.quartos;
    }

    public int getBanheiros() {
        return banheiros;
    }

    public void setBanheiros(int banheiros) {
        this.banheiros = banheiros < 0 ? 0 : this.banheiros;
    }

    public String toString(){
        return String.format("\n%sProprietario: %s\nPreço: %.2f\nNumero de quartos: %d\nRua: %s\nBairro: %s\nCidade: %s\n", "----- \n" , getProprietario(), getValor(), getQuartos(), getRua(), getBairro(), getCidade());
    } 

    public int compareTo (Imovel im){
        return Float.compare(this.getValor(), im.getValor());

    }

}
