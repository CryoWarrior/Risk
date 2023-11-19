#ifndef MAIN_CPP_VERTICEGRAFO_H
#define MAIN_CPP_VERTICEGRAFO_H

#include <map>
#include "../Territorio.h"
class VerticeGrafo {
protected:
    Territorio* dato;
    map<string,int> paisesColindantes;
public:
    //Constructor
    VerticeGrafo();
    explicit VerticeGrafo(Territorio *dato);
    VerticeGrafo(Territorio *dato, const map<string,int> &paisesColindantes);


    //Getters and Setters
    Territorio *getDato() ;
    void setDato(Territorio *dato);
    const map<string,int> &getPaisesColindantes() const;
    void setPaisesColindantes(const map<string,int> &paisColindante);
    void agregarPaisColidante(const string& nombrePais, int valorTropas);


};


#endif //MAIN_CPP_VERTICEGRAFO_H
