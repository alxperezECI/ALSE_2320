#include "punto.h"

class Vec2D : public punto
{

public:
    Vec2D(); // constructores
    Vec2D(double x, double y);
    Vec2D unitario(); // devuelve un vector unitario
    double norma();   // devuelve la norma del vector
}