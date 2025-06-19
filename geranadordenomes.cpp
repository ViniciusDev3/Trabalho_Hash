#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

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

    return nomes[i] + " " + sobrenomes[j];
}

int main() 
{
    srand(time(0)); // inicializa a semente de aleatoriedade

    for (int i = 0; i < 100; i++) 
    {
        cout << gerarNome() << endl;
    }

    return 0;
}
