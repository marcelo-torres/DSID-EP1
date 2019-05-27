
#include <string>
#include <iostream>

#include <fstream>
#include <sstream>

#include <vector>
#include <list> 
#include <iterator> 

using namespace std;

#warning Apagar essa funcao antes de enviar
void showlist(list <string> g) 
{ 
    list <string> :: iterator it; 
    for(it = g.begin(); it != g.end(); ++it) 
        cout << '\t' << *it; 
    cout << '\n'; 
} 

class GerenciadorDeFrases {

public:

    // Devolve uma lista de strings com os nomes de todos os autores
    list<string> obterAutores() {
    
        list<string> listaDeNomes;
        
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
        
        cout << "Foi sorteado: " << indiceFraseSorteada << "\n";
        
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



int main() {
 
    GerenciadorDeFrases g;
    
    showlist(g.obterAutores());
    
    string n = g.obterFraseAleatoriaDoAutor("Paulo Freire");
    cout << n << "\n";
    

    return 0;
}








