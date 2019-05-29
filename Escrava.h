#include <pthread.h>

#include <string>
#include "Fila.cpp"
#include "StubServidor.cpp"

#define TAMANHO_BUFFER 1024

using namespace std;

class Escrava{

    Fila* f;
    pthread_t thread;
    int numero;
    

public:

    Escrava(Fila* fila, int tNumero){
        
        this->f = fila;
        this->numero = tNumero;       
        
    }

    void start(){
        long t;

        int resp = pthread_create(&thread, NULL, &Escrava::send_wrapper, (void *)t); 
 
    }

    void limparBuffer(char* buffer) {
        int i;

        for(i = 0; i < TAMANHO_BUFFER; i++) {
            buffer[i] = 0;
        }
    }

    static void* send_wrapper(void* object)
    {
        reinterpret_cast<Escrava*>(object)->printHello(object);
        return 0;
    }

    void printHello(void *threadid)
    {

        int socket;
        int valread;
        char buffer[TAMANHO_BUFFER] = {0};
        char str[] = "Oi do servidor na thread: ";
        StubServidor stub;
        
        char novoId[strlen(str)*2];

        snprintf (novoId, strlen(str)*2, "\n%s%d :)\n", str, numero);
       
        

        while(true){
            limparBuffer(buffer);

            socket = f->retirar(numero);

            printf("\nthread %d pegou socket: %d\n", numero, socket);
            valread = read(socket, buffer, TAMANHO_BUFFER);
            printf("Processando.\n\n");


            string s = stub.response(buffer); //manda pro stub a mensagem e pega a resposta
        
            int n = s.length(); 
        
 
            char resp[n + 1]; 
        
       
            strcpy(resp, s.c_str()); 
            
            

            send(socket, resp, strlen(resp), 0); //envia a resposta pro cliente
            printf("Hello message sent\n\n");
        }
        

        pthread_exit(NULL);
    }
    



};
