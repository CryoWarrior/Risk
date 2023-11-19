
#include "Grafo.h"

 list<VerticeGrafo> &Grafo::getVertices()  {
    return vertices;
}

void Grafo::setVertices(const list<VerticeGrafo> &vertices) {
    Grafo::vertices = vertices;
}

void Grafo::agregarVertice(const VerticeGrafo &vertice) {
    vertices.push_back(vertice);
}
