#include <iostream>
using namespace std;

class DiarioClasse {
    public:
        void mostraMensagem () {
            cout << "Hello World!" << endl;
        }
};

int main() {
    DiarioClasse meuDiario;
    meuDiario.mostraMensagem();
    return 0;
}
