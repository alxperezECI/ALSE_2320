/**
 * Project Untitled
 */


#include "Filtro.h"
#include <iostream>
#include <list>

/**
 * Filtro implementation
 */
Filtro::Filtro(unsigned char tamano){
    _tamano = tamano;
    _memoria.clear();
}

/**
 * @param a
 * @return void
 */
bool Filtro::agregarDato(float a) {
	// Escrir el código para garantizar el tamaño fijo de la ventana de muestras

    _memoria.push_back( a );
    if( _memoria.size() > _tamano ) _memoria.pop_front();

    return true;
}

/**
 * @return float
 */
float Filtro::promedio() {
    float prom = 0.;
    // Escribir el código para calcular el promedio de los datos de la lista
    std::list<float>::iterator it;
    for ( it = _memoria.begin(); it != _memoria.end(); ++it )
        prom += *it;

    return prom / _memoria.size();
}

float& Filtro::salida_filtro(float &a){
	float prom = promedio();
	agregarDato( a );
	return (a -= prom);
}



