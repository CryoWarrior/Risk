#include "Territorio.h"

const string &Territorio::getNombre() const {
    return nombre;
}

void Territorio::setNombre(const string &nombre) {
    Territorio::nombre = nombre;
}

const Continente &Territorio::getContinente() const {
    return continente;
}

void Territorio::setContinente(const Continente &continente) {
    Territorio::continente = continente;
}

const list<Tropa> &Territorio::getTropas() const {
    return tropas;
}

void Territorio::setTropas(const list<Tropa> &tropas) {
    Territorio::tropas = tropas;
}

const list<Territorio> &Territorio::getTerritoriosColindantes() const {
    return territoriosColindantes;
}

void Territorio::setTerritoriosColindantes(const list<Territorio> &territoriosColindantes) {
    Territorio::territoriosColindantes = territoriosColindantes;
}



Territorio& Territorio::operator=(const Territorio &other) {
    if (this != &other) {
        nombre = other.nombre;
        continente = other.continente;
        tropas = other.tropas;
        territoriosColindantes = other.territoriosColindantes;
    }
    return *this;
}




