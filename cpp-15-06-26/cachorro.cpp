// Aula do Curos de FullStack ITEAM - C++ / 15-06-2026
// Professora: Erika
// Aluno: Ivan Bentes
// Github: https://github.com/ivncrmwll

#include <iostream>
#include <string>
using namespace std;

class Cachorro {
private:
    string nome;
    string raca;

public:
    Cachorro(string nome, string raca) {
        this->nome = nome;
        this->raca = raca;
    }

    void latir() {
        cout << "Au Au! O cachorro " << this->nome
             << " está latindo." << endl;
    }
};

int main() {
    Cachorro c1("Rex", "Labrador");

    c1.latir();

    return 0;
}