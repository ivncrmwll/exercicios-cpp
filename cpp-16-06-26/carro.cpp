// Aula do Curso de FullStack ITEAM - C++ / 16-06-2026
// Professora: Erika
// Aluno: Ivan Bentes
// Github: https://github.com/ivncrmwll
// Exercicio de Fixacao 3 - Classe Carro (Encapsulamento - acelerar/frear)

#include <iostream>
#include <string>
using namespace std;

class Carro {
private:
    string marca;
    double velocidade;

public:
    Carro(string marca) {
        this->marca = marca;
        this->velocidade = 0;
    }

    void acelerar(double valor) {
        if (valor > 0) {
            this->velocidade += valor;
            cout << "O carro " << this->marca << " acelerou para "
                 << this->velocidade << " km/h." << endl;
        } else {
            cout << "Valor de aceleracao invalido!" << endl;
        }
    }

    void frear(double valor) {
        if (valor > 0) {
            this->velocidade -= valor;
            if (this->velocidade < 0) {
                this->velocidade = 0;
            }
            cout << "O carro " << this->marca << " freou para "
                 << this->velocidade << " km/h." << endl;
        } else {
            cout << "Valor de frenagem invalido!" << endl;
        }
    }

    string getMarca() {
        return this->marca;
    }

    double getVelocidade() {
        return this->velocidade;
    }

    void exibirInformacoes() {
        cout << "Carro: " << this->marca << " | Velocidade atual: "
             << this->velocidade << " km/h" << endl;
    }
};

int main() {
    Carro c1("Fiat Uno");

    c1.exibirInformacoes();

    c1.acelerar(60);
    c1.acelerar(40);
    c1.exibirInformacoes();

    c1.frear(30);
    c1.exibirInformacoes();

    c1.frear(100);
    c1.exibirInformacoes();

    return 0;
}

