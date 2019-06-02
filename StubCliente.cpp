#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <string>
#include <vector>
#include "Comunicador.cpp"


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
        //string request = strcat("obterFraseAleatoriaDoAutor>", nomeDoAutor);//monta a atring, caractere '>' separa nome do metodo do parametro
        string request = "obterFraseAleatoriaDoAutor>" + nomeDoAutor;

        string response = Comunicador::response(request); //manda o middeware enviar a string e pega a resposta
        
        //trata a resposta e a retorna
        if(response[0] == '-'){//casos de erros
            if(response[1] == '1'){ 
                return "Erro, autor desconhecido pelo sistema.";
            }
            else if(response[1] == '4'){ //-2, erro ao abrir arquivo no servidor
                //vector<string> v{"Erro, Erro, problemas ao se conectar ao servidor"};
                //return v;
                
                //cout << "deu ruim aqui";
                cout << "[!] Erro: " << response << "\n";
                return "";
            }
            //colocar aqui os tratamentos para os outros codigos
        }
        
        else{//caso de acerto
            return response;
        }
	
    }

    vector<string> obterAutores(){
        string request = "obterAutores>";
        string response = Comunicador::response(request);

        //trata a resposta
        if(response[0] == '-'){//casos de erros
            if(response[1] == '1'){ //-1, chegou requisicao desconhecida no servidor
                /*vector<string> v{"Erro no sistema."};
                return v;*/
                
                cout << "[!] Erro no sistema. \n";
                vector<string> v;
                return v;
            }
            if(response[1] == '2'){ //-2, erro ao abrir arquivo no servidor
                /*vector<string> v{"Erro, problemas ao procurar lista de autores no sistema."};
                return v;*/
                
                cout << "[!] Erro, problemas ao procurar lista de autores no sistema. \n";
                vector<string> v;
                return v;
            }
            if(response[1] == '3'){ //-2, erro ao abrir arquivo no servidor
                //vector<string> v{"Erro, Erro, problemas ao se conectar ao servidor"};
                //return v;
                
                cout << "[!] Erro, problemas ao se conectar ao servidor. \n";
                vector<string> v;
                return v;
            }
            if(response[1] == '4'){ //-2, erro ao abrir arquivo no servidor
                //vector<string> v{"Erro, Erro, problemas ao se conectar ao servidor"};
                //return v;
                
                cout << "[!] Erro: " << response << "\n";
                vector<string> v;
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

