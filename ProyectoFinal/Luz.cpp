#include "Luz.h"
#include <stdlib.h>

Luz::Luz() {
}

void Luz:: setdato(){
    int dato = rand()%2000;
    _dato.push_back(dato);
}

Luz::~Luz() {
}
