#include "Punto.h"
#include <cmath>
#include <iostream>

Punto::Punto(){
    _x=0.;
    _y=0.;
}
Punto::Punto(double x, double y)
{
    _x=x;
    _y=y;
}

double Punto::distancia(Punto &b){
    return sqrt((_x-b._x)*(_x-b._x)+(_y-b._y)*(_y-b._y));
}
double Punto:: X(){
    return _x;
}
double Punto:: Y(){
    return _y;
}
void Punto::X(const double &x){
    _x=x;
}
void Punto:: Y(const double &y){
    _y=y;
}

std::ostream& operator<<( std::ostream &out, const Punto &p){
  out << "(" << p._x << ", " << p._y << ")" ;
  return out;
}
Punto Punto::operator+(const Punto &b)const{
    Punto tmp;
    tmp._x=_x+b._x;
    tmp._y=_y+b._y;
    return tmp;
}
Punto Punto::operator/(const double &b)const{
    Punto tmp;
    tmp._x=_x/b;
    tmp._y=_y/b;
    return tmp;
}
Punto Punto:: operator+=(const Punto &b){
    _x+=b._x;
    _y+=b._y;
    return *this;
}
Punto Punto:: operator/=(const double &b){
    _x/=b;
    _y/=b;
    return *this;
}
