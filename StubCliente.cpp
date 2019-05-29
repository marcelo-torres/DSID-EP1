#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <string>
#include "MiddlewareCliente.cpp"


using namespace std;

class StubCliente {

    const vector<string> explode(const string& s, const char& c)
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

    string obterFraseAleatoriaDoAutor(string nomeDoAutor){
        char* request = strcat("obterFraseAleatoriaDoAutor>", nomeDoAutor);//monta a atring, caractere '>' separa nome do metodo do parametro

        string response = MiddlewareCliente.response(request); //manda o middeware enviar a string e pega a resposta
        
        //trata a resposta e a retorna
        if(response[0] == '-'){//casos de erros
            if(response[1] == '1'){ 
                return "Erro, autor desconhecido pelo sistema.";
            }
            //colocar aqui os tratamentos para os outros codigos
        }
        
        else{//caso de acerto
            return response;
        }
	
    }

    vector<string> obterAutores(){
        char* request = "obterAutores>";
        string response = MiddlewareCliente.response(request);

        //trata a resposta
        if(response[0] == '-'){//casos de erros
            if(response[1] == '1'){ //-1, chegou requisicao desconhecida no servidor
                vector<string> v{"Erro no sistema."};
                return v; 
            }
            if(response[1] == '2'){ //-2, erro ao abrir arquivo no servidor
                vector<string> v{"Erro, problemas ao procurar lista de autores no sistema."};
                return v;
            }
            //colocar aqui os outros cassos de erro com ifs e corrigir o codigo do primeiro, caso necessário
        }
        
        else{//caso de acerto
            vector<string> v{explode(response, '|')};
            return v;
        }
    }

};

