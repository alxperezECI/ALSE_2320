#include "Pentagono.h"
#include <iostream>

Pentagono::Pentagono(float l, float x, float y) {
	_lado = l;
	_xc = x;
	_yc = y;
}

float Pentagono::area() {
    return 0.;
}

float Pentagono::perimetro() {
    return 0.;
}

float Pentagono::getLado() {
    return _lado;
}

void Pentagono::setLado(float l) {
    _lado = l;
}

Pentagono::Pentagono(string parametros) {
    size_t posicion = 0;
    size_t pos_ant = 0;
    posicion = parametros.find(" ");
    _lado = atof(parametros.substr(pos_ant,posicion).c_str());
    pos_ant =  posicion + 1;
    posicion = parametros.find(" ",pos_ant);
    setX( atof(parametros.substr(pos_ant,posicion).c_str()) );
    pos_ant =  posicion + 1;
    posicion = parametros.find(" ",pos_ant);
    setY( atof(parametros.substr(pos_ant,posicion).c_str()) );
    pos_ant =  posicion + 1;
    posicion = parametros.find(" ",pos_ant);
    setAngulo( atof(parametros.substr(pos_ant,posicion).c_str()) );
    cout << "Pentágono de L: " << _lado << ", Xc: " << _xc << ", Yc: " << _yc << ", Ángulo: " << _angulo << endl;
     _area = _perimetro = 0.;
     _idTipo =  pentagono;
}


ostream& operator<<(ostream& stream, Pentagono& p) {
	stream << "Soy un pentágono que no sabe calcular su área ni su perímetro.";
    return stream;
}

Pentagono::Pentagono() {

}