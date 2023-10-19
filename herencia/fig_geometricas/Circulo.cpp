/**
 * Project Untitled
 */


#include "Circulo.h"
#include <iostream>
#include <cmath>

using namespace std;

/**
 * Circulo implementation
 */


Circulo::Circulo(float r, float x, float y ) {
    if ( r > 0. ) {
        _radio = r;
        _xc = x;
        _yc = y;
    }else{
        cout << "No puede crear círculos de radio 0.";
        _radio = _xc = _yc = 0.;
    }

}

float Circulo::area() {
    return M_PI * _radio * _radio;
}

float Circulo::perimetro() {
    return 2 * M_PI * _radio;
}

bool Circulo::intersectan(Circulo &c){
    float dx, dy;
    dx = _xc - c._xc;
    dy = _yc - c._yc;
    dx = sqrt(dx * dx + dy * dy);
    //cout << dx << " : " << _radio + c._radio << endl;
    return ( dx <= ( _radio + c._radio ) );
}

bool Circulo::intersectan(Cuadrado &c){
    float dx, dy;
    dx = _xc - c.getX();
    dy = _yc - c.getY();
    dx = sqrt(dx * dx + dy * dy);
    //cout << dx << " : " << _radio + c._radio << endl;
    return ( dx <= ( _radio + c.getLado() / 2. ) );
}


ostream& operator<<(ostream& stream,  Circulo &c) {
    stream  << "Soy un círculo de radio: " << c._radio << ". Mi perímetro es: " << c.perimetro() <<
               " y mi área es: " << c.area();

    return stream;
}

