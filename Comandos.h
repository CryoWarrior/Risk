#ifndef COMANDOS_H
#define COMANDOS_H

#include "string"

using namespace std;

class Comandos {
public:
    void inicializar();
    void inicializar(string nombre_archivo);
    void turno(string id_jugador);
    void salir();
    void guardar(string nombre_archivo);
    void guardar_comprimido(string nombre_archivo);
    string costo_conquista(string terrtorio);
    string conquista_mas_barata();
};


#endif //COMANDOS_H
