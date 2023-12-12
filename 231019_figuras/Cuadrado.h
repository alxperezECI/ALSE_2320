#ifndef _CUADRADO_H
#define _CUADRADO_H

#include "Geometrica.h"


class Cuadrado: public Geometrica{
public: 
    Cuadrado(float l, float x=0, float y=0);
    float getLado();
    void setLado(float l);
    float area();
    float perimetro();
    Cuadrado(string parametros);
    string queSoy();
protected: 
    float _lado;
private:
Cuadrado();
};

#endif