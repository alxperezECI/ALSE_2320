#include "Pentagono.h"
#include <iostream>
#include <cmath>


using namespace std;
Pentagono::Pentagono(float l, float x, float y ) {
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

ostream& operator<<(ostream& stream, Pentagono& p) {
	stream << "Soy un pentágono que no sabe calcular su área ni su perímetro.";
    return stream;
}

Pentagono::Pentagono() {

}
