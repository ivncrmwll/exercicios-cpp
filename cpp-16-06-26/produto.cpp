// Aula do Curso de FullStack ITEAM - C++ / 16-06-2026
// Professora: Erika
// Aluno: Ivan Bentes
// Github: https://github.com/ivncrmwll
// Exercicio de Fixacao 2 - Classe Produto (Encapsulamento - validacao de preco)

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Produto {
private:
    string nome;
    double preco;

public:
    Produto(string nome, double preco) {
        this->nome = nome;
        this->preco = preco;
    }

    string get_nome() {
        return this->nome;
    }

    double get_preco() {
        return this->preco;
    }

    void set_preco(double novo_preco) {
        if (novo_preco > 0) {
            this->preco = novo_preco;
            cout << fixed << setprecision(2);
            cout << "Preco do produto '" << this->nome
                 << "' atualizado para R$ " << novo_preco << endl;
        } else {
            cout << "Preco invalido! O valor deve ser maior que zero." << endl;
        }
    }

    void exibir_informacoes() {
        cout << fixed << setprecision(2);
        cout << "Produto: " << this->nome << " | Preco: R$ " << this->preco << endl;
    }
};

int main() {
    // Teste
    Produto produto1("Notebook", 3500.00);
    Produto produto2("Mouse", 80.00);

    produto1.exibir_informacoes();
    produto2.exibir_informacoes();

    produto1.set_preco(-1500);
    produto2.set_preco(100);

    cout << "\nApos atualizacao de precos:" << endl;
    produto1.exibir_informacoes();
    produto2.exibir_informacoes();

    return 0;
}

