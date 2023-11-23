#include "Circulo.h"
#include "Cuadrado.h"
#include "Geometrica.h"
#include <iostream>
#include <cmath>

using namespace std;

Circulo::Circulo(float r, float x, float y) {
    if ( r > 0. ) {
        _radio = r;
        _xc = x;
        _yc = y;
    }else{
        cout << "No puede crear círculos de radio 0.";
        _radio = _xc = _yc = 0.;
    }
}

Circulo::Circulo() {
}
float Circulo::area() {
    return M_PI * _radio * _radio;
}

float Circulo::perimetro() {
    return 2. * M_PI * _radio;
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

float Circulo::getRadio() {
    return _radio;
}

void Circulo::setRadio(float r) {
    if ( r > 0. ) {
        _radio = r;
    }else{
        cout << "No puede crear círculos de radio 0.";
        _radio = 0.;
    }
}


ostream& operator<<(ostream& stream,  Circulo &c) {
    stream  << "Soy un círculo de radio: " << c.getRadio() << ". Mi perímetro es: " << c.perimetro() <<
               " y mi área es: " << c.area();
    return stream;
}

Circulo::Circulo(string parametros){
    _idTipo =  circulo ;
    size_t posicion = 0;
    size_t pos_ant = 0;
    posicion = parametros.find(" ");
    _radio = atof(parametros.substr(0,posicion).c_str());
    pos_ant =  posicion + 1;
    posicion = parametros.find(" ",pos_ant);
    _xc = atof(parametros.substr(pos_ant,posicion).c_str());
    pos_ant =  posicion + 1;
    posicion = parametros.find(" ",pos_ant);
    _yc = atof(parametros.substr(pos_ant,posicion).c_str());
    pos_ant =  posicion + 1;
    posicion = parametros.find(" ",pos_ant);
    _angulo = atof(parametros.substr(pos_ant,posicion).c_str());
    cout << "Círculo de R: " << _radio << ", Xc: " << _xc << ", Yc: " << _yc << ", Ángulo: " << _angulo << endl;
    _area = _perimetro = 0.;
}

string Circulo::queSoy(){
    return "Soy un círculo";
}