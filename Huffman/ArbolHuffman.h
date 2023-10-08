#ifndef MAIN_CPP_ARBOLHUFFMAN_H
#define MAIN_CPP_ARBOLHUFFMAN_H

#include "NodoHuffman.h"

class ArbolHuffman {
protected:
    NodoHuffman* raiz;
    int cantidadDeCaracteres;

public:
    NodoHuffman *getRaiz() const;
    void setRaiz(NodoHuffman *raiz);
};


#endif //MAIN_CPP_ARBOLHUFFMAN_H
