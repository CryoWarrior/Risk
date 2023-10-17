#include "ArbolHuffman.h"


ArbolHuffman::ArbolHuffman() {}


ArbolHuffman::ArbolHuffman(deque<NodoHuffman*> colaFrecuencia) {
    while (colaFrecuencia.size() > 1) {
        pop_heap(colaFrecuencia.begin(), colaFrecuencia.end(), greater<>());
        NodoHuffman* izquierdo = colaFrecuencia.back();
        colaFrecuencia.pop_back();

        pop_heap(colaFrecuencia.begin(), colaFrecuencia.end(), greater<>());
        NodoHuffman* derecho = colaFrecuencia.back();
        colaFrecuencia.pop_back();


        NodoHuffman* nodo = new NodoHuffman(izquierdo->getFrecuencia() + derecho->getFrecuencia(), '$');
        nodo->setIzq(izquierdo);
        nodo->setDer(derecho);

        colaFrecuencia.push_back(nodo);
        push_heap(colaFrecuencia.begin(),colaFrecuencia.end(),greater<>());
    }

    raiz = colaFrecuencia.back();
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
        if(nodoHuffman->getCodigoSimbolo() != '$'){
            caracterYCodigo[nodoHuffman->getCodigoSimbolo()] = codigo;
            return;
        }
    }

    generarCodigos(nodoHuffman->getIzq(), codigo+='0',caracterYCodigo);
    generarCodigos(nodoHuffman->getDer(),codigo+='1',caracterYCodigo);
}
