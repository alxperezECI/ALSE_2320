#include "Triangulo.h"

Triangulo::Triangulo(float b, float h, float x, float y) {
    _base = b;
    _altura = h;
    _xc = x;
    _yc = y;
}

float Triangulo::area() {
    return _base * _altura / 2.;
}

float Triangulo::perimetro() {
    return 3. * _base;
}

float Triangulo::getBase() {
    return _base;
}

void Triangulo::setBase(float b) {
    _base = b;
}

float Triangulo::getAltura() {
    return _altura;
}

void Triangulo::setAltura(float h) {
    _altura = h;
}

ostream& operator<<(ostream& stream, Triangulo& t) {
    stream << "Soy un triángulo" << ". Mi perímetro es: " << t.perimetro() <<
               " y mi área es: " << t.area() ;
	return stream;
}

Triangulo::Triangulo() {

}

Triangulo::Triangulo(string parametros) {
    size_t posicion = 0;
    size_t pos_ant = 0;
    posicion = parametros.find( " " );
    _base = atof(parametros.substr(0,posicion).c_str());
    pos_ant =  posicion + 1;
    posicion = parametros.find( " ", pos_ant );
    _altura = atof(parametros.substr(0,posicion).c_str());
    pos_ant =  posicion + 1;
    posicion = parametros.find( " ", pos_ant );
    setX( atof(parametros.substr(0,posicion).c_str()) );
    pos_ant =  posicion + 1;
    posicion = parametros.find( " ", pos_ant );
    setY( atof(parametros.substr(0,posicion).c_str()) );
    pos_ant =  posicion + 1;
    posicion = parametros.find( " ", pos_ant );
    setAngulo( atof(parametros.substr(0,posicion).c_str()) );
    cout << "Triángulo de B: " << _base << ", h: " << _altura << ", Xc: " << _xc << ", Yc: " << _yc << ", Ángulo: " << _angulo << endl;
    _area = _perimetro = 0.;
    _idTipo =  triangulo;
}