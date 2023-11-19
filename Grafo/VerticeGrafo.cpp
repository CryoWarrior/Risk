#include "VerticeGrafo.h"


VerticeGrafo::VerticeGrafo() {}
VerticeGrafo::VerticeGrafo(Territorio *dato) : dato(dato) {}


Territorio *VerticeGrafo::getDato() {
    return dato;
}

void VerticeGrafo::setDato(Territorio *dato) {
    VerticeGrafo::dato = dato;
}

const list<string> &VerticeGrafo::getPaisColindante() const {
    return paisesColindantes;
}

void VerticeGrafo::setPaisColindante(const list<string> &paisColindante) {
    VerticeGrafo::paisesColindantes = paisColindante;
}

void VerticeGrafo::agregarPaisColidante(const string& nombrePais) {
    VerticeGrafo::paisesColindantes.push_back(nombrePais);
}

VerticeGrafo::VerticeGrafo(Territorio *dato, const list<string> &paisesColindantes) : dato(dato), paisesColindantes(
        paisesColindantes) {}



