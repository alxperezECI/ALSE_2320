#include "Geometrica.h"

float Geometrica::area() {
    return 0.0;
}

float Geometrica::perimetro() {
    return 0.0;
}

Geometrica::Geometrica() {

}
void Geometrica::setX(float x) {
    _xc = x;
}

float Geometrica::getX() {
    return _xc;
}

void Geometrica::setY(float y) {
    _yc = y;
}

float Geometrica::getY() {
    return _yc;
}

float Geometrica::getAngulo() {
    return _angulo;
}

void Geometrica::setAngulo(float a) {
    _angulo = a;
}

Geometrica::~Geometrica() {
    cout << "Destruyendo figura geométrica" << endl;
}

string Geometrica::queSoy(){
    return "Soy una figura geométrica";
}

ostream& operator<<(ostream& stream, Geometrica& g) {
    cout << "llamada a operador << de Geométrica" << endl;
    cout << g.queSoy();
    return stream   ;
}

fig_G Geometrica::getTipo(){
    return _idTipo;
}