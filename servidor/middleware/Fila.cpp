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
#include <unistd.h>


using namespace std;


class Fila {
    queue<int> fila;
    int tamanhoMax;

    pthread_mutex_t mutexGeral, mutexRetirada;
    pthread_cond_t cond;

public:

    Fila(int tamanho) {
      tamanhoMax = tamanho;
      pthread_mutex_init(&mutexGeral, NULL);
      pthread_mutex_init(&mutexRetirada, NULL);
      pthread_cond_init(&cond, NULL);
    }

    int retirar(int numero) {
        printf("Thread: %d vai tentar mutexRetirada\n", numero);
        pthread_mutex_lock(&mutexRetirada);
        
        printf("Thread: %d passou pelo mutex retirada, vai tentar mutex geral\n", numero);
        pthread_mutex_lock(&mutexGeral);
        printf("Thread: %d passou pelo mutex geral, vai tentar fila\n", numero);
        if(fila.empty()){
            printf("Thread: %d achou fila vazia, vai pegar cond\n", numero);
            pthread_cond_wait(&cond, &mutexGeral);
            printf("Thread: %d foi acordada\n", numero);
        } 
  
        int retorno = fila.front();
        fila.pop();

        printf("Thread: %d pegou socket e vai liberar mutexs\n", numero);
        pthread_mutex_unlock(&mutexGeral);
        pthread_mutex_unlock(&mutexRetirada);
        return retorno;    
    }


    bool inserir(int socket){
        pthread_mutex_lock(&mutexGeral);

        printf("Servidor inserindo\n");
        if(fila.size() >= tamanhoMax){
            printf("Servidor vai acordar\n");
            pthread_mutex_unlock(&mutexGeral);
            pthread_cond_signal(&cond);
            return false;
        }
        
        fila.push(socket);
        

        pthread_mutex_unlock(&mutexGeral);

        printf("Servidor vai acordar\n");
        pthread_cond_signal(&cond);
        return true;

    }


};


