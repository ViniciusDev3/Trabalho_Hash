#include <iostream>
#include <string>
#include <vector>

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

    string getNome() const {
        return nome;
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

    void deletarPorNome(const string& nome) {
    if (!head) {
        cout << "A lista está vazia.\n";
        return;
    }

    No* atual = head;
    No* anterior = nullptr;

    while (atual) {
        if (atual->pessoal.getNome() == nome) {
            if (atual == head) {
                head = head->next;
                if (atual == tail) tail = nullptr; // lista ficou vazia
            } else {
                anterior->next = atual->next;
                if (atual == tail) tail = anterior;
            }
            delete atual;
            cout << "Passageiro com Nome " << nome << " removido com sucesso.\n";
            return;
        }
        anterior = atual;
        atual = atual->next;
    }

        cout << "Passageiro com Nome " << nome << " não encontrado.\n";
    }
};

class TreeNode 
{
private:
    string data;
    TreeNode* left;
    TreeNode* right;

    TreeNode* minValueNode(TreeNode* node) 
    {
        TreeNode* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

public:
    TreeNode(const string& value) : data(value), left(nullptr), right(nullptr) {}

    ~TreeNode() 
    {
        delete left;
        delete right;
    }

    int getBalance()
    {
        int leftHeight = left ? left->height() : 0;
        int rightHeight = right ? right->height() : 0;
        return (leftHeight - rightHeight);         
    }

    TreeNode* rotateRight()
    {
        TreeNode* x = left;
        TreeNode* T2 = x->right;

        x->right = this;
        left = T2;

        return x;
    }

    TreeNode* rotateLeft()
    {
        TreeNode* y = right;
        TreeNode* T2 = y->left;

        y->left = this;
        right = T2;
        
        return y;
    }

    TreeNode* insert(const string& new_data) 
    {
        if (new_data < data) 
        {
            if (left == nullptr)
                left = new TreeNode(new_data);
            else
                left = left->insert(new_data);
        } 
        else if (new_data > data)
        {
            if (right == nullptr)
                right = new TreeNode(new_data);
            else
                right = right->insert(new_data);
        }
        else
        {
            // dados duplicados não são inseridos
            return this;
        }

        int balance = getBalance();

        if (balance > 1)
        {
            if (new_data < left->data)
                return rotateRight(); // LL
            else
            {
                left = left->rotateLeft(); // LR
                return rotateRight();
            }
        }

        if (balance < -1)
        {
            if (new_data > right->data)
                return rotateLeft(); // RR
            else
            {
                right = right->rotateRight(); // RL
                return rotateLeft();
            }
        }

        return this;
    }

    void printTree(const string& prefix = "", bool isLeft = true) 
    {
        if (right)
            right->printTree(prefix + (isLeft ? "│   " : "    "), false);

        cout << prefix;
        cout << (isLeft ? "└── " : "┌── ");
        cout << data << endl;

        if (left)
            left->printTree(prefix + (isLeft ? "    " : "│   "), true);
    }

    void inOrder() 
    {
        if (left) left->inOrder();
        cout << data << " \n";
        if (right) right->inOrder();
    }

    bool search(const string& key) 
    {
        if (data == key)
            return true;
        if (key < data && left)
            return left->search(key);
        if (key > data && right)
            return right->search(key);
        return false;
    }

    int height() 
    {
        int leftHeight = left ? left->height() : 0;
        int rightHeight = right ? right->height() : 0;
        return 1 + max(leftHeight, rightHeight);
    }

    TreeNode* deleteNode(const string& key) 
    {
        if (key < data && left)
            left = left->deleteNode(key);
        else if (key > data && right)
            right = right->deleteNode(key);
        else if (key == data)
        {
            if (!left)
            {
                TreeNode* temp = right;
                this->right = nullptr;
                delete this;
                return temp;
            }

            if (!right)
            {
                TreeNode* temp = left;
                this->left = nullptr;
                delete this;
                return temp;
            }

            TreeNode* temp = minValueNode(right);
            data = temp->data;
            right = right->deleteNode(temp->data);
        }

        int balance = getBalance();

        if (balance > 1)
        {
            if (left->getBalance() >= 0)
                return rotateRight();
            else
            {
                left = left->rotateLeft();
                return rotateRight();
            }
        }

        if (balance < -1)
        {
            if (right->getBalance() <= 0)
                return rotateLeft();
            else
            {
                right = right->rotateRight();
                return rotateLeft();
            }
        }

        return this;
    }

    void clear() 
    {
        if (left)
        {
            left->clear();
            delete left;
        }
        if (right)
        {
            right->clear();
            delete right;
        }
    }	
};

string gerarNome() 
{
	vector<string> nomes = 
  {
    "João", "Ana", "Carlos", "Maria", "Lucas", "Érica", "Bruno", "Juliana", "Pedro", "Camila",
    "Gustavo", "Larissa", "Felipe", "Aline", "Ricardo", "Patrícia", "André", "Renata", "Tiago", "Gabriela",
    "Daniel", "Vanessa", "Rafael", "Natália", "Eduardo", "Carla", "Leonardo", "Tatiane", "Rodrigo", "Marina",
    "Fernando", "Érica", "Marcelo", "Sabrina", "Igor", "Viviane", "Fábio", "Letícia", "Alexandre", "Nicole",
    "Henrique", "Rafaela", "Matheus", "Débora", "Diego", "Jéssica", "Murilo", "Lívia", "Thiago", "Cíntia",
    "Vinícius", "Raquel", "Caio", "Elaine", "Alan", "Bárbara", "Heitor", "Daniela", "Otávio", "Yasmin",
    "Maurício", "Roberta", "Paulo", "Caroline", "Antônio", "Sônia", "Joaquim", "Gisele", "Mateus", "Clarissa",
    "Alana", "Leandro", "Tatiana", "Rebeca", "Jonas", "Nádia", "Wilson", "Monique", "Vagner", "Priscila",
    "Rogério", "Isabela", "Artur", "Manuela", "Luís", "Lorena", "Benjamin", "Bianca", "Hugo", "Helena",
    "Cristiano", "Lúcia", "Armando", "Elaine", "Caíque", "Sandra", "Jonathan", "Celina", "Nilson", "Tatiane"
  };

    vector<string> sobrenomes = 
    {
    	"Silva", "Souza", "Pereira", "Oliveira", "Costa", "Fernandes", "Martins", "Carvalho", "Ribeiro", "Barros",
      "Dias", "Almeida", "Gomes", "Pinto", "Araújo", "Teixeira", "Castro", "Nunes", "Ramos", "Melo",
      "Monteiro", "Pires", "Vieira", "Correia", "Freitas", "Moraes", "Antunes", "Cunha", "Leal", "Batista",
      "Dantas", "Fonseca", "Tavares", "Duarte", "Cardoso", "Macedo", "Santana", "Braga", "Faria", "Lopes",
      "Barcellos", "Neves", "Rezende", "Soares", "Peixoto", "Moura", "Assis", "Henriques", "Magalhães", "Azevedo",
      "Amorim", "Nóbrega", "Mendes", "Prado", "Guimarães", "Andrade", "Freire", "Sales", "Pimenta", "Borges",
      "Godoy", "Rangel", "Torres", "Castilho", "Aguiar", "Rezende", "Xavier", "Matos", "Meireles", "Lacerda",
      "Medeiros", "Valente", "Aragão", "Teles", "Santos", "Brandão", "Lima", "Serpa", "Moreira", "Ferraz",
      "Novaes", "Furtado", "Cavalcanti", "Galvão", "Abreu", "Vasconcelos", "Bezerra", "Campos", "Queiroz", "Nogueira",
      "Machado", "Camargo", "Cavalcante", "Pinheiro", "Bittencourt", "Lessa", "Maranhão", "Mota", "Vieira", "Beltrão"
    };

	int i = rand() % nomes.size();
	int j = rand() % sobrenomes.size();

	return nomes[i] + " " + " " + sobrenomes[j];
}

string gerarCPF() {
    string cpf;
    for (int i = 0; i < 11; ++i)
        cpf += char('0' + rand()%10);
    return cpf;
}

string gerarCod() {
    return "R" + to_string(rand()%10000);
}

int gerarVoo() {
    return 100 + rand()%900;
}

string gerarAssento() {
    char letra = 'A' + rand()%6;
    int num = 1 + rand()%30;
    return to_string(num) + letra;
}

int main() {
    srand((unsigned)time(nullptr));

    ListaPassageiros lista;
    TreeNode* root = nullptr;

    // popula com 849 passageiros
    for (int i = 0; i < 849; ++i) {
        string nome     = gerarNome();
        string cpf      = gerarCPF();
        string codRes   = gerarCod();
        int    numVoo   = gerarVoo();
        string assento  = gerarAssento();

        Passageiro p(nome, cpf, codRes, numVoo, assento);
        lista.insert(p);
        root = (root ? root->insert(nome) : new TreeNode(nome));
    }

    cout << "\n📋 Lista completa de passageiros:\n";
    lista.imprimir();

    // remoção interativa
    cout << "\n\nDigite um nome completo para deletar: ";
    string delNome;
    getline(cin, delNome);

    if (root && root->search(delNome)) {
        root = root->deleteNode(delNome);
        cout << "\n\"" << delNome << "\" removido da árvore AVL.\n";
        lista.deletarPorNome(delNome);
    } else {
        cout << "\nNome \"" << delNome << "\" não encontrado na árvore.\n";
    }

    // opcional: mostrar lista e árvore após remoção
    cout << "\n📋 Lista após remoção:\n";
    lista.imprimir();

    cout << "\n Lista em ordem:\n";

    root->inOrder();
    delete root;
    return 0;
}