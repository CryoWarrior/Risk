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

list<Tropa> &Territorio::getTropas(){
    return tropas;
}

void Territorio::setTropas(const list<Tropa> &tropas) {
    Territorio::tropas = tropas;
}

list<Territorio> &Territorio::getTerritoriosColindantes() {
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




