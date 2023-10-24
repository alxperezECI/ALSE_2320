#ifndef _PENTAGONO_H
#define _PENTAGONO_H

#include "Geometrica.h"


class Pentagono: public Geometrica {
public: 
    Pentagono(float l, float x=0, float y=0);
    float getLado();
    void setLado(float l);
    float area();
    float perimetro();
    Pentagono(string parametros);
private: 
    float _lado;
    Pentagono();
};

#endif