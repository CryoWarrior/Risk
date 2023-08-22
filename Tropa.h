#ifndef MAIN_CPP_TROPA_H
#define MAIN_CPP_TROPA_H

#include "string"

using namespace std;
class Tropa {
protected:
    string tipoTropa;
    int valorTropa;
    string color;

public:
    const string &getTipoTropa() const;

    void setTipoTropa(const string &tipoTropa);

    int getValorTropa() const;

    void setValorTropa(int valorTropa);

    const string &getColor() const;

    void setColor(const string &color);
};


#endif //MAIN_CPP_TROPA_H
