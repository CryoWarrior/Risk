#include "Tropa.h"

const string &Tropa::getTipoTropa() const {
    return tipoTropa;
}

void Tropa::setTipoTropa(const string &tipoTropa) {
    Tropa::tipoTropa = tipoTropa;
}

int Tropa::getValorTropa() const {
    return valorTropa;
}

void Tropa::setValorTropa(int valorTropa) {
    Tropa::valorTropa = valorTropa;
}

const string &Tropa::getColor() const {
    return color;
}

void Tropa::setColor(const string &color) {
    Tropa::color = color;
}
