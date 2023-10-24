#ifndef _Geometrica_H_
#define _Geometrica_H_
#include <iostream>
#include <string>

using namespace std;

enum fig_G
{
    Circulo = 1,
    Cuadrado,
    Triangulo,
    Pentagono
};

class Geometrica
{
public:
    float area();
    float perimetro();
    virtual string quesoy();
    friend ostream &operator<<(ostream &stream, Geometrica &g);
    //
    void setX(float x) { _xc = x; }
    float getX() { return _xc; }
    void setY(float y) { _yc = y; }
    float getY() { return _yc; }
    void setAngulo(float a) { _angulo = a; }
    float getAngulo() { return _angulo; }
    void setArea(float a) { _area = a; }
    float getArea() { return _area; }
    void setPerimetro(float p) { _perimetro = p; }
    float getPerimetro() { return _perimetro; }

protected:
    float _xc, _yc;
    float _angulo;
    float _area;
    float _perimetro;

private:
    void Geometrica();
};

#endif //_Geometrica_H_