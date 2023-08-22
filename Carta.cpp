using namespace std;
#include "Carta.h"

Carta& Carta::operator=(const Carta &other) {
    if (this != &other) {
        idCarta = other.idCarta;
        territorio = other.territorio;
        tropa = other.tropa;
    }
    return *this;
}