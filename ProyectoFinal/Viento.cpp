#include "Viento.h"
#include <stdlib.h>

Viento::Viento() {
}


void Viento::setdato() {
    int dato = rand()%361-180;
    _dato.push_back(dato);
}

Viento::~Viento() {
}