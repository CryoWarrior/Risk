#pragma once

#ifndef COMANDOS_H
#define COMANDOS_H

#include "string"
#include <vector>
#include "Risk.h"

using namespace std;

class Comandos {
public:
    void inicializarJuego(Risk& risk);
    void inicializar(const string& nombre_archivo);
    void turnoJugador(int jugadorId, Risk& risk);
    void salirJuego(Risk& risk);
    void guardarEstadoJuego(Risk& risk, const string &nombreArchivo);
    void guardarEstadoComprimido(Risk& risk,const string &nombreArchivo);
    string costoConquista(Risk& risk, const string &territorio,const vector<string> &territorios);
    string conquistaMasBarata(Risk& risk,const vector<string> &territorios);


    int obtenerNuevasUnidades(Jugador& jugador, Risk& risk);
    int obtenerCantidadTerritoriosOcupados(int jugadorId, const vector<string> &territorios);
    int obtenerUnidadesPorContinentes(int jugadorId);
    int obtenerUnidadesPorCartas(int jugadorId); 
    vector <string> obtenerTerritoriosJugador(int jugadorId, const vector<string> &territorios);
    int obtenerPropietarioTerritorio(const string &territorio, const vector<string> &territorios);
    vector<int> lanzarDados(int cantidad);
    vector<int> calcularPerdidas(const vector<int>& resultadosA, const vector<int>& resultados);
    void eliminarPerdidas(Territorio& territorio, int infanteria, int caballaria, int artilleria, int valorPerido);
    void eliminarPropiedadConColor(Risk& risk, const string& color, const string& nombreTerritorio);
    static void fortificarPosicion(Jugador& jugador, Risk& risk);
    int intercambiarCartas(Jugador& jugadorActual, Risk& risk);
    int calcularUnidadesExtra(int cartasIntercambiadas, int unidadesExtras);
    int intercambioCartasYTerritorio(Risk& risk, Jugador& jugadorActual,string tropa, int contador);
};


#endif //COMANDOS_H
