#include <iostream>
#include <string>
#include <utility>
#include <cstdio>

using namespace std;

struct Node {
    int chave;
    string valor;
    Node* proximo;
    
    Node(int key, const string& data) : chave(key), valor(data), proximo(nullptr) {}
};

class Voos {
private:
    Node** tabela_hash; //ponteiro para tabela rash
    int tamanho_tabela;
    
    int hashFunction(int chave) const 
    {
        return chave % tamanho_tabela;
    }
    
    void redimensionar(int novo_tamanho) 
    {
        Node** nova_tabela = new Node*[novo_tamanho]();  
        
        //reinsere todos os elementos na nova tabela
        for (int i = 0; i < tamanho_tabela; ++i) 
        {
            Node* atual = tabela_hash[i];
            while (atual != nullptr) 
            {
                Node* proximo = atual->proximo;
                int novo_indice = hashFunction(atual->chave) % novo_tamanho;
                
                atual->proximo = nova_tabela[novo_indice];
                nova_tabela[novo_indice] = atual;
                
                atual = proximo;
            }
        }
        
        //libera a tabela antiga e atualiza
        delete[] tabela_hash;
        tabela_hash = nova_tabela;
        tamanho_tabela = novo_tamanho;
    }
    
    void limparTabela() 
    {
        for (int i = 0; i < tamanho_tabela; ++i) 
        {
            Node* atual = tabela_hash[i];
            while (atual != nullptr) 
            {
                Node* proximo = atual->proximo;
                delete atual;
                atual = proximo;
            }
        }
    }

public:
    // construtor
    Voos(int tamanho_inicial = 10) : tamanho_tabela(tamanho_inicial) {
        tabela_hash = new Node*[tamanho_tabela]();  
    }
    
    // destrutor
    ~Voos() {
        limparTabela();
        delete[] tabela_hash;
    }
    
    void cadastrarVoo() 
    {
        int numero_voo;
        char destino[30];

        FILE* lista_voos = fopen("voos2.txt", "r");

        if (lista_voos == nullptr)
        {
            perror("Erro ao abrir o arquivo");
            return;
        }

        while(fscanf(lista_voos, "%d %99[^\n]", &numero_voo, destino) == 2) 
        {
            inserir(numero_voo, string(destino));
        }

        cout << "Voos Cadastrados com sucesso!" << endl;
        
        fclose(lista_voos);
    }

    void inserir(int chave, const string& valor) 
    {
        // redimensiona se fator de carga > 0.7
        if (contarElementos() > 0.7 * tamanho_tabela) 
        {
            redimensionar(tamanho_tabela * 2);
        }
        
        int indice = hashFunction(chave);
        
        // verifica se a chave já existe
        Node* atual = tabela_hash[indice];
        while (atual != nullptr) 
        {
            if (atual->chave == chave) 
            {
                atual->valor = valor;
                cout << "Voo " << chave << " atualizado.\n";
                return;
            }
            atual = atual->proximo;
        }
        
        // insere novo nó no início da lista
        Node* novo = new Node(chave, valor);
        novo->proximo = tabela_hash[indice];
        tabela_hash[indice] = novo;
    }
    
    int contarElementos() const 
    {
        int count = 0;
        for (int i = 0; i < tamanho_tabela; ++i) 
        {
            Node* atual = tabela_hash[i];
            while (atual != nullptr) 
            {
                ++count;
                atual = atual->proximo;
            }
        }
        return count;
    }

    string buscar(int chave) const 
    {
        int indice = hashFunction(chave);
        Node* atual = tabela_hash[indice];
        
        while (atual != nullptr) 
        {
            if (atual->chave == chave) 
            {
                return "Voo: " + to_string(atual->chave) + " | Destino: " + atual->valor;
            }
            atual = atual->proximo;
        }
        return "Voo não encontrado";
    }

    void imprimir() const 
    {
        cout << "\nTABELA HASH (Tamanho: " << tamanho_tabela << ")\n";
        cout << "[NÚMERO][DESTINO]\n";
        
        for (int i = 0; i < tamanho_tabela; ++i) 
        {
            Node* atual = tabela_hash[i];
            if (atual != nullptr) 
            {
                cout << "Posição: " << i << ": ";
                while (atual != nullptr) 
                {
                    cout << "[" << atual->chave << "][" << atual->valor << "] ";
                    atual = atual->proximo;
                }
                cout << endl;
            }
        }
    }
};

int main() {
    int tamanho_inicial;
    cout << "Digite o tamanho inicial da tabela hash: ";
    cin >> tamanho_inicial;
    
    Voos aeroporto(tamanho_inicial);
    
    while (true) {
        cout << "\nMENU:\n";
        cout << "1. Cadastrar voo\n";
        cout << "2. Buscar voo\n";
        cout << "3. Listar todos\n";
        cout << "4. Sair\n";
        cout << "Escolha: ";
        
        int opcao;
        cin >> opcao;
        
        switch (opcao) {
            case 1:
                aeroporto.cadastrarVoo();
                break;
            case 2: {
                int numero;
                cout << "Digite o número do voo: ";
                cin >> numero;
                cout << aeroporto.buscar(numero) << endl;
                break;
            }
            case 3:
                aeroporto.imprimir();
                break;
            case 4:
                return 0;
            default:
                cout << "Opção inválida!\n";
        }
    }
}