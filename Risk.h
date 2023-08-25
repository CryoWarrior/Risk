#pragma once

#ifndef RISK_H
#define RISK_H

#include "list"
#include "vector"
#include "Tropa.h"
#include "Continente.h"
#include "Jugador.h"
#include "Carta.h"
#include "Territorio.h"

using namespace std;
class Risk {
protected:
    vector<Continente> listaContinentes;
    vector<Carta> listaCartas;
    list<Jugador> listaJugadores;
    list<Territorio> listaTerritorios;
    int currentTurn;
    int cartasIntercambiadas;
    bool isGameInitialized = false;
    bool isGameOver = false;


public:
    Risk();

    vector<Continente> &getListaContinentes();

    void setListaContinentes(const vector<Continente> &listaContinentes);

    vector<Carta> &getListaCartas();

    void setListaCartas(const vector<Carta> &listaCartas);

    list<Jugador> &getListaJugadores();

    void setListaJugadores(const list<Jugador> &listaJugadores);

    list<Territorio> &getListaTerritorios();

    void setListaTerritorios(const list<Territorio> &listaTerritorios);

    int getCurrentTurn() const;

    void setCurrentTurn(int currentTurn);

    bool isGameInitialized1() const;

    void setIsGameInitialized(bool isGameInitialized);

    bool isGameOver1() const;

    void setIsGameOver(bool isGameOver);

    int getCartasIntercambiadas() const;

    void setCartasIntercambiadas(int cartasIntercambiadas);

    void eliminarUltimaCarta();
};

#endif //RISK_H
