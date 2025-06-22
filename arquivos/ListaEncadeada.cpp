#include <iostream>
#include <string>

using namespace std;

class Passageiro {
private:
    string nome;
    string cpf;
    string codReserva;
    int numVoo;
    string assento;

public:
    Passageiro(string nome, string cpf, string codReserva, int numVoo, string assento)
    : nome(nome), cpf(cpf), codReserva(codReserva), numVoo(numVoo), assento(assento) {}

    void imprimir() const {
        cout << "Nome: " << nome 
        << " | CPF: " << cpf
        << " | Reserva: " << codReserva 
        << " | Voo: " << numVoo 
        << " | Assento: " 
        << assento 
        << endl;
    }
};

class No
{
public:
    Passageiro pessoal;
    No* next;

    No(Passageiro pessoal): pessoal(pessoal), next(nullptr) {}
};

class ListaPassageiros {
private:
    No* head;       
    No* tail;
        
public:
    ListaPassageiros(): head(nullptr), tail(nullptr) {}

    void insert(Passageiro pessoa) {
        No* newDate = new No(pessoa);
        if (!head) {
            head = tail = newDate;
        } else {
            tail->next = newDate;
            tail = newDate;
        }
    }

    void imprimir() const {
        No* atual = head;
        while (atual) {
            atual->pessoal.imprimir();
            atual = atual->next;
        }
    }
};

int main() {
    ListaPassageiros lista;

    Passageiro p1("João", "111.111.111-11", "R001", 123, "1A");
    Passageiro p2("Ana", "222.222.222-22", "R002", 123, "1B");

    lista.insert(p1);
    lista.insert(p2);

    cout << "📋 Lista de passageiros:\n";
    lista.imprimir();

    return 0;
}
