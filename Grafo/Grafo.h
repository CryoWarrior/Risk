
#ifndef MAIN_CPP_GRAFO_H
#define MAIN_CPP_GRAFO_H

#include <list>
#include "VerticeGrafo.h"

class Grafo {
protected:
    list<VerticeGrafo> vertices;

public:
    list<VerticeGrafo> &getVertices() ;
    void setVertices(const list<VerticeGrafo> &vertices);
    void agregarVertice(const VerticeGrafo& vertice);

};

#endif //MAIN_CPP_GRAFO_H
