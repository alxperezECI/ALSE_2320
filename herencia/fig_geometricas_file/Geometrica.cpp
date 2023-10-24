#include "Geometrica.h"
#include <iostream>
#include <cmath>

using namespace std;

float Geometrica::area()
{
    return 0.;
}

float Geometrica::perimetro()
{
    return 0.;
}

virtual string Geometrica::quesoy()
{
    return "Geometrica";
}

ostream &Geometrica::operator<<(ostream &stream, Geometrica &g)
{
    return stream;
}
