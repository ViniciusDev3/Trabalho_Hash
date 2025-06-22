#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

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

		void preOrder() 
		{
			cout << data << " ";
			if (left) left->preOrder();
			if (right) right->preOrder();
		}

		void inOrder() 
		{
			if (left) left->inOrder();
			cout << data << " ";
			if (right) right->inOrder();
		}

		void postOrder() 
		{
			if (left) left->postOrder();
			if (right) right->postOrder();
			cout << data << " ";
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

		string getMin() 
		{
			if (!left) return data;
			return left->getMin();         
		}

		string getMax() 
		{
			if (!right) return data;
			return right->getMax();
		}

		int countNodes() 
		{
			int count = 1;
			if (left)
				count += left->countNodes();
			if (right)
				count += right->countNodes();
			return count;
		}

		int countLeaves() 
		{
			if (!left && !right)
				return 1;
			int leaves = 0;
			if (left)
				leaves += left->countLeaves();
			if (right)
				leaves += right->countLeaves();
			return leaves; 
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

int main() 
{
  TreeNode* root = nullptr;
  srand(time(0));

  for(int i = 0; i < 3000; i++)
  {
    string nome = gerarNome();  // Gera o nome UMA vez
        
    if(root == nullptr)
      root = new TreeNode(nome);
    else
    	root = root->insert(nome);  // Atualiza root com o novo nó se necessário
  }

	cout << "AVL de strings\n";
	root->printTree();

    // Remoção interativa
    cout << "\nDigite um nome completo para deletar (ex: Felipe Carvalho): ";
    string deleteValue;
    getline(cin, deleteValue);

	if (root->search(deleteValue)) 
	{
		root = root->deleteNode(deleteValue);
		cout << "\n\"" << deleteValue << "\" removido com sucesso!\n\n";
	} 
	else 
	{
		cout << "\nNome \"" << deleteValue << "\" não encontrado na árvore.\n";
	}

	cout << "\nÁrvore após deletar:\n\n";
	root->printTree();

	cout << "Menor valor: " << root->getMin() << endl;
	cout << "Maior valor: " << root->getMax() << endl;
	cout << "Quantidade total de nós: " << root->countNodes() << "\n";
	cout << "Quantidade de folhas: " << root->countLeaves() << "\n";
	cout << "Nível de Balanceamento: " << root->getBalance() << endl;

	delete root;
	return 0;
}