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
 
#define PORT 8080 

using namespace std;

class Cliente {

    string response(string request, bool* erro) { 
	    struct sockaddr_in address; 
	    int sock = 0, valread; 
	    struct sockaddr_in serv_addr; 
	    
	    const char *hello = mensagem.c_str(); 
	    char buffer[1024] = {0}; 
	    if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) { 
                //printf("\n Erro ao criar o socket \n"); 
                return NULL; 
	    } 

	    memset(&serv_addr, '0', sizeof(serv_addr)); 

	    serv_addr.sin_family = AF_INET; 
	    serv_addr.sin_port = htons(PORT); 
	    
	    // Convert IPv4 and IPv6 addresses from text to binary form 
	    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) { 
                //printf("\n Invalid address/ Address not supported \n"); 
                *erro = true;
                return NULL; 
	    } 

	    if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) { 
                //printf("\n Não foi possível se conectar ao servidor!\n"); 
                *erro = true;
                return NULL; 
	    }
            
	    send(sock , hello , strlen(hello) , 0 ); 
	    //printf("Hello message sent\n"); 

	    valread = read( sock , buffer, 1024); 
	    //printf("%s\n",buffer ); 

        string s(strlen(buffer), buffer);

	    return s; 
    }

    
    
public:
    vector<string> obterAutores() {
        

    
    }
     

};


