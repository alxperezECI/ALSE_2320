#include <iostream>

class Alumnos
{
    double _calif1, _calif2, _calif3, _calif4, _calif5;

public:
    Alumnos();
    Alumnos(double calif1, double calif2, double calif3, double calif4, double calif5);
    double calif1();
    double calif2();
    double calif3();
    double calif4();
    double calif5();
    void calif1(const double &calif1);
    void calif2(const double &calif2);
    void calif3(const double &calif3);
    void calif4(const double &calif4);
    void calif5(const double &calif5);
    Alumnos operator+(const alumnos &b) const;
    Alumnos &operator+=(const alumnos &b);
    friend std::ostream &operator<<(std::ostream &out, const Alumnos &p);
};
