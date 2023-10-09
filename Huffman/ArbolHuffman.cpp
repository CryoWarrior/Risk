
#include "ArbolHuffman.h"


ArbolHuffman::ArbolHuffman() {}

ArbolHuffman::ArbolHuffman(priority_queue<NodoHuffman*> colaFrecuencia) {
    while (colaFrecuencia.size() > 1) {
        NodoHuffman* izquierdo = colaFrecuencia.top();
        colaFrecuencia.pop();
        NodoHuffman* derecho = colaFrecuencia.top();
        colaFrecuencia.pop();

        NodoHuffman* nodo = new NodoHuffman(izquierdo->getFrecuencia() + derecho->getFrecuencia(), '$');
        nodo->setIzq(izquierdo);
        nodo->setDer(derecho);

        colaFrecuencia.push(nodo);
    }

    raiz = colaFrecuencia.top();
}

NodoHuffman *ArbolHuffman::getRaiz() const {
    return raiz;
}

void ArbolHuffman::setRaiz(NodoHuffman *raiz) {
    ArbolHuffman::raiz = raiz;
}

void ArbolHuffman::generarCodigos(NodoHuffman* nodoHuffman ,string codigo,map<int,string> &caracterYCodigo) {
    if(nodoHuffman == nullptr){
        return;
    }

    if(nodoHuffman->getIzq() == nullptr && nodoHuffman->getDer() == nullptr){
        caracterYCodigo[nodoHuffman->getCodigoSimbolo()] = codigo;
        return;
    }

    generarCodigos(nodoHuffman->getIzq(), codigo+='0',caracterYCodigo);
    generarCodigos(nodoHuffman->getDer(),codigo+='1',caracterYCodigo);
}
