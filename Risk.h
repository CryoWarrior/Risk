#ifndef RISK_H
#define RISK_H

#include "list"
#include "vector"
#include "Tropa.cpp"
#include "Continente.cpp"
#include "Jugador.cpp"
#include "Carta.cpp"

using namespace std;
class Risk {
protected:
    vector<Continente> listaContinentes;
    vector<Tropa> listaTropas;
    vector<Carta> listaCartas;
    list<Jugador> listaJugadores;
};


#endif //RISK_H
