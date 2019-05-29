#include <string>
#include <vector>
#include "gerenciadorFrases.cpp"


using namespace std;

class Responser {

public:


    string response(string request){
        string metodo = request.s
    }

    
private:

    vector<string> vetorRequest(string request){
        string tratada
    } 




    // Devolve uma lista de strings com os nomes de todos os autores
    vector<string> obterAutores() {
        GerenciadorDeFrases gerenciador;
        return gerenciador.obterAutores();
    }
    
    // Dado um autor retorna uma frase aleatoria de um autor
    string obterFraseAleatoriaDoAutor(string nomeDoAutor) {        
        GerenciadorDeFrases gerenciador;        
        return gerenciador.obterFraseAleatoriaDoAutor(nomeDoAutor);
    }


};



int main() {
 
    GerenciadorDeFrases g;  
    vector<string> autores = g.obterAutores();
    
    cout << "Escolha um autor:\n";
    for(int i = 1; i <= autores.size(); i++) {
        cout << "\t" << i << " - " << autores.at(i - 1) << "\n";
    }

    
    bool invalido = true;
    int escolha = -1;
    do {
        cout << "Escolha o número: ";
        cin >> escolha;
        
        invalido = (escolha < 0 || escolha > autores.size());
        
        if(invalido) {
            cout << "[!] Valor invalido! Digite um numero entre 1 e " << autores.size() << "\n";
        }
        
    } while(invalido);
    
    string autor = autores.at(escolha - 1);
    string frase = g.obterFraseAleatoriaDoAutor(autor);
    
    cout << "\nFRASE:\n" << frase << " -" << autor << "\n\n";

    return 0;
}








