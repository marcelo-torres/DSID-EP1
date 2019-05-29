#include <string>
#include <iostream>

#include <fstream>
#include <sstream>

#include <vector>

using namespace std;

class GerenciadorDeFrases {

public:

    GerenciadorDeFrases(){
        
    }

    // Devolve uma lista de strings com os nomes de todos os autores
    vector<string> obterAutores() {
    
        vector<string> listaDeNomes;
        
        ifstream arquivo(this->arquivoDeNomes);

        string nomeDoAutor, codigoDoArquivo;
    
        if(arquivo.is_open()) {
            while(getline(arquivo, nomeDoAutor, ';')) {
                if(getline(arquivo, codigoDoArquivo, '\n')) {
                    listaDeNomes.push_back(nomeDoAutor);
                } else {
                    cout << "[!] Arquivo fora do padrao\n";
                    break;
                }
  
            }
            arquivo.close();
        } else {
            cout << "[!] Nao foi possivel abrir o arquivo: " << this->arquivoDeNomes << "\n";
        }    
    
        return listaDeNomes;
    
    }
    
    // Dado um autor retorna uma frase aleatoria de um autor
    string obterFraseAleatoriaDoAutor(string nomeDoAutor) {
        
        vector<string> listaDeFrases = this->listarFrasesDoAutor(nomeDoAutor);
        int indiceFraseSorteada = this->sortearValor(listaDeFrases.size());
        string fraseSorteada = listaDeFrases.at(indiceFraseSorteada);
        
        return fraseSorteada;
    }
    
private:

    string arquivoDeNomes = "autores.csv";

    string codigoDoArquivo(string nomeDoAutorProcurado) {
    
        ifstream arquivo(this->arquivoDeNomes);
        string nomeDoAutor, codigoDoArquivo;
    
        if(arquivo.is_open()) {
            while(getline(arquivo, nomeDoAutor, ';')) {
                if(getline(arquivo, codigoDoArquivo, '\n')) {
                    if(nomeDoAutor.compare(nomeDoAutorProcurado) == 0) {
                        return codigoDoArquivo;
                    }
                } else {
                    cout << "[!] Arquivo fora do padrao\n";
                    break;
                }
  
            }
            arquivo.close();
        } else {
            cout << "[!] Nao foi possivel abrir o arquivo: " << this->arquivoDeNomes << "\n";
        }   
    
        return "";
    }

    vector<string> listarFrasesDoAutor(string nomeDoAutor) {
    
        string nomeDoArquivoDeFrases = this->codigoDoArquivo(nomeDoAutor);
    
        ifstream arquivo(nomeDoArquivoDeFrases);
    
        vector<string> listaDeFrases;
        
        string frase;
        if(arquivo.is_open()) {
            while(getline(arquivo, frase, '\n')) {
                listaDeFrases.push_back(frase);
            }
            arquivo.close();
        } else {
            cout << "[!] Nao foi possivel abrir o arquivo: " << nomeDoArquivoDeFrases << "\n";
        }
    
        return listaDeFrases;
    }
    
    // Sorteia um numero inteiro entre 0 (inclusivo) e maximo (exclusivo)
    int sortearValor(int maximo) {
        
        srand(time(0));    
        return (rand() % maximo);
    }
};


/*
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
*/







