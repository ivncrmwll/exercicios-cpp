// Aula do Curos de FullStack ITEAM - C++ / 15-06-2026
// Professora: Erika
// Aluno: Ivan Bentes
// Github: https://github.com/ivncrmwll

#include <iostream>
#include <string>
using namespace std;

class Pessoa {
private:
    string nome;
    int idade;

public:
    
    Pessoa(string nome, int idade) {
        this->nome  = nome;
        this->idade = idade;
    }

    void exibir() {
        cout << "Nome: " << this->nome
             << " | Idade: " << this->idade << " anos" << endl;
    }
};

int main() {
    Pessoa p1("Ana", 25);
    Pessoa p2("Carlos", 30);

    p1.exibir();
    p2.exibir();

    return 0;
}