#include <cmath>
#include <iostream>
#include "alumno.h"

Alumnos::Alumnos()
{
    _calif1 = _calif2 = _calif3 = _calif4 = _calif5 = 0.;
}

Alumnos::Alumnos(double calif1, double calif2, double calif3, double calif4, double calif5)
{
    _calif1 = calif1;
    _calif2 = calif2;
    _calif3 = calif3;
    _calif4 = calif4;
    _calif5 = calif5;
}

double Alumnos::calif1()
{
    return _calif1;
}

double Alumnos::calif2()
{
    return _calif2;
}

double Alumnos::calif3()
{
    return _calif3;
}

double Alumnos::calif4()
{
    return _calif4;
}

double Alumnos::calif5()
{
    return _calif5;
}

void Alumnos::calif1(const double &calif1)
{
    _calif1 = calif1;
}
void Alumnos::calif2(const double &calif2)
{
    _calif2 = calif2;
}

void Alumnos::calif3(const double &calif3)
{
    _calif3 = calif3;
}

void Alumnos::calif4(const double &calif4)
{
    _calif4 = calif4;
}

void Alumnos::calif5(const double &calif5)
{
    _calif5 = calif5;
}

Alumnos Alumnos::operator+(const Alumnos &b) const
{
    Alumnos res;
    res._calif1 = _calif1 + b._calif1;
    res._calif2 = _calif2 + b._calif2;
    res._calif3 = _calif3 + b._calif3;
    res._calif4 = _calif4 + b._calif4;
    res._calif5 = _calif5 + b._calif5;
    return res;
}

Alumnos &Alumnos::operator+=(const Alumnos &b)
{
    _calif1 += b._calif1;
    _calif2 += b._calif2;
    _calif3 += b._calif3;
    _calif4 += b._calif4;
    _calif5 += b._calif5;
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Alumnos &p)
{
    out << "( " << p._calif1 << ", " << p._calif2 << "," << p._calif3 << "," << p._calif4 << "," << p._calif5 << " )";
    return out;
}
