/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <string>
#include <mutex>
#include <pthread.h>
#include <queue>
#include "Escrava.h"
#include "PoolDeEscrava.cpp"
//#include "Fila.cpp"

using namespace std;

#define PORT 8080


class Servidor {
    Fila* f;

public:

    int tamanhoBuffer = 1024;

    

    Servidor(Fila* fila) {
        f = fila;
    }

    int iniciar() {

        int server_fd, new_socket, valread;
        struct sockaddr_in address;
        int opt = 1;
        int addrlen = sizeof(address);
        char buffer[tamanhoBuffer] = {0};

        std::string mensagem = "Hello from server";
        const char *vetor = mensagem.c_str();

        // Creating socket file descriptor
        if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
            perror("socket failed");
            exit(EXIT_FAILURE); 
        }

        // Forcefully attaching socket to the port 8080
        if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
            perror("setsockopt");
            exit(EXIT_FAILURE);
        }
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(PORT);

        // Forcefully attaching socket to the port 8080
        if(bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
            perror("bind failed");
            exit(EXIT_FAILURE);
        }

        if(listen(server_fd, 3) < 0) {
            perror("listen");
            exit(EXIT_FAILURE);
        }

        while(true) {
            if((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
                perror("accept");
                exit(EXIT_FAILURE);
            }



            bool inseriu = f->inserir(new_socket);

            if(!inseriu){
                char resp[] = "Servidor muito requisitado, tente novamente mais tarde.";
                send(new_socket, resp, strlen(resp), 0);
            }

        }

        return 0;
    }

};


int main(int argc, char** argv) {
    Fila *f = new Fila(1);
    
    Servidor *servidor = new Servidor(f);

    PoolDeEscravas *esc = new PoolDeEscravas(f, 1);

    servidor->iniciar();
    
    printf("Servidor iniciado.\n");

    while(true && false) {

        servidor->iniciar();
    }

    return 0;
}