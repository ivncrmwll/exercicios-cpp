// Aula do Curso de FullStack ITEAM - C++ / 16-06-2026
// Professora: Erika
// Aluno: Ivan Bentes
// Github: https://github.com/ivncrmwll
// Exercicio 1 - Classe Restaurante (Encapsulamento - cardapio e atendimento)

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Restaurante {
private:
    string nome;
    vector<string> cardapio;

public:
    Restaurante(string nome) {
        this->nome = nome;
    }

    string getNome() {
        return this->nome;
    }

    void setNome(string novo_nome) {
        if (!novo_nome.empty()) {
            this->nome = novo_nome;
            cout << "Nome do restaurante atualizado para: " << this->nome << endl;
        } else {
            cout << "Nome invalido! O nome nao pode ser vazio." << endl;
        }
    }

    void adicionarPrato(string prato) {
        for (int i = 0; i < (int)this->cardapio.size(); i++) {
            if (this->cardapio[i] == prato) {
                cout << "O prato '" << prato << "' ja existe no cardapio!" << endl;
                return;
            }
        }
        this->cardapio.push_back(prato);
        cout << "Prato '" << prato << "' adicionado ao cardapio." << endl;
    }

    void listarCardapio() {
        if (this->cardapio.empty()) {
            cout << "Cardapio vazio." << endl;
            return;
        }
        cout << "Cardapio de " << this->nome << ":" << endl;
        for (int i = 0; i < (int)this->cardapio.size(); i++) {
            cout << " - " << this->cardapio[i] << endl;
        }
    }

    void atenderCliente(string nome_cliente, string prato) {
        for (int i = 0; i < (int)this->cardapio.size(); i++) {
            if (this->cardapio[i] == prato) {
                cout << "Pedido confirmado! " << nome_cliente
                     << " pediu: " << prato << endl;
                return;
            }
        }
        cout << "Desculpe, " << nome_cliente << ", o prato '"
             << prato << "' nao existe no cardapio." << endl;
    }
};

int main() {
    // Extra
    Restaurante r1("Sabor Caseiro");

    r1.adicionarPrato("Feijoada");
    r1.adicionarPrato("Picanha na Brasa");
    r1.adicionarPrato("Moqueca de Peixe");

    cout << endl;
    r1.listarCardapio();

    cout << endl;
    r1.atenderCliente("Ana", "Feijoada");
    r1.atenderCliente("Bruno", "Lasanha");

    cout << endl;
    r1.setNome("Sabor Caseiro Premium");
    cout << "Nome atual: " << r1.getNome() << endl;

    return 0;
}

