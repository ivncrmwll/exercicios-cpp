// Aula do Curos de FullStack ITEAM - C++ / 15-06-2026
// Professora: Erika
// Aluno: Ivan Bentes
// Github: https://github.com/ivncrmwll

#include <iostream>
#include <string>
using namespace std;

class contabancaria {
private:
    string titular;
    double saldo;

public:
    contabancaria(string titular, double saldo) {
        this->titular = titular;
        this->saldo = saldo;
    }
    void depositar(double valor) {
        this->saldo += valor;
        cout << "Deposito de R$ " << valor
             << " realizado. Saldo atual: R$ " << this->saldo << endl;
    }
    void sacar(double valor) {
        if (valor > this->saldo) {
            cout << "Saldo insuficiente! Saldo atual: R$ "
                 << this->saldo << endl;
        } else {
            this->saldo -= valor;
            cout << "Saque de R$ " << valor
                 << " realizado. Saldo atual: R$ " << this->saldo << endl;
        }
    }

    void exibirSaldo() {

        
        cout << "Titular: " << this->titular
             << " | Saldo final: R$ " << this->saldo << endl;
    }
};

int main() {
    contabancaria conta("Ivan", 1000.00);

    conta.depositar(500.00);
    conta.sacar(200.00);
    conta.exibirSaldo();

    return 0;
}