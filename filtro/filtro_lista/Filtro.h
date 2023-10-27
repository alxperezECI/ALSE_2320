/**
 * Project Untitled
 */


#ifndef _FILTRO_H
#include "Dato.h"

class Filtro {
  public:
    Filtro(unsigned char tamano);
    float promedio();
	float& salida_filtro(float &muestra);
  private:
    Filtro();
	bool agregarDato(float a);
    unsigned char _tamano;
    Dato*		  _cabezaFiltro;
};

#endif //_FILTRO_H
