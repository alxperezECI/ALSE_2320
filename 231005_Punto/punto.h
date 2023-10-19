#include <iostream>

class Punto
{
  double _x, _y;

public:
  Punto();
  Punto(double x, double y);
  double distancia(Punto &b);
  double X();
  double Y();
  void X(const double &x);
  void Y(const double &y);
<<<<<<< HEAD
  Punto operator+(const Punto &b) const;
  Punto operator/(const double &e) const;
  Punto &operator+=(const Punto &b);
  friend std::ostream &operator<<(std::ostream &out, const Punto &p);
=======
  Punto operator+(const Punto &b)const;
  Punto operator/(const double &e)const;
  Punto& operator+=(const Punto &b);
  friend std::ostream& operator<<(std::ostream &out, const Punto &p);
>>>>>>> c8284a7c4a25682ea6e1171e4003799139f05e0f
};
