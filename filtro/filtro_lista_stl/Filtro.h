/**
 * Project Untitled
 */


#ifndef _FILTRO_H
#include <list>

class Filtro {
  public:
    Filtro(unsigned char tamano);
    float promedio();
	float& salida_filtro(float &muestra);
  private:
    Filtro();
	bool agregarDato(float a);
    unsigned char 	 _tamano;
    std::list<float> _memoria;
};

#endif //_FILTRO_H
