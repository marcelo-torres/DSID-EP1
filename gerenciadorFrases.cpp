#include <string>
#include <iostream>

#include <fstream>
#include <sstream>

#include <vector>
#include "Frases.cpp"

using namespace std;

class GerenciadorDeFrases: public Frases {

public:

    GerenciadorDeFrases(string caminho){
        this->caminho = caminho;
        this->arquivoDeNomes = caminho + "autores.csv";
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

    string caminho;

    string arquivoDeNomes;

    // Devolve o nome do arquivo em que estao armazenadas as frases de um autor
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

    // Dado um nome de um autor lista as suas frases que estao armazenadas em um arquivo csv
    vector<string> listarFrasesDoAutor(string nomeDoAutor) {
    
        string nomeDoArquivoDeFrases = this->codigoDoArquivo(nomeDoAutor);
    
        ifstream arquivo(this->caminho + nomeDoArquivoDeFrases);
    
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
