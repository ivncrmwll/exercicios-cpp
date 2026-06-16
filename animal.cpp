// Aula do Curos de FullStack ITEAM - C++ / 15-06-2026
// Professora: Erika
// Aluno: Ivan Bentes
// Github: https://github.com/ivncrmwll

#include <iostream>
#include <string>
using namespace std;

class Animal {
private:
    string especie;
    string som;

public:
    Animal(string especie, string som) {
        this->especie = especie;
        this->som     = som;
    }

    void emitir_som() {
        cout << "O animal " << this->especie
             << " faz: " << this->som << endl;
    }
};

int main() {
    Animal a1("Gato", "Miau!");
    Animal a2("Vaca", "Muu!");
    Animal a3("Leão", "Roarrr!");

    a1.emitir_som();
    a2.emitir_som();
    a3.emitir_som();

    return 0;
}