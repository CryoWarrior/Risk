#pragma once


#ifndef CONTINENTE_H
#define CONTINENTE_H

#include <string>
#include "list"
#include "Territorio.h"

using namespace std;

class Continente {
protected:
    string nombre;
    list<Territorio*> territorios;
public:
    //Constructores
    Continente() = default;
    Continente(const string &nombre, const list<Territorio *> &territorios);


    //Getters y setters
    const string &getNombre() const;
    void setNombre(const string &nombre);
    list<Territorio *> &getTerritorios();
    void setTerritorios(const list<Territorio *> &territorios);
};


#endif //CONTINENTE_H
