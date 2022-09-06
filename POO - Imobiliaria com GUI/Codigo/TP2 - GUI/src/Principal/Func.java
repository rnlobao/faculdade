package Principal;

import java.io.FileWriter;
import java.util.Vector;
import java.util.Collections;
import java.io.*;
import java.util.*;

public class Func {

    //metodo usado para trasnformar inteiro em booleano, já que no arquivos os valores estão como 0 e 1 e em java
    //0 e 1 nao sao considerados Booleanos
    public static boolean intToBoolean(String texto){

        return (Integer.parseInt(texto) == 0) ? false : true;
    }

    /*Aqui irei percorrer todo o vetor de ponteiros a classe imoveis e ver se o proprietario que foi passado como
    parametro tem algum imovel entre todos os imoveis que estão no arquivo e retorno true se tiver e false se nao tiver*/
    public static boolean propriIdenti (Vector <Imovel> imoveis, String propri){

        for (Imovel aux : imoveis){

            if(aux.getProprietario() == propri){

                return true;

            }
        }
        
        return false;
    }

    /*Aqui irei criar um vetor ponteiros a classe imoveis que vai guardar os objetos(Casa, Apartamento ou Chacara) que 
    tenham o valor dele abaixo ou igual do numero passado como parametro e esse vetor é retornado para o main para ser 
    impresso os atributos desse imovel com sobrecarga do cout*/
    public static Vector<Imovel> valorBarato (Vector <Imovel> imoveis, float valor){

        Vector <Imovel> ibarato = new Vector<Imovel>();

        for (Imovel aux : imoveis){
        
            if (aux.getValor() <= valor){

                ibarato.add(aux);
            }
        }   

        return ibarato;
    }

    /*Aqui irei criar um vetor ponteiros a classe imoveis que vai guardar os objetos(Casa, Apartamento ou Chacara) que 
    tenham o numero de quartos acima do numero passado como parametro e esse vetor é retornado para o main para ser 
    impresso os atributos desse imovel com sobrecarga do cout*/
    public static Vector<Imovel> muitosQuartos (Vector <Imovel> imoveis, int quartos){

        Vector <Imovel> iquartos = new Vector<Imovel>();
    
        for (Imovel aux : imoveis){
    
            if(aux.getQuartos() >= quartos){
    
                iquartos.add(aux);
            }
        }
    
        return iquartos;
    }

    /* Aqui irei criar um vetor ponteiros a classe imoveis que vai guardar os objetos(Casa, Apartamento ou Chacara) que 
    sejam o imovel passado como parametro (1 - casa, 2 - apartamento, 3 - chacara) que foi passada como parametro e esse 
    vetor é retornado para o main para ser impresso apenas caracteristicas(atributos) especificas dos imovel passado como 
    parametro*/
    public static Vector<Imovel> imovelUnico (Vector <Imovel> imoveis, int imo){

        Vector <Imovel> temp = new Vector<Imovel>();
    
        for (Imovel aux : imoveis){
    
            if(aux.getId() == imo){
    
                temp.add(aux);
            }
        }
        
        Collections.sort(temp);
    
        return temp;
    }
    /* Aqui irei criar um vetor ponteiros a classe imoveis que vai guardar os objetos(Casa, Apartamento ou Chacara) que 
    estejam na cidade que foi passada como parametro e esse vetor é retornado para o main para ser
    impresso os seus atributos */
    public static Vector<Imovel> cidadeImoveis (Vector <Imovel> imoveis, String cidade){

        Vector <Imovel> icity = new Vector<Imovel>();
    
        //Esse for é usado para percorremos objeto a objeto que está armazenado no vetor de ponteiro a classe Imovel e 
        //guarda os objetos que tem como atributo a cidade passada como parametro nessa novo vetor vazio icity
        for (Imovel aux : imoveis){
    
            if(aux.getCidade() == cidade){
    
                icity.add(aux);
            }
        }
    
        Collections.sort(icity, Collections.reverseOrder());
    
        return icity;
    }

    /*Vamos buscar no vetor de objetos imovel por meio de um iterador, onde quando o proprietario do imovel apontador
    pelo iterador foi igual ao proprietário passado como parametro, inserimos o iterador no final de um vetor de iteradores
    que apontam para objetos de imóvel. Assim, retornamos esse vetor de iteradores a objeto imóvel com cada um dos imoveis 
    do proprietario*/
    public static Vector<Imovel> retornaPropries(Vector<Imovel> imoveis, String propri){

        Vector<Imovel> vec = new Vector<>();
        
        for(Imovel aux : imoveis){

            if(aux.getProprietario() == propri){

                vec.add(aux);
            }
        }
    
        return vec;
    }   
    
    //Metodo usado para escrever os dados em um arquivo txt
    public static void escreverTexto(String caminho,Vector<Imovel> imo){
        try(
            FileWriter criador = new FileWriter(caminho, false); 
            BufferedWriter buffer = new BufferedWriter(criador);
            PrintWriter escritor = new PrintWriter(buffer);
        ){
            
            for(Imovel aux: imo){
                if(aux instanceof Casa){
                    Casa imoveis = (Casa) aux;
                    escritor.printf(
                            "casa;%.0f;%s;%s;%s;%s;%d;%d;%d;%d;%d;\n",
                            imoveis.getValor(),imoveis.getProprietario(),imoveis.getRua(),imoveis.getBairro(),imoveis.getCidade(),imoveis.getNumero(),imoveis.getQuartos(),imoveis.getBanheiros(),
                            imoveis.getAndares(),(imoveis.getSala_jantar())?1:0
                    );
                }else if(aux instanceof Apartamento){
                    Apartamento imoveis = (Apartamento) aux;
                    escritor.printf(
                            "apartamento;%.0f;%s;%s;%s;%s;%d;%d;%d;%.0f;%d;%d;\n",
                            imoveis.getValor(),imoveis.getProprietario(),imoveis.getRua(),imoveis.getBairro(),imoveis.getCidade(),imoveis.getNumero(),imoveis.getQuartos(),imoveis.getBanheiros(),
                            imoveis.getTaxa_condominio(), (imoveis.getElevador())?1:0, (imoveis.getSacada())?1:0
                    );
                }else{
                    Chacara imoveis = (Chacara) aux;
                    escritor.printf(
                            "chacara;%.0f;%s;%s;%s;%s;%d;%d;%d;%d;%d;%d;%d;%d;\n",
                            imoveis.getValor(),imoveis.getProprietario(),imoveis.getRua(),imoveis.getBairro(),imoveis.getCidade(),imoveis.getNumero(),imoveis.getQuartos(),imoveis.getBanheiros(),
                            (imoveis.getSalao_festa())?1:0, (imoveis.getSalao_jogos())?1:0, (imoveis.getCampo_futebol())?1:0, (imoveis.getChurrasqueira())?1:0, (imoveis.getPiscina())?1:0
                    );
                }
            }
            
        }catch(IOException e){
            e.printStackTrace();
        }  
    }
    
    
}   
