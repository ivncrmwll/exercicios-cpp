// ============================================
//  BOLAO DA COPA 2026 - Atividade ITEAM
//  Modulo 08 - Linguagem de Programacao C++
//  VERSAO 2: 2 Jogadores + Ranking Final
//  Professora: Érika Dilly
//  Turma: Full Stack (noturno)
//  Alunos: Ivan, Marcio e Maik
// =============================================

#include <iostream>
#include <string>
using namespace std;

const int QTD_JOGOS       = 4;
const int QTD_APOSTADORES = 3;

// ============================================================
// CLASSE JOGO
// Representa um jogo com os dois times e os gols de cada lado
// ============================================================
class Jogo {
private:
    string timeCasa;
    string timeFora;
    int golsCasa;
    int golsFora;

public:
    // Construtor padrão
    Jogo() {
        this->timeCasa = "";
        this->timeFora = "";
        this->golsCasa = 0;
        this->golsFora = 0;
    }

    // Construtor com parâmetros
    Jogo(string timeCasa, string timeFora, int golsCasa, int golsFora) {
        this->timeCasa = timeCasa;
        this->timeFora = timeFora;
        this->golsCasa = golsCasa;
        this->golsFora = golsFora;
    }

    // Getters
    string getTimeCasa() { return this->timeCasa; }
    string getTimeFora() { return this->timeFora; }
    int    getGolsCasa() { return this->golsCasa; }
    int    getGolsFora() { return this->golsFora; }

    // Setters
    void setTimeCasa(string tc) { this->timeCasa = tc; }
    void setTimeFora(string tf) { this->timeFora = tf; }
    void setGolsCasa(int gc)    { this->golsCasa = gc; }
    void setGolsFora(int gf)    { this->golsFora = gf; }

    void exibir() {
        cout << this->timeCasa << " "
             << this->golsCasa << " x "
             << this->golsFora << " "
             << this->timeFora;
    }
};

// ============================================================
// CLASSE APOSTADOR
// Armazena nome, pontuação e palpites (vetor dinâmico)
// ============================================================
class Apostador {
private:
    string nome;
    int    pontuacao;
    Jogo*  palpites;
    int    qtdJogos;

public:
    Apostador() {
        this->nome      = "";
        this->pontuacao = 0;
        this->palpites  = nullptr;
        this->qtdJogos  = 0;
    }

    ~Apostador() {
        if (this->palpites != nullptr) {
            delete[] this->palpites;
            this->palpites = nullptr;
        }
    }

    void inicializar(string nome, int qtdJogos) {
        this->nome      = nome;
        this->pontuacao = 0;
        this->qtdJogos  = qtdJogos;
        this->palpites  = new Jogo[qtdJogos]; // ALOCAÇÃO DINÂMICA
    }

    // Getters
    string getNome()   { return this->nome; }
    int getPontuacao() { return this->pontuacao; }

    void cadastrarPalpites(Jogo jogosReais[]) {
        cout << "\n--- Palpites de " << this->nome << " ---\n";
        for (int i = 0; i < this->qtdJogos; i++) {
            int golsCasa, golsFora;

            cout << "Jogo " << (i + 1) << " (";
            jogosReais[i].exibir();
            cout << ")\n";

            cout << "  Seu palpite - Gols "
                 << jogosReais[i].getTimeCasa() << ": ";
            cin >> golsCasa;

            cout << "  Seu palpite - Gols "
                 << jogosReais[i].getTimeFora() << ": ";
            cin >> golsFora;

            this->palpites[i] = Jogo(
                jogosReais[i].getTimeCasa(),
                jogosReais[i].getTimeFora(),
                golsCasa,
                golsFora
            );
        }
    }

    // Regras: placar exato = 10pts | acertar vencedor/empate = 5pts
    void calcularPontuacao(Jogo jogosReais[]) {
        this->pontuacao = 0;

        for (int i = 0; i < this->qtdJogos; i++) {
            int gcReal    = jogosReais[i].getGolsCasa();
            int gfReal    = jogosReais[i].getGolsFora();
            int gcPalpite = this->palpites[i].getGolsCasa();
            int gfPalpite = this->palpites[i].getGolsFora();

            cout << "  Jogo " << (i + 1) << " | Real: ";
            jogosReais[i].exibir();
            cout << " | Palpite: ";
            this->palpites[i].exibir();

            if (gcReal == gcPalpite && gfReal == gfPalpite) {
                this->pontuacao += 10;
                cout << " >>> PLACAR EXATO! +10 pts\n";
            }
            else if (
                (gcReal > gfReal && gcPalpite > gfPalpite) ||
                (gcReal < gfReal && gcPalpite < gfPalpite) ||
                (gcReal == gfReal && gcPalpite == gfPalpite)
            ) {
                this->pontuacao += 5;
                cout << " >>> Acertou o vencedor! +5 pts\n";
            }
            else {
                cout << " >>> Errou. +0 pts\n";
            }
        }
        cout << "  Total de " << this->nome
             << ": " << this->pontuacao << " pontos\n";
    }
};

