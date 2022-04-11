#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;


class Jogador {
    private:
        string nome;
        int idade;
        int habilidade;
        int gols;
        int camisa;
    public:
        Jogador(string nome, int idade, int habilidade) {
            this->nome = nome;
            this->idade = idade;
            this->habilidade = habilidade;
            this->gols = 0;
        }
        Jogador() {gols++;}
        virtual int getHabilidade() = 0;
        void somaGol() {
            gols++;
        }
};

class JogadorAtacante: Jogador {
    private:
        int velocidade;
        int tecnica;
    public:
        JogadorAtacante() {}
        int getHabilidade() {
            return ((getHabilidade()*5) + (velocidade*2) + (tecnica*3) ) / 10;
        }
};

class JogadorDefesa: Jogador {
    private:
        int desarme;
        int cobertura;
    public:
    JogadorDefesa() {}
        int getHabilidade() {
            return ((getHabilidade()*5) + (cobertura*3) + (desarme*2) )/10;
        }
};

void golsTipoJogador() {
    vector<Jogador> jogadores;
    int golsdefesa = 0, golsataque = 0;
    for(int i=0; i<jogadores.size(); i++) {
        if (typeid(jogadores[i]) == typeid(JogadorDefesa)) {
            golsdefesa++;
        }
        else if (typeid(jogadores[i]) == typeid(JogadorAtacante)) {
            golsataque++;
        }
    }
    cout << "gols defesa: " << golsdefesa;
    cout << "gols ataque: " << golsataque << endl;
}

class Partidas {
    public:
        int placarCasa;
        int placarVisitante;
        char timecasa, timefora;
}

class Time {
    int vitorias, derrotas;
}

class Campeonato {
    public:
        vector<Partidas> partidas;
        vector<Time> times;
    private:
        void classificacao() {
            for (int i = 0; i < partidas.size(); i++) {
                char time1 = partidas[i].timecasa;
                char time2 = partidas[i].timefora;
                if 

            }
        }
        
}