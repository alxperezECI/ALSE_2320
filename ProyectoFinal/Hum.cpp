#include "Hum.h"
#include <stdlib.h>
#include <iostream>

Hum::Hum() {

}

void Hum::setdato() {
    int dato = rand()%100;
    _dato.push_back(dato);
}

Hum::~Hum() {
}