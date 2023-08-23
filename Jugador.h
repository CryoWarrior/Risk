#pragma once

#ifndef JUGADOR_H
#define JUGADOR_H

#include "string"
#include "list"
#include "Territorio.h"
#include "Carta.h"

using namespace std;
class Jugador {
protected:
    string nombre;
    int id_jugador;
    string color;
    list<Territorio> territoriosOcupados;
    list<Carta> cartas;
public:
    const string &getNombre() const;

    void setNombre(const string &nombre);

    int getIdJugador() const;

    void setIdJugador(int idJugador);

    const string &getColor() const;

    void setColor(const string &color);

    list<Territorio> &getTerritoriosOcupados();

    void setTerritoriosOcupados(const list<Territorio> &territoriosOcupados);

    const list<Carta> &getCartas() const;

    void agregarCarta(Carta& carta);

    void eliminarCarta(std::list<Carta>::const_iterator iterador);

    void setCartas(const list<Carta> &cartas);

    Jugador() = default;

    Jugador(const string &nombre, int idJugador, const string &color);

    Jugador& operator=(const Jugador &other);
};


#endif //JUGADOR_H
