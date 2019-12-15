#ifndef ARTISTA_H
#define ARTISTA_H
#include<string>


using namespace std;

class Artista{
    public:

    std::string nombre;
    Artista(std::string _nombre)
    {

        this->nombre = _nombre;
    }


     void imprimir();

};

#endif // ARTISTA_H
