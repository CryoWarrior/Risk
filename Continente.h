#pragma once


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
public:
    const string &getNombre() const;

    Continente() = default;

    Continente(const string &nombre, const list<Territorio> &territorios);

    void setNombre(const string &nombre);

    const list<Territorio> &getTerritorios() const;

    void setTerritorios(const list<Territorio> &territorios);
};


#endif //CONTINENTE_H
