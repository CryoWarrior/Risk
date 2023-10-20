#include "ArbolHuffman.h"

ArbolHuffman::ArbolHuffman() {}


ArbolHuffman::ArbolHuffman(deque<NodoHuffman*> heapFrecuencia) {
    while (heapFrecuencia.size() > 1) {
        pop_heap(heapFrecuencia.begin(), heapFrecuencia.end(),NodoHuffman::comparadorNodosHuffman());
        NodoHuffman* izquierdo = heapFrecuencia.back();
        heapFrecuencia.pop_back();

        pop_heap(heapFrecuencia.begin(), heapFrecuencia.end(),NodoHuffman::comparadorNodosHuffman());
        NodoHuffman* derecho = heapFrecuencia.back();
        heapFrecuencia.pop_back();


        NodoHuffman* nodo = new NodoHuffman(izquierdo->getFrecuencia() + derecho->getFrecuencia(), '$');
        nodo->setIzq(izquierdo);
        nodo->setDer(derecho);

        heapFrecuencia.push_back(nodo);
        push_heap(heapFrecuencia.begin(),heapFrecuencia.end(),NodoHuffman::comparadorNodosHuffman());
    }

    raiz = heapFrecuencia.back();
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

