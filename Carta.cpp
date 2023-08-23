#include "Carta.h"

Carta& Carta::operator=(const Carta &other) {
    if (this != &other) {
        idCarta = other.idCarta;
        territorio = other.territorio;
        tropa = other.tropa;
    }
    return *this;
}

Carta::Carta(const string &idCarta, const string &territorio, const string &tropa) : idCarta(idCarta),
                                                                                        territorio(territorio),
                                                                                        tropa(tropa) {}

const string &Carta::getIdCarta() const {
    return idCarta;
}

void Carta::setIdCarta(const string &idCarta) {
    Carta::idCarta = idCarta;
}

const string &Carta::getTerritorio() const {
    return territorio;
}

void Carta::setTerritorio(const string &territorio) {
    Carta::territorio = territorio;
}

const string &Carta::getTropa() const {
    return tropa;
}

void Carta::setTropa(const string &tropa) {
    Carta::tropa = tropa;
}

bool Carta::operator==(const Carta &other) const {
    return (idCarta == other.idCarta) &&
    (territorio == other.territorio) &&
    (tropa == other.tropa);
}
