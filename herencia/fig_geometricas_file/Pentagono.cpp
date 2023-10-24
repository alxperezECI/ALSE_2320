/**
 * Project Untitled
 */


#include "Pentagono.h"

/**
 * Pentagono implementation
 */


/**
 * @param l
 * @param x
 * @param y
 */
Pentagono::Pentagono(float l, float x, float y) {
    _idTipo =  pentagono;
    _lado = l;
    setX( x );
    setY( y );
    setTipo( pentagono );
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

Pentagono::Pentagono() {

}
