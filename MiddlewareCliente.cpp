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

#include <iostream>
 
//#define PORT 8080 
#include "porta.h"

using namespace std;

class MiddlewareCliente {

    
public:

    static string response(string mensagem) { 
    
	    struct sockaddr_in address; 
	    int sock = 0, valread; 
	    struct sockaddr_in serv_addr; 
	    
	    const char *hello = mensagem.c_str(); 
	    char buffer[1024] = {0}; 
	    if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) { 
                //printf("\n Erro ao criar o socket \n"); 
                return "-1"; 
	    } 

	    memset(&serv_addr, '0', sizeof(serv_addr)); 

	    serv_addr.sin_family = AF_INET; 
	    serv_addr.sin_port = htons(PORT); 
	    
	    // Convert IPv4 and IPv6 addresses from text to binary form 
	    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) { 
                //printf("\n Invalid address/ Address not supported \n"); 
                return "-2"; 
	    } 

	    if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) { 
                //printf("\n Não foi possível se conectar ao servidor!\n");
                return "-3"; 
	    }
            
	    send(sock , hello , strlen(hello) , 0 ); 
	    //printf("Hello message sent\n"); 
	    valread = read( sock , buffer, 1024); 
	    //printf("%s\n",buffer ); 

        

		if(buffer[0] == '-' && buffer[1] == '1'){
			return "-4";
		}
		
	    return buffer; 
    }
	


};
