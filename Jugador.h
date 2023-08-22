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

    Jugador() = default;

    Jugador& operator=(const Jugador &other);
};


#endif //JUGADOR_H
