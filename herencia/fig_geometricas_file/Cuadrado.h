/**
 * Project Untitled
 */

<<<<<<< HEAD
#ifndef _CUADRADO_H
#define _CUADRADO_H

#include <iostream>

using namespace std;

class Cuadrado
{
public:
  Cuadrado(float l, float x = 0., float y = 0.);

  float area();
  float perimetro();
  friend ostream &operator<<(ostream &stream, Cuadrado &c);

  void setLado(float l) { _lado = l; }
  float getLado() { return _lado; }
  void setX(float x) { _xc = x; }
  float getX() { return _xc; }
  void setY(float y) { _yc = y; }
  float getY() { return _yc; }
  void setAngulo(float a) { _angulo = a; }
  float getAngulo() { return _angulo; }

private:
  float _lado;
  float _xc;
  float _yc;
  float _angulo;
  float _area;
  float _perimetro;

  Cuadrado();
=======

#ifndef _CUADRADO_H
#define _CUADRADO_H

#include "Geometrica.h"


class Cuadrado: public Geometrica {
  public:
    Cuadrado(float l, float x = 0., float y = 0.);
    Cuadrado(string parametros);

    float area();
    float perimetro();
    string queSoy();
    void setLado(float l){ _lado = l;}
    float getLado(){ return _lado;}

  private:
	float _lado;
	
    Cuadrado();
>>>>>>> origin/main
};

#endif //_CUADRADO_H
