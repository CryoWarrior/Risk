#ifndef MAIN_CPP_VERTICEGRAFO_H
#define MAIN_CPP_VERTICEGRAFO_H

#include "../Territorio.h"
class VerticeGrafo {
protected:
    Territorio* dato;
    list<string> paisesColindantes;
public:
    //Constructor
    VerticeGrafo();
    explicit VerticeGrafo(Territorio *dato);
    VerticeGrafo(Territorio *dato, const list<string> &paisesColindantes);


    //Getters and Setters
    Territorio *getDato() ;
    void setDato(Territorio *dato);
    const list<string> &getPaisColindante() const;
    void setPaisColindante(const list<string> &paisColindante);
    void agregarPaisColidante(const string& nombrePais);


};


#endif //MAIN_CPP_VERTICEGRAFO_H
