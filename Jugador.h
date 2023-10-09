#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include "list"
#include "Territorio.h"
#include "Carta.h"

using namespace std;
class Jugador {
protected:
    string nombre;
    int id_jugador;
    string color;
    list<Territorio*> territoriosOcupados;
    list<Carta> cartas;
public:
    //Constructores
    Jugador() = default;
    Jugador(const string &nombre, int idJugador, const string &color);

    //Getters y Setters
    const string &getNombre() const;
    void setNombre(const string &nombre);
    int getIdJugador() const;
    void setIdJugador(int idJugador);
    const string &getColor() const;
    void setColor(const string &color);
    list<Territorio *> &getTerritoriosOcupados();
    void setTerritoriosOcupados(const list<Territorio *> &territoriosOcupados);
    const list<Carta> &getCartas() const;
    void setCartas(const list<Carta> &cartas);

    //Sobrecarga operadores
    Jugador& operator=(const Jugador &other);

    //Demas funciones
    void agregarCarta(Carta& carta);
    list<Carta>::const_iterator eliminarCarta(std::list<Carta>::const_iterator iterador);





};


#endif //JUGADOR_H
