// Client side C/C++ program to demonstrate Socket programming 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 

#include <unistd.h>
#include <fcntl.h>

#include <netinet/in.h>
#include <arpa/inet.h>

#include <string.h>
#include <string>
#include "StubCliente.cpp"

#include <iostream>
 
#define PORT 8080 

using namespace std;

class Cliente {

	StubCliente stub;
    
public:

	void metodoInteracaoComUsuario(){
		
		
		StubCliente stub;  
        vector<string> autores = stub.obterAutores(); // RPC
        
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
        string frase = stub.obterFraseAleatoriaDoAutor(autor); // RPC
        
        cout << "\nFRASE:\n" << frase << " -" << autor << "\n\n";
	}


};

int main(int argc, char** argv) {
    
    Cliente cliente;
    
    cliente.metodoInteracaoComUsuario();
	
    return 0;
}
