#include <iostream>
#include <string>

using namespace std;

class Carro {
    string placa;
    int velocidade;
public:
    void acelerar() {
        velocidade += 10;
    }
    void frear() {
        velocidade -= 10;
    }
    void set(string mplaca, int mvelo) {
        placa = mplaca;
        velocidade = mvelo;
    }
    void mostrarInfo() {
        cout << velocidade << "km/h\n";
    }

};

int main() {
    Carro eva;
    eva.set("ABC", 20);
    eva.acelerar();
    eva.mostrarInfo();
    eva.frear();
    eva.mostrarInfo();
    return 0;
}
