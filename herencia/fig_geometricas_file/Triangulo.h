/**
 * Project Untitled
 */

<<<<<<< HEAD
#ifndef _TRIANGULO_H
#define _TRIANGULO_H

#include <iostream>

using namespace std;

class Triangulo
{
public:
  Triangulo(float b, float h, float x = 0., float y = 0.);
  float area();
  float perimetro();
  friend ostream &operator<<(ostream &stream, Triangulo &t);

  void setBase(float b) { _base = b; }
  void setAltura(float h) { _altura = h; }
  float getBase() { return _base; }
  float getAltura() { return _altura; }
  void setX(float x) { _xc = x; }
  float getX() { return _xc; }
  void setY(float y) { _yc = y; }
  float getY() { return _yc; }
  void setAngulo(float a) { _angulo = a; }
  float getAngulo() { return _angulo; }

private:
  float _base;
  float _altura;
  float _xc;
  float _yc;
  float _angulo;
  float _area;
  float _perimetro;

  Triangulo();
=======

#ifndef _TRIANGULO_H
#define _TRIANGULO_H

#include "Geometrica.h"


class Triangulo: public Geometrica {
public: 
	
    /**
     * @param b
     * @param h
     * @param x
     * @param y
     */

    float area();
    float perimetro();
    Triangulo(float b, float h, float x = 0., float y = 0.);
    Triangulo(string parametros);
private:
	float _base;
	float _altura;
	
    Triangulo();
>>>>>>> origin/main
};

#endif //_TRIANGULO_H
