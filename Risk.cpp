#include "Risk.h"

 vector<Continente> &Risk::getListaContinentes()  {
    return listaContinentes;
}

void Risk::setListaContinentes(const vector<Continente> &listaContinentes) {
    Risk::listaContinentes = listaContinentes;
}

 vector<Tropa> &Risk::getListaTropas()  {
    return listaTropas;
}

void Risk::setListaTropas(const vector<Tropa> &listaTropas) {
    Risk::listaTropas = listaTropas;
}

 vector<Carta> &Risk::getListaCartas()  {
    return listaCartas;
}

void Risk::setListaCartas(const vector<Carta> &listaCartas) {
    Risk::listaCartas = listaCartas;
}

 list<Jugador> &Risk::getListaJugadores()  {
    return listaJugadores;
}

void Risk::setListaJugadores(const list<Jugador> &listaJugadores) {
    Risk::listaJugadores = listaJugadores;
}

list<Territorio> &Risk::getListaTerritorios() {
    return listaTerritorios;
}

void Risk::setListaTerritorios(const list<Territorio> &listaTerritorios) {
    Risk::listaTerritorios = listaTerritorios;
}

Risk::Risk() {}