// ============================================================
// FUNÇÕES DO MENU
// ============================================================

void cadastrarJogos(Jogo jogos[]) {
    cout << "\n=== CADASTRAR RESULTADOS DOS JOGOS ===\n";
    string timeCasa, timeFora;
    int golsCasa, golsFora;

    for (int i = 0; i < QTD_JOGOS; i++) {
        cout << "\nJogo " << (i + 1) << ":\n";
        cout << "  Time da casa: "; cin >> timeCasa;
        cout << "  Time de fora: "; cin >> timeFora;
        cout << "  Gols " << timeCasa << ": "; cin >> golsCasa;
        cout << "  Gols " << timeFora << ": "; cin >> golsFora;

        jogos[i] = Jogo(timeCasa, timeFora, golsCasa, golsFora);
    }
    cout << "\nJogos cadastrados com sucesso!\n";
}

void cadastrarTodosPalpites(Apostador apostadores[], Jogo jogos[]) {
    cout << "\n=== CADASTRAR PALPITES ===\n";
    for (int i = 0; i < QTD_APOSTADORES; i++) {
        apostadores[i].cadastrarPalpites(jogos);
    }
    cout << "\nPalpites cadastrados com sucesso!\n";
}

void calcularPontuacoes(Apostador apostadores[], Jogo jogos[]) {
    cout << "\n=== CALCULANDO PONTUACOES ===\n";
    for (int i = 0; i < QTD_APOSTADORES; i++) {
        cout << "\n" << apostadores[i].getNome() << ":\n";
        apostadores[i].calcularPontuacao(jogos);
    }
}

void exibirRanking(Apostador apostadores[]) {
    int indices[QTD_APOSTADORES];
    for (int i = 0; i < QTD_APOSTADORES; i++) {
        indices[i] = i;
    }

    for (int i = 0; i < QTD_APOSTADORES - 1; i++) {
        for (int j = 0; j < QTD_APOSTADORES - 1 - i; j++) {
            if (apostadores[indices[j]].getPontuacao() <
                apostadores[indices[j + 1]].getPontuacao()) {
                int temp    = indices[j];
                indices[j]  = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }

    cout << "\n=== RANKING DO BOLAO ===\n";
    for (int i = 0; i < QTD_APOSTADORES; i++) {
        cout << (i + 1) << "o - "
             << apostadores[indices[i]].getNome()
             << " - "
             << apostadores[indices[i]].getPontuacao()
             << " pontos\n";
    }
}

// ==============================
// MAIN
// ==============================
int main() {
    cout << "=== SISTEMA DE BOLAO DA COPA 2026 ===\n";

    Jogo jogosReais[QTD_JOGOS];

    Apostador* apostadores = new Apostador[QTD_APOSTADORES];

    cout << "\nCadastro dos apostadores:\n";
    for (int i = 0; i < QTD_APOSTADORES; i++) {
        string nome;
        cout << "Nome do apostador " << (i + 1) << ": ";
        cin >> nome;
        apostadores[i].inicializar(nome, QTD_JOGOS);
    }

    int opcao;
    do {
        cout << "\n=== MENU ===\n";
        cout << "1 - Cadastrar resultados dos jogos\n";
        cout << "2 - Cadastrar palpites dos apostadores\n";
        cout << "3 - Calcular pontuacao\n";
        cout << "4 - Exibir ranking\n";
        cout << "0 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

        if      (opcao == 1) cadastrarJogos(jogosReais);
        else if (opcao == 2) cadastrarTodosPalpites(apostadores, jogosReais);
        else if (opcao == 3) calcularPontuacoes(apostadores, jogosReais);
        else if (opcao == 4) exibirRanking(apostadores);
        else if (opcao != 0) cout << "Opcao invalida!\n";

    } while (opcao != 0);

    delete[] apostadores;

    cout << "\nPrograma encerrado. Boa sorte!\n";
    return 0;
}

