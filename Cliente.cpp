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
		for(string s:v){
			int n = s.length(); 
            char resp[n + 1]; 
            strcpy(resp, s.c_str()); 
			printf("%s\n",resp);
		} 
		//...
	}


};

int main(int argc, char** argv) {
    Cliente c;

    c.metodoInteracaoComUsuario();
	
    return 0;
}
