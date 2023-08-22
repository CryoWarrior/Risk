#include "Jugador.h"

const string &Jugador::getNombre() const {
    return nombre;
}

void Jugador::setNombre(const string &nombre) {
    Jugador::nombre = nombre;
}

int Jugador::getIdJugador() const {
    return id_jugador;
}

void Jugador::setIdJugador(int idJugador) {
    id_jugador = idJugador;
}

const string &Jugador::getColor() const {
    return color;
}

void Jugador::setColor(const string &color) {
    Jugador::color = color;
}

list<Territorio> &Jugador::getTerritoriosOcupados() {
    return territoriosOcupados;
}

void Jugador::setTerritoriosOcupados(const list<Territorio> &territoriosOcupados) {
    Jugador::territoriosOcupados = territoriosOcupados;
}

Jugador& Jugador::operator=(const Jugador &other) {
    if (this != &other) {
        nombre = other.nombre;
         id_jugador = other.id_jugador;
         color = other.color;
        territoriosOcupados = other.territoriosOcupados;
        cartas = other.cartas;
    }
    return *this;
}


