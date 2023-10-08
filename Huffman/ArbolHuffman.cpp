
#include "ArbolHuffman.h"

NodoHuffman *ArbolHuffman::getRaiz() const {
    return raiz;
}

void ArbolHuffman::setRaiz(NodoHuffman *raiz) {
    ArbolHuffman::raiz = raiz;
}
