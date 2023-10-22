#ifndef MAIN_CPP_ARBOLHUFFMAN_H
#define MAIN_CPP_ARBOLHUFFMAN_H

#include "NodoHuffman.h"
#include <vector>
#include <map>
#include <queue>
#include <fstream>
#include <exception>




using namespace std;
class ArbolHuffman{
protected:

    NodoHuffman* raiz;
    int cantidadDeCaracteres;

public:
    //Constructor
    struct customComparator;
    ArbolHuffman();
    ArbolHuffman(deque<NodoHuffman*> colaFrecuencia);

    //Getters y setters
    NodoHuffman *getRaiz() const;
    void setRaiz(NodoHuffman *raiz);

    //Demas funciones
    void generarCodigos(NodoHuffman* nodoHuffman, string codigo,map<int,string> &);

};
#endif //MAIN_CPP_ARBOLHUFFMAN_H
