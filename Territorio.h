#ifndef TERRITORIO_H
#define TERRITORIO_H

#include "string"
#include "continente.h"
#include "tropa.h"
#include "list"

using namespace std;
class Territorio {
protected:
    string nombre;
    Continente continente;
    list<Tropa> tropas;
    list<Territorio> territoriosColindantes;

public:
    const string &getNombre() const;

    void setNombre(const string &nombre);

    const Continente &getContinente() const;

    void setContinente(const Continente &continente);

    list<Tropa> &getTropas();

    void setTropas(const list<Tropa> &tropas);

    list<Territorio> &getTerritoriosColindantes();

    void setTerritoriosColindantes(const list<Territorio> &territoriosColindantes);

    Territorio() = default;

    Territorio& operator=(const Territorio &other);


};


#endif //TERRITORIO_H
