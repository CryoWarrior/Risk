
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
    //Constructores
    NodoHuffman();
    NodoHuffman(int frecuencia, int codigoSimbolo);

    //Getters y Setters
        NodoHuffman *getIzq() const;
        void setIzq(NodoHuffman *izq);
        NodoHuffman *getDer() const;
        void setDer(NodoHuffman *der);
        int getFrecuencia() const;
        void setFrecuencia(int frecuencia);
        int getCodigoSimbolo() const;
        void setCodigoSimbolo(int codigoSimbolo);

    //Sobrecarga operadores
    bool operator<(const NodoHuffman &other) const;
    bool operator>(const NodoHuffman &other) const;
    bool esHoja();

    struct comparadorNodosHuffman {
        bool operator()( NodoHuffman* lhs,  NodoHuffman* rhs) const {
            return lhs->frecuencia > rhs->frecuencia;
        }
    };

};


#endif //MAIN_CPP_NODOHUFFMAN_H
