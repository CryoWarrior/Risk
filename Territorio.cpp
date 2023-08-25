#include "Territorio.h"

const string &Territorio::getNombre() const {
    return nombre;
}

void Territorio::setNombre(const string &nombre) {
    Territorio::nombre = nombre;
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
        tropas = other.tropas;
        territoriosColindantes = other.territoriosColindantes;
    }
    return *this;
}

Territorio::Territorio(const string &nombre, const list<Tropa> &tropas) : nombre(nombre), tropas(tropas) {}


Territorio::Territorio(const string &nombre, const list<Tropa> &tropas, TerritorioEnum territorioEnum)
        : nombre(nombre), tropas(tropas), territorioEnum(territorioEnum){}




