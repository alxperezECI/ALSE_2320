/**
 * Project Untitled
 */


#include "Filtro.h"
#include <iostream>

/**
 * Filtro implementation
 */
Filtro::Filtro(unsigned char tamano){
    _tamano = tamano;
    _cabezaFiltro = NULL;
}

/**
 * @param a
 * @return void
 */
bool Filtro::agregarDato(float a) {
    Dato *ptr = _cabezaFiltro;
    int tam = 1;

    if( ptr == NULL )
        _cabezaFiltro = new Dato( a );
    else{
        while( ptr->getSig() != NULL ){
            ptr = ptr->getSig();
            tam++;
        }

        ptr->setSig( new Dato (a) );
        tam++;

        if( tam > _tamano ){
            ptr = _cabezaFiltro->getSig();
            delete _cabezaFiltro;
            _cabezaFiltro = ptr;
        }
    }
    return true;
}

/**
 * @return float
 */
float Filtro::promedio() {
    Dato *ptr = _cabezaFiltro;
    float prom = 0.;
    if( ptr == NULL ) return 0.;
    for(int i = 0; i < _tamano; i++){
        if( ptr == NULL ) return prom / i ;
        prom += ptr->getDato();
        ptr = ptr->getSig();
    }
    prom /= _tamano;
    return prom;
}

float& Filtro::salida_filtro(float &a){
	float prom = promedio();
	agregarDato( a );
	return (a -= prom);
}



