/**
 * Project Untitled
 */


#include "Cuadrado.h"
#include <iostream>

using namespace std;

/**
 * Cuadrado implementation
 */

Cuadrado::Cuadrado(float l, float x , float y ) {
	_lado = l;
	_xc = x;
	_yc = y;
}

float Cuadrado::area() {
    return _lado * _lado;
}

float Cuadrado::perimetro() {
    return 4. * _lado;
}

ostream& operator<<(ostream& stream, Cuadrado& c) {
    stream  << "Soy un cuadrado de lado: " << c._lado << ". Mi perímetro es: " << c.perimetro() <<
               " y mi área es: " << c.area();

    return stream;
}

Cuadrado::Cuadrado() {

}
