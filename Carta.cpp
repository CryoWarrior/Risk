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

Carta::Carta(const string &idCarta, const string &territorio, const string &tropa) : idCarta(idCarta),
                                                                                        territorio(territorio),
                                                                                        tropa(tropa) {}
