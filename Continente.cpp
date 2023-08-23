#include "Continente.h"

const string &Continente::getNombre() const {
    return nombre;
}

void Continente::setNombre(const string &nombre) {
    Continente::nombre = nombre;
}

const list<Territorio> &Continente::getTerritorios() const {
    return territorios;
}

void Continente::setTerritorios(const list<Territorio> &territorios) {
    Continente::territorios = territorios;
}

Continente::Continente(const string &nombre, const list<Territorio> &territorios) : nombre(nombre),
                                                                                    territorios(territorios) {}
