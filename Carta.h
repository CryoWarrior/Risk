#pragma once

#ifndef CARTA_H
#define CARTA_H


#include "string"

using namespace std;

class Carta {
protected:
    string idCarta;
    string territorio;
    string tropa;
public:
    Carta() = default;

    Carta(const string &idCarta, const string &territorio, const string &tropa);

    Carta& operator=(const Carta &other);
};


#endif //CARTA_H
