#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() 
{
    ifstream arquivo("nomes.txt");  // abre o arquivo para leitura

    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }

    string linha;
    while (getline(arquivo, linha)) {
        cout << " " << linha << endl;
    }

    arquivo.close();  // opcional: é fechado automaticamente ao sair do escopo
    return 0;
}
