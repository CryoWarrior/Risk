
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


pair<int,vector<string>> Grafo::encontrarCaminoMinimo(const string& inicio, const string& objetivo) {
    queue<string> cola;
    unordered_set<string> visitados;
    unordered_map<string, CaminoInfo> caminos;

    cola.push(inicio);
    visitados.insert(inicio);
    caminos[inicio] = {0, {inicio}};

    while (!cola.empty()) {
        string territorioActual = cola.front();
        cola.pop();

        for (VerticeGrafo *vecino: obtenerVecinos(territorioActual)) {
            string nombreVecino = vecino->getDato()->getNombre();

            if (visitados.find(nombreVecino) == visitados.end()) {
                cola.push(nombreVecino);
                visitados.insert(nombreVecino);

                CaminoInfo nuevoCamino = caminos[territorioActual];
                nuevoCamino.cantidadTropas += vecino->getDato()->contarTropas();
                nuevoCamino.camino.push_back(nombreVecino);

                caminos[nombreVecino] = nuevoCamino;
            }
        }
    }

    // Comprobamos si se encontró un camino al objetivo
    if (caminos.find(objetivo) != caminos.end()) {
        //return caminos[objetivo];
        return make_pair(caminos[objetivo].cantidadTropas, caminos[objetivo].camino) ;
    } else {
        // No se encontró un camino al objetivo
        return {numeric_limits<int>::max(), {}};
    }
}

map<string, map<string, int>>  Grafo::floydWarshall() {
    map<string, map<string, int>> matrizDistancias;
    map<string, map<string, string>> matrizPredecesores;


    // Inicializar matrizDistancias con los valores de los vértices directos
    for (VerticeGrafo& v : vertices) {
        string nombreV = v.getDato()->getNombre();
        matrizDistancias[nombreV][nombreV] = 0;
        matrizPredecesores[nombreV][nombreV] = nombreV;


        for (const auto& vecino : v.getPaisesColindantes()) {
            matrizDistancias[nombreV][vecino.first] = vecino.second;
        }
    }

    // Aplicar el algoritmo de Floyd-Warshall
    for (VerticeGrafo& k : vertices) {
        for (VerticeGrafo& i : vertices) {
            for (VerticeGrafo& j : vertices) {
                string nombreI = i.getDato()->getNombre();
                string nombreJ = j.getDato()->getNombre();
                string nombreK = k.getDato()->getNombre();

                if (matrizDistancias[nombreI][nombreK] + matrizDistancias[nombreK][nombreJ] < matrizDistancias[nombreI][nombreJ]
                    && matrizDistancias[nombreI][nombreK] != numeric_limits<int>::max()
                    && matrizDistancias[nombreK][nombreJ] != numeric_limits<int>::max())
                {
                    matrizDistancias[nombreI][nombreJ] = matrizDistancias[nombreI][nombreK] + matrizDistancias[nombreK][nombreJ];
                    matrizPredecesores[nombreI][nombreJ] = matrizPredecesores[nombreK][nombreJ];
    
                }
            }
        }
    }
    return matrizDistancias;
}

VerticeGrafo& Grafo::encontrarVertice(string nombre) {

    for(VerticeGrafo& vertice : vertices){
        if(vertice.getDato()->getNombre()==nombre){
            return vertice;
        }
    }
    VerticeGrafo vertice;
    return vertice;
}

list<VerticeGrafo *> Grafo::obtenerVecinos(string nombre) {

    list<VerticeGrafo*> vecinos;
    for(VerticeGrafo verticeGrafo : vertices){
        if(verticeGrafo.getDato()->getNombre() == nombre){
            for(auto Pvecino: verticeGrafo.getPaisesColindantes()){
                string vecino = Pvecino.first;
                vecinos.push_back(&encontrarVertice(vecino));
            }
            break;
        }
    }
    return vecinos;
}

