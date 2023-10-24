/**
 * Project Untitled
 */


#include "Geometrica.h"
#include <iostream>

using namespace std;

float Geometrica::area() {
    return 0.0;
}

float Geometrica::perimetro() {
    return 0.0;
}

string Geometrica::queSoy(){
  return "Soy una figura geométrica";
}

ostream& operator<<(ostream& stream, Geometrica& g) {
    cout << "llamada a operador << de Geométrica" << endl;
    cout << g.queSoy();
    return stream   ;
}

Geometrica::Geometrica() {

}

Geometrica::~Geometrica(){
    cout << "Llamando destructor de Geométrica" << endl;
}


