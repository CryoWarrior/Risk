#ifndef CARTA_H
#define CARTA_H

#include "string"
#include "Territorio.cpp"
#include "Tropa.cpp"

using namespace std;

class Carta {
protected:
    string idCarta;
    Territorio territorio;
    Tropa tropa;
};


#endif //CARTA_H
