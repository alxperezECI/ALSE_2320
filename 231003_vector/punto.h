#include <iostream>

class Punto{
  double _x, _y;

public:
  Punto();
  Punto(double x, double y);
  double distancia(Punto &b);
  double X();
  double Y();
  void X(const double &x);
  void Y(const double &y);
  friend std::ostream& operator<<(std::ostream &out, const Punto &p);
};
