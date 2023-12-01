#include "Temp.h"
#include <stdlib.h>

Temp::Temp() {

}

void Temp::setdato() {
    int dato = rand()%45+10;
    _dato.push_back(dato);
}

Temp::~Temp() {
}