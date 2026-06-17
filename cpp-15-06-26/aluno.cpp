// Aula do Curos de FullStack ITEAM - C++ / 15-06-2026
// Professora: Erika
// Aluno: Ivan Bentes
// Github: https://github.com/ivncrmwll

#include <iostream>
#include <string>
using namespace std;

class Aluno {
private:
    string nome;
    double nota1;
    double nota2;

public:
    Aluno(string nome, double nota1, double nota2) {
        this->nome  = nome;
        this->nota1 = nota1;
        this->nota2 = nota2;
    }

    double calcularMedia() {
        return (this->nota1 + this->nota2) / 2.0;
    }

    void exibirResultado() {
        double media = this->calcularMedia();
        cout << "Aluno: " << this->nome
             << " | Media: " << media;

        if (media >= 7.0) {
            cout << " | Resultado: APROVADO" << endl;
        } else {
            cout << " | Resultado: REPROVADO" << endl;
        }
    }
};

int main() {
    Aluno a1("Joao", 8.0, 9.0);
    Aluno a2("Maria", 5.0, 6.0);

    a1.exibirResultado();
    a2.exibirResultado();

    return 0;
}