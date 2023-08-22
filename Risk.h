#ifndef RISK_H
#define RISK_H

#include "list"
#include "vector"
#include "Tropa.cpp"
#include "Continente.cpp"
#include "Jugador.cpp"
#include "Carta.cpp"
#include "Territorio.cpp"

using namespace std;
class Risk {
protected:
    vector<Continente> listaContinentes;
    vector<Tropa> listaTropas;
    vector<Carta> listaCartas;
    list<Jugador> listaJugadores;
    list<Territorio> listaTerritorios;

public:
    Risk();

    vector<Continente> &getListaContinentes();

    void setListaContinentes(const vector<Continente> &listaContinentes);

    vector<Tropa> &getListaTropas();

    void setListaTropas(const vector<Tropa> &listaTropas);

    vector<Carta> &getListaCartas();

    void setListaCartas(const vector<Carta> &listaCartas);

    list<Jugador> &getListaJugadores();

    void setListaJugadores(const list<Jugador> &listaJugadores);

    list<Territorio> &getListaTerritorios();

    void setListaTerritorios(const list<Territorio> &listaTerritorios);
};


#endif //RISK_H
