#ifndef _TRIANGULO_H
#define _TRIANGULO_H

#include "Geometrica.h"


class Triangulo: public Geometrica {
public: 
    Triangulo(float b, float h, float x=0, float y=0);
    float getBase();
    void setBase(float b);
    float getAltura();
    void setAltura(float h);
    float area();
    float perimetro();
    Triangulo(string parametros);
private: 
    float _base;
    float _altura;
    
    Triangulo();
};

#endif //_TRIANGULO_H