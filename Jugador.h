#ifndef JUGADOR_H
#define JUGADOR_H

#include "string"
#include "list"
#include "Territorio.cpp"

using namespace std;
class Jugador {
protected:
    string nombre;
    int id_jugador;
    string color;
    list<Territorio> territoriosOcupados;
};


#endif //JUGADOR_H
