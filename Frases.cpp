#include <string>

class Frases {
public:
    virtual vector<string> obterAutores() = 0;
    virtual string obterFraseAleatoriaDoAutor(string nomeDoAutor) = 0;
};
