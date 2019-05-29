#include <stdio.h> 
#include <string.h>
#include <string>
#include "gerenciadorFrases.cpp"
#include <vector>
 
#define PORT 8080 

using namespace std;

class StubServidor {

    GerenciadorDeFrases gerenciador = new GerenciadorDeFrases();

    const vector<string> explode(const string& s, const char& c) //metodo split, copiado da net
    {
        string buff{""};
        vector<string> v;
        
        for(auto n:s)
        {
            if(n != c) buff+=n; else
            if(n == c && buff != "") { v.push_back(buff); buff = ""; }
        }
        if(buff != "") v.push_back(buff);
        
        return v;
    }

    

    
public:

    //metodo que recebe a string que veio do stub do cliente e verifica qual metodo chamar
    string reesponse(string request){ 
        vector<string> vetor{explode(request, '>')};//separa metodo de parametro, na string

        if(vetor[0] && vetor[0] == "obterAutores"){//metodo obter autores (não tem parametro)
            
            string resp{""};
            vector<string> aux = gerenciador.obterAutores();
            for(string n: aux){//tranforma vetor em string
                resp += n+'|';//padrao do nosso ep, cada elemento do vetor separado por '|';
            }

            return resp;
        }
        else if(vetor[0] = "obterFraseAleatoriaDoAutor"){
            if(vetor[1]){
                return gerenciador.obterFraseAleatoriaDoAutor(vetor[1]);
            }
        }
        else{ //string fora dos padroes ou metodo não reconhecido
            return "-1|requeisição desoconhecida"; //requeisição desoconhecida
        }
	
    }



};

