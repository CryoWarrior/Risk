#ifndef CARTA_H
#define CARTA_H

#include "string"
#include "Territorio.h"
#include "Tropa.h"

using namespace std;

class Carta {
protected:
    string idCarta;
    Territorio territorio;
    Tropa tropa;
public:
    Carta() = default;

    Carta& operator=(const Carta &other);
};


#endif //CARTA_H
