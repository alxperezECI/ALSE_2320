/**
 * Project Untitled
 */

<<<<<<< HEAD
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
=======

#ifndef _CIRCULO_H
#define _CIRCULO_H

#include "Geometrica.h"
#include <string>


class Circulo: public Geometrica {

public: 	
    Circulo(float r, float x = 0., float y = 0.);
    Circulo(string parametros);
    float area();
    float perimetro();
    std::string queSoy();
    friend ostream& operator<<(ostream& stream, Circulo& c);

    void setRadio(float r){_radio = r;}
    float getRadio(){return _radio;}

private: 
	float _radio;
	
    Circulo();
>>>>>>> origin/main
};

#endif //_CIRCULO_H
