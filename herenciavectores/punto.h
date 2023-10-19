#include <iostream>

class Punto
{
protected:
  double _x, _y;

public:
  Punto();
  Punto(double x, double y);
  double distancia(Punto &b);
  double X();
  double Y();
  void X(const double &x);
  void Y(const double &y);
  Punto operator+(const Punto &b) const;
  friend std::ostream &operator<<(std::ostream &out, const Punto &p);
};
