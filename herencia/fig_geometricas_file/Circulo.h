/**
 * Project Untitled
 */

#ifndef _CIRCULO_H
#define _CIRCULO_H

#include <iostream>
#include "Cuadrado.h"

using namespace std;

class Circulo
{
public:
  Circulo(float r, float x = 0.0, float y = 0.0);
  Circulo(string parametros);
  float area();
  float perimetro();
  std::string quesoy();
  friend ostream &operator<<(ostream &stream, Circulo &c);
  void setRadio(float r) { _radio = r; }
  float getRadio() { return _radio; }

private:
  float _radio;

  Circulo();
};

#endif //_CIRCULO_H
