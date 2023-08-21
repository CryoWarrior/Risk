#ifndef COMANDOS_H
#define COMANDOS_H

#include "string"
#include <vector>

using namespace std;

class Comandos {
private:
    bool isGameInitialized = false;
    bool isGameOver = false;
    int currentTurn = 1;

public:
    void inicializarJuego();
    void inicializar(string nombre_archivo);
    void turnoJugador(int jugadorId);
    void salirJuego();
    void guardarEstadoJuego(const string &nombreArchivo);
    void guardarEstadoComprimido(const string &nombreArchivo);
    string costoConquista(const string &territorio,const vector<string> &territorios);
    string conquistaMasBarata(const vector<string> &territorios);
    bool getIsGameInitialized() const; 
    void setIsGameInitialized(bool value); 
    bool getIsGameOver() const; 
    void setIsGameOver(bool value);  
    int obtenerNuevasUnidades(int jugadorId);
    int obtenerCantidadTerritoriosOcupados(int jugadorId, const vector<string> &territorios);
    int obtenerUnidadesPorContinentes(int jugadorId);
    int obtenerUnidadesPorCartas(int jugadorId); 
    vector <string> obtenerTerritoriosJugador(int jugadorId, const vector<string> &territorios);
    int obtenerPropietarioTerritorio(const string &territorio, const vector<string> &territorios);
};


#endif //COMANDOS_H