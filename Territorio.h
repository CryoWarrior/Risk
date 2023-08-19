#ifndef TERRITORIO_H
#define TERRITORIO_H

#include "string"
#include "continente.cpp"
#include "tropa.h"
#include "list"

using namespace std;
class Territorio {
protected:
    string nombre;
    Continente continente;
    list<Tropa> tropas;
};


#endif //TERRITORIO_H
