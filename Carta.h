#pragma once

#ifndef CARTA_H
#define CARTA_H


#include <string>

using namespace std;

class Carta {
protected:
    string idCarta;
    string territorio;
    string tropa;
public:
    //Constructores
    Carta() = default;
    Carta(const string &idCarta, const string &territorio, const string &tropa);


    //Getters y Setters
    const string &getIdCarta() const;
    void setIdCarta(const string &idCarta);
    const string &getTerritorio() const;
    void setTerritorio(const string &territorio);
    const string &getTropa() const;
    void setTropa(const string &tropa);

    //Sobrecarga de operadores
    Carta& operator=(const Carta &other);
    bool operator==(const Carta& other) const;
};


#endif //CARTA_H
