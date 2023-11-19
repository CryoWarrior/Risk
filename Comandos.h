#pragma once

#ifndef COMANDOS_H
#define COMANDOS_H

#include <string>
#include <vector>
#include "Risk.h"

using namespace std;

class Comandos {
public:
    //Comandos principales
    void inicializarJuego(Risk& risk);
    void inicializarPartidaCargada(Risk &risk, const string& nombre_archivo);
    void turnoJugador(int jugadorId, Risk& risk);
    void salirJuego(Risk& risk);
    void guardarEstadoJuego(Risk& risk, const string &nombreArchivo);
    void guardarEstadoComprimido(Risk& risk,const string &nombreArchivo);
    void costoConquista(Risk &risk, const string &territorio);
    void conquistaMasBarata(Risk& risk, string territorioOrigen);

    //Inicio
    int obtenerNuevasUnidades(Jugador& jugador, Risk& risk);

    //Ataque
    vector<int> lanzarDados(int cantidad);
    vector<int> calcularPerdidas(const vector<int>& resultadosA, const vector<int>& resultados);

    //Fortificacion
    static void fortificarPosicion(Jugador& jugador, Risk& risk);
    void eliminarPerdidas(Territorio*& territorio, int infanteria, int caballaria, int artilleria, int valorPerido);
    void eliminarPropiedadConColor(Risk& risk, const string& color, const string& nombreTerritorio);

    //Cartas
    int intercambiarCartas(Jugador& jugadorActual, Risk& risk);
    int calcularUnidadesExtraCartas(int cartasIntercambiadas, int unidadesExtras);
    int intercambioCartasYTerritorio(Risk& risk, Jugador& jugadorActual,string tropa, int contador);

    //Archivos
    void contarCaracteres(map<int,int> &caracteresYFrecuencias, int &diferentes , string);
    string codificarString(string texto, map<int,string> caracteresYFrecuencias);
    bool leerArchivoTexto(Risk &risk, const string &nombreArchivo);
    bool leerComprimido(Risk &risk, const string &nombreArchivo);
    string decodificarString(const string &codigo, const ArbolHuffman &arbolHuffman);
    bool cargarFrecuenciasDesdeArchivo(ifstream& archivo, map<int,int>& conteoCaracteres);

    //Operaciones en bits
    char crearMascara(int posicion);
    char obtenerByte(string unByte);
    vector<char> convertirBits(string bytesCadena);

    char extraerBit(char y, int posicion);
    string extraerBits (char c);
    string extraerBitsDeBytes(vector<char> bytes);


    //Buscar Camino territorio
    bool verificarTerritorio(Risk& risk, string nombreTerritorio);
    vector<int> calcularPerdidasEntreTerritorios(Territorio* origen, Territorio* destino);
    bool territorioNoJugador(Jugador& jugador, string nombreTerritorio);
    vector<string> obtenerCamino(map<string, map<string, string>>& matrizPredecesores,const string& inicio, const string& fin);
    int  eliminarTropasPropiasDeCamino(Jugador& jugador, vector<string> listaTerritorios, int tropasTotales);
    };


#endif //COMANDOS_H
