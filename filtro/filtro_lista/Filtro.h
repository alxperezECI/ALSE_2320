/**
 * Project Untitled
 */


#ifndef _FILTRO_H
#include "Dato.h"

class Filtro {
  public:
    // constructor del filtro con restriccion de tamaño positivo
    Filtro(unsigned char tamano);
    float promedio();
	float& salida_filtro(float &muestra); // funcion que saca la salida del filtro como dato
  private:
    Filtro(); // filtro por omision privado
	bool agregarDato(float a);
    unsigned char _tamano; // puntero al primer dato
    Dato*		  _cabezaFiltro;
};

#endif //_FILTRO_H
