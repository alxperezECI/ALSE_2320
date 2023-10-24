/**
 * Project Untitled
 */


#ifndef _PENTAGONO_H
#define _PENTAGONO_H

#include "Geometrica.h"


class Pentagono: public Geometrica {
  public:
    Pentagono(float l, float x, float y);
    Pentagono(string parametros);
  private:
	float _lado;
	
    Pentagono();
};

#endif //_PENTAGONO_H
