#include "punto.h"
#include <cmath> //#include <math.h>
#include <iostream>

Punto::Punto(){  //Constructor por omisión
  _x = _y = 0.;
}

Punto::Punto(double x, double y){  //Constructor con parámetros X e Y
  _x = x;
  _y = y;
}

double Punto::distancia(Punto &b){ //Calcula la distancia a otro 
                                   //objeto de la clase Punto
  return sqrt((b._x - _x)*(b._x - _x) + (b._y - _y)*(b._y - _y));
}

double Punto::X(){ 
  return _x;
}

double Punto::Y(){ 
  return _y;
}

void Punto::X(const double &x){ 
  _x = x; 
}

void Punto::Y(const double &y){ 
  _y = y;
}
Punto Punto::operator+(const Punto &b)const{
  Punto res;
  res._x = _x + b._x;
  res._y = _y + b._y;
  return res;
}

Punto Punto::operator/(const double &e)const{
  Punto res;
  res._x = _x / e;
  res._y = _y / e;
  return res;
}

Punto& Punto::operator+=(const Punto &b){
  _x += b._x;
  _y += b._y;
  return *this;
}

std::ostream& operator<<( std::ostream &out, const Punto &p){
  out << "( " << p._x << ", " << p._y << " )" ;
  return out;
}

