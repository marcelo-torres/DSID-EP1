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
 
#define PORT 8080 

using namespace std;

class Cliente {

	StubCliente stub;
    
public:

	void metodoInteracaoComUsuario(){
		//...
		// usar deste jeito
		vector<string> v{stub.obterAutores()}; 
		for(string s:v) cout << s << endl;
		//...
	}


};

int main(int argc, char** argv) {
    
    metodoInteracaoComUsuario();
	
    return 0;
}
