
#ifndef MAIN_CPP_NODOHUFFMAN_H
#define MAIN_CPP_NODOHUFFMAN_H

#include <string>

class NodoHuffman {
protected:
    NodoHuffman* izq;
    NodoHuffman* der;
    int frecuencia;
    int codigoSimbolo;

public:
    //Getters y Setters
    NodoHuffman *getIzq() const;
    void setIzq(NodoHuffman *izq);
    NodoHuffman *getDer() const;
    void setDer(NodoHuffman *der);
    int getFrecuencia() const;
    void setFrecuencia(int frecuencia);
    int getCodigoSimbolo() const;
    void setCodigoSimbolo(int codigoSimbolo);

};


#endif //MAIN_CPP_NODOHUFFMAN_H
