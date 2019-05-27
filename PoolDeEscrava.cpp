

#include <string>
//#include "Fila.cpp"

#define TAMANHO_BUFFER 1024

using namespace std;

class PoolDeEscravas{

    Fila* f;
    Escrava** threads;
    int quantidade;

public:

    PoolDeEscravas(Fila* fila, int quantidade){
        
        this->f = fila;
        quantidade = quantidade;
        threads = new Escrava*[quantidade];
        
        int i;
        for(i = 0; i < quantidade; i++){
            threads[i] = new Escrava(f, i);
            threads[i]->start();
        }

    }

};