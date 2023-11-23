#ifndef _CIRCULO_H
#define _CIRCULO_H

#include "Geometrica.h"
#include "Cuadrado.h"


class Circulo: public Geometrica {
public: 
    bool intersectan(Circulo& c);
    bool intersectan(Cuadrado& c);
    Circulo(float r, float x=0, float y=0);
    Circulo(string parametros);
    float getRadio();
    void setRadio(float r);
    float area();
    float perimetro();
    std::string queSoy();
    friend ostream& operator<<(ostream& stream, Circulo& c);
private:
    Circulo();
    float _radio;
};

#endif