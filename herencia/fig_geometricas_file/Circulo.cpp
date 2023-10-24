/**
 * Project Untitled
 */

#include "Circulo.h"
#include <iostream>
#include <cmath>

using namespace std;

/**
 * Circulo implementation
 */

Circulo::Circulo(float r, float x, float y)
{
    if (r > 0.)
    {
        _radio = r;
        _xc = x;
        _yc = y;
    }
    else
    {
        cout << "No puede crear círculos de radio 0.";
        _radio = _xc = _yc = 0.;
    }
}

float Circulo::area()
{
    return M_PI * _radio * _radio;
}

float Circulo::perimetro()
{
    return 2 * M_PI * _radio;
}

ostream &operator<<(ostream &stream, Circulo &c)
{
    stream << "Soy un círculo de radio: " << c._radio << ". Mi perímetro es: " << c.perimetro() << " y mi área es: " << c.area();

    return stream;
}
