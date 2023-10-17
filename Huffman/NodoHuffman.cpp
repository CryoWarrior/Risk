#include "NodoHuffman.h"


NodoHuffman::NodoHuffman(){}

NodoHuffman::NodoHuffman(int frecuencia, int codigoSimbolo) : izq(nullptr), der(nullptr), frecuencia(frecuencia),
                                                              codigoSimbolo(codigoSimbolo) {}


NodoHuffman *NodoHuffman::getIzq() const {
    return izq;
}

void NodoHuffman::setIzq(NodoHuffman *izq) {
    NodoHuffman::izq = izq;
}

NodoHuffman *NodoHuffman::getDer() const {
    return der;
}

void NodoHuffman::setDer(NodoHuffman *der) {
    NodoHuffman::der = der;
}

int NodoHuffman::getFrecuencia() const {
    return frecuencia;
}

void NodoHuffman::setFrecuencia(int frecuencia) {
    NodoHuffman::frecuencia = frecuencia;
}

int NodoHuffman::getCodigoSimbolo() const {
    return codigoSimbolo;
}

void NodoHuffman::setCodigoSimbolo(int codigoSimbolo) {
    NodoHuffman::codigoSimbolo = codigoSimbolo;
}

bool NodoHuffman::operator<(const NodoHuffman &other) const {
    return frecuencia < other.frecuencia;
}

bool NodoHuffman::operator>(const NodoHuffman &other) const {
    return frecuencia > other.frecuencia;
}