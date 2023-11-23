#ifndef _GEOMETRICA_H
#define _GEOMETRICA_H

#include <iostream>
using namespace std;

enum fig_G{
    circulo = 1,
    cuadrado,
    triangulo,
    pentagono
};

class Geometrica {
public:
    virtual float area();
    virtual float perimetro();
    virtual void setX(float x);
    virtual float getX();
    virtual void setY(float y);
    virtual float getY();
    virtual float getAngulo();
    virtual void setAngulo(float a);
    virtual string queSoy();
    friend ostream& operator<<(ostream& stream, Geometrica& g);
    Geometrica();
    virtual ~Geometrica();
    fig_G getTipo();

protected: 
    float _xc;
    float _yc;
    float _angulo;
    float _area;
    float _perimetro;
    fig_G _idTipo;
};

#endif