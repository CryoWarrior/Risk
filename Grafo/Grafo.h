
#ifndef MAIN_CPP_GRAFO_H
#define MAIN_CPP_GRAFO_H

#include <list>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <limits>
#include "VerticeGrafo.h"

class Grafo {
protected:
    list<VerticeGrafo> vertices;

    struct CaminoInfo {
        int cantidadTropas;
        vector<string> camino;
    };

public:
    list<VerticeGrafo> &getVertices() ;
    void setVertices(const list<VerticeGrafo> &vertices);
    void agregarVertice(const VerticeGrafo& vertice);

    pair<int,vector<string>> encontrarCaminoMinimo(const string& inicio, const string& objetivo);
    VerticeGrafo& encontrarVertice(string nombre);
    list<VerticeGrafo*> obtenerVecinos(string nombre);
    pair<map<string, map<string, int>>, map<string, map<string, string>>> floydWarshall();
};

#endif //MAIN_CPP_GRAFO_H
