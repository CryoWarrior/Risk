// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN
// This includes the catch.hpp file
#include "Librerias/catch.hpp"
#include "Comandos.h"
#include "Risk.h"

#include <fstream>
#include <iostream>
#include <string>

// Include the header file of the class that you are testing
void inicializarJuegoQuemado(Risk &risk);

TEST_CASE("Pruebas grafos"){
    SECTION("Costo Conquista"){

        Risk risk = Risk();
        inicializarJuegoQuemado(risk);

        Comandos comandos;
        string resultado = comandos.costoConquista(risk, "India");

        REQUIRE(resultado == "hola");
    }
}



void inicializarJuegoQuemado(Risk &risk) {
    risk.setIsGameInitialized(true);


    Jugador jugador1;
    jugador1.setIdJugador(1);
    jugador1.setNombre("Cami");
    jugador1.setColor("azul");

    Jugador jugador2;
    jugador2.setIdJugador(2);
    jugador2.setNombre("Ale");
    jugador2.setColor("rojo");

    Jugador jugador3;
    jugador3.setIdJugador(3);
    jugador3.setNombre("Ripa");
    jugador3.setColor("negro");

    risk.getListaJugadores().push_back(jugador1);
    risk.getListaJugadores().push_back(jugador2);
    risk.getListaJugadores().push_back(jugador3);

    list<Territorio *> territoriosDisponibles;

    for (auto territorio: risk.getListaTerritorios()) {
        territoriosDisponibles.push_back(territorio.get());
    }

    auto iterterritoriosDisponibles = territoriosDisponibles.begin();

    auto iterJugadorActual = risk.getListaJugadores().begin();
    while (!territoriosDisponibles.empty()) {

        Jugador &jugadorActual = *iterJugadorActual;
        Territorio &territorioActual = **iterterritoriosDisponibles;

        Tropa infanteria("Infanteria", 1, jugadorActual.getColor());
        territorioActual.getTropas().push_back(infanteria);

        iterterritoriosDisponibles = territoriosDisponibles.erase(iterterritoriosDisponibles);


        ++iterJugadorActual;
        if (iterJugadorActual == risk.getListaJugadores().end()) {
            iterJugadorActual = risk.getListaJugadores().begin();
        }
    }

    risk.setCurrentTurn(risk.getListaJugadores().front().getIdJugador());

}