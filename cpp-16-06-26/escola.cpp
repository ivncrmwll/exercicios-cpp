// Aula do Curso de FullStack ITEAM - C++ / 16-06-2026
// Professora: Erika
// Aluno: Ivan Bentes
// Github: https://github.com/ivncrmwll
// Exercicio 3 - Classes Aluno e Escola (Encapsulamento - matricula de alunos)

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Aluno {
private:
    string nome;
    int idade;
    string curso;

public:
    Aluno(string nome, int idade, string curso) {
        this->nome = nome;
        this->idade = idade;
        this->curso = curso;
    }

    string getNome() {
        return this->nome;
    }

    void setNome(string novo_nome) {
        if (!novo_nome.empty()) {
            this->nome = novo_nome;
        } else {
            cout << "Nome invalido! Nao pode ser vazio." << endl;
        }
    }

    int getIdade() {
        return this->idade;
    }

    void setIdade(int nova_idade) {
        if (nova_idade > 0) {
            this->idade = nova_idade;
        } else {
            cout << "Idade invalida! Deve ser maior que 0." << endl;
        }
    }

    string getCurso() {
        return this->curso;
    }

    void setCurso(string novo_curso) {
        if (!novo_curso.empty()) {
            this->curso = novo_curso;
        } else {
            cout << "Curso invalido! Nao pode ser vazio." << endl;
        }
    }

    string apresentar() {
        return "Nome: " + this->nome + " | Idade: " + to_string(this->idade)
               + " | Curso: " + this->curso;
    }
};

class Escola {
private:
    string nome;
    vector<Aluno> alunos;

public:
    Escola(string nome) {
        this->nome = nome;
    }

    string getNome() {
        return this->nome;
    }

    void setNome(string novo_nome) {
        if (!novo_nome.empty()) {
            this->nome = novo_nome;
        } else {
            cout << "Nome invalido! Nao pode ser vazio." << endl;
        }
    }

    void adicionarAluno(Aluno aluno) {
        this->alunos.push_back(aluno);
        cout << "Aluno matriculado com sucesso na " << this->nome << "." << endl;
    }

    void listarAlunos() {
        if (this->alunos.empty()) {
            cout << "Nenhum aluno matriculado." << endl;
            return;
        }
        cout << "Alunos matriculados na " << this->nome << ":" << endl;
        for (int i = 0; i < (int)this->alunos.size(); i++) {
            cout << " - " << this->alunos[i].apresentar() << endl;
        }
    }
};

int main() {
    // Extra
    Escola escola("Escola Futuro");

    Aluno a1("Joao", 20, "Informatica");
    Aluno a2("Maria", 22, "Engenharia Civil");

    escola.adicionarAluno(a1);
    escola.adicionarAluno(a2);

    cout << endl;
    escola.listarAlunos();

    cout << endl;
    // Teste
    a1.setIdade(21);
    a2.setCurso("Engenharia de Software");

    cout << "Aluno 1 atualizado -> " << a1.apresentar() << endl;
    cout << "Aluno 2 atualizado -> " << a2.apresentar() << endl;

    return 0;
}

