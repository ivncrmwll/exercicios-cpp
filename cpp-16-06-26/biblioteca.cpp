// Aula do Curso de FullStack ITEAM - C++ / 16-06-2026
// Professora: Erika
// Aluno: Ivan Bentes
// Github: https://github.com/ivncrmwll
// Exercicio 2 - Classe Biblioteca (Encapsulamento - lista de livros)

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Biblioteca {
private:
    string nome;
    vector<string> livros;

public:
    Biblioteca(string nome) {
        this->nome = nome;
    }

    string getNome() {
        return this->nome;
    }

    void setNome(string novo_nome) {
        if (!novo_nome.empty()) {
            this->nome = novo_nome;
            cout << "Nome da biblioteca atualizado para: " << this->nome << endl;
        } else {
            cout << "Nome invalido! O nome nao pode ser vazio." << endl;
        }
    }

    void adicionarLivro(string titulo) {
        if (titulo.empty()) {
            cout << "Titulo invalido! Nao pode ser vazio." << endl;
            return;
        }
        for (int i = 0; i < (int)this->livros.size(); i++) {
            if (this->livros[i] == titulo) {
                cout << "O livro '" << titulo << "' ja esta cadastrado!" << endl;
                return;
            }
        }
        this->livros.push_back(titulo);
        cout << "Livro '" << titulo << "' adicionado com sucesso." << endl;
    }

    void listarLivros() {
        if (this->livros.empty()) {
            cout << "Nenhum livro cadastrado." << endl;
            return;
        }
        cout << "Livros disponiveis em " << this->nome << ":" << endl;
        for (int i = 0; i < (int)this->livros.size(); i++) {
            cout << " - " << this->livros[i] << endl;
        }
    }
};

int main() {
    // Extra
    Biblioteca b1("Biblioteca Central");

    b1.adicionarLivro("Dom Casmurro");
    b1.adicionarLivro("O Cortico");
    b1.adicionarLivro("Capitaes da Areia");
    b1.adicionarLivro("Dom Casmurro");
    cout << endl;
    b1.listarLivros();

    cout << endl;
    b1.setNome("Biblioteca Municipal Central");
    cout << "Nome atual: " << b1.getNome() << endl;

    return 0;
}
