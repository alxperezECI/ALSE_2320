#include<iostream>

class Punto{
    double _x,_y;
    public:
    Punto();
    Punto(double x, double y);
    double X();
    double Y();
    double distancia(Punto &b);
    void X(const double &x);
    void Y(const double &y);
    friend std::ostream& operator<<(std::ostream &out, const Punto &p);
    Punto operator+(const Punto &b)const;
    Punto operator/(const double &b)const;
    Punto operator+=(const Punto &b);
    Punto operator/=(const double &b);
};