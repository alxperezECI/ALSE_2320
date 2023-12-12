#include "Lluvia.h"
#include <stdlib.h>

Lluvia::Lluvia() {

}

/**
 * @param in
 */
void Lluvia::setdato() {
    int dato = rand()%50;
    _dato.push_back(dato);
}

Lluvia::~Lluvia() {
}