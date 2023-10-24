/**
 * Project Untitled
 */


#include "Cuadrado.h"

Cuadrado::Cuadrado(float l, float x, float y) {
    _lado = l;
    _idTipo =  cuadrado;
    setX( x );
    setY( y );
    setTipo( cuadrado );
}

Cuadrado::Cuadrado(string parametros){
    // 32.2 -65.2 -42.1 30.0   ... Lado xc yc angulo
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
    cout << "Cuadrado de L: " << _lado << ", Xc: " << _xc << ", Yc: " << _yc << ", Ángulo: " << _angulo << endl;
     _area = _perimetro = 0.;
     _idTipo =  cuadrado;
}

Cuadrado::Cuadrado() {

}

float Cuadrado::area(){
    return _lado * _lado;
}

float Cuadrado::perimetro(){
    return 4 * _lado;
}

string Cuadrado::queSoy(){
    return "Soy un cuadrado";
}

