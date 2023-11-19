#include "VerticeGrafo.h"


VerticeGrafo::VerticeGrafo() {}
VerticeGrafo::VerticeGrafo(Territorio *dato) : dato(dato) {}


Territorio *VerticeGrafo::getDato() {
    return dato;
}

void VerticeGrafo::setDato(Territorio *dato) {
    VerticeGrafo::dato = dato;
}

const map<string,int> &VerticeGrafo::getPaisesColindantes() const {
    return paisesColindantes;
}

void VerticeGrafo::setPaisesColindantes(const map<string,int> &paisColindante) {
    VerticeGrafo::paisesColindantes = paisColindante;
}

void VerticeGrafo::agregarPaisColidante(const string& nombrePais, int tropas) {
    VerticeGrafo::paisesColindantes[nombrePais] = tropas;
}

VerticeGrafo::VerticeGrafo(Territorio *dato, const map<string,int> &paisesColindantes) : dato(dato), paisesColindantes(
        paisesColindantes) {}



