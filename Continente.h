#ifndef CONTINENTE_H
#define CONTINENTE_H

#include "string"
#include "list"
#include "Territorio.h"

using namespace std;

class Continente {
protected:
    string nombre;
    list<Territorio> territorios;
};


#endif //CONTINENTE_H
