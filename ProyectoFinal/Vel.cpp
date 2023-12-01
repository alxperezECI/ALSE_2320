#include "Vel.h"
#include <stdlib.h>

Vel::Vel() {
}

void Vel::setdato() {
    int dato = rand()%40;
    _dato.push_back(dato);
}

Vel::~Vel() {
}