// Aula do Curos de FullStack ITEAM - C++ / 15-06-2026
// Professora: Erika
// Aluno: Ivan Bentes
// Github: https://github.com/ivncrmwll

#include <iostream>
#include <string>

using namespace std;

class Aviao {
private:
    string modelo;
    int capacidade;

public:
    Aviao(string modelo, int capacidade) {
        this->modelo = modelo;
        this->capacidade = capacidade;
    }
void decolar() {
    cout << "O avião " << this->modelo
         << " está decolando com " << this->capacidade
         << " passageiros!" << endl;
}

void pousar() {
    cout << "O avião " << this->modelo
         << " pousou com segurança." << endl;
}
};

int main() {
    Aviao a1("Boeing 737", 180);
    Aviao a2("Airbus a380", 555);

    a1.decolar();
    a2.decolar();

    a1.pousar();
    a2.pousar();

    return 0;
}