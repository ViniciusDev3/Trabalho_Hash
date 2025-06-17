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

    string getNome() const { return nome; }
    string getCpf() const { return cpf; }
    string getCodReserva() const { return codReserva; }
    int getNumVoo() const { return numVoo; }
    string getAssento() const { return assento; }

    void imprimir() const {
        cout << "Nome: " << nome << " | CPF: " << cpf << " | Reserva: " << codReserva << " | Voo: " << numVoo << " | Assento: " << assento << endl;
    }
};

class ListPassageiros {
private:
    struct No
    {
        Passageiro p;      
        No* proximo;      
        
        No(Passageiro p): p(p), proximo(nullptr) {}
    };
    
    No* inicial;
public:
    ListPassageiros(): inicial(nullptr) {}

    void insert(Passageiro p) {

    }
};

class ListaPassageiros {
private:
    struct No {
        Passageiro p;
        No* proximo;
        No(Passageiro p) : p(p), proximo(nullptr) {}
    };

    No* inicio;

public:
    ListaPassageiros() : inicio(nullptr) {}

    void inserir(Passageiro p) {
        No* novo = new No(p);
        if (!inicio) {
            inicio = novo;
        } else {
            No* temp = inicio;
            while (temp->proximo)
                temp = temp->proximo;
            temp->proximo = novo;
        }
    }

    void imprimir() const {
        No* temp = inicio;
        while (temp) {
            temp->p.imprimir();
            temp = temp->proximo;
        }
    }

    //Gustavo
    void inserirNaBST(class xxxx) const;

    // usado para copiar para BST
    No* getInicio() const { return inicio; } 
};
