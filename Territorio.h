#pragma once


#ifndef TERRITORIO_H
#define TERRITORIO_H

#include "TerritoriosEnum.h"

#include "string"
#include "Tropa.h"
#include "list"

using namespace std;


class Territorio {
protected:
    string nombre;
    list<Tropa> tropas;
    list<Territorio> territoriosColindantes;
    TerritorioEnum territorioEnum;

public:
    const string &getNombre() const;

    void setNombre(const string &nombre);

    list<Tropa> &getTropas();

    void setTropas(const list<Tropa> &tropas);

    list<Territorio> &getTerritoriosColindantes();

    void setTerritoriosColindantes(const list<Territorio> &territoriosColindantes);

    Territorio() = default;

    Territorio(const string &nombre, const list<Tropa> &tropas);

    Territorio(const string &nombre, const list<Tropa> &tropas, TerritorioEnum territorioEnum);

    Territorio& operator=(const Territorio &other);


};


#endif //TERRITORIO_H
