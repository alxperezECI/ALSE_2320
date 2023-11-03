#include <string>

using namespace std;

class Alumno{
  double _notas[5];
  int 	 _codigo;
  double _promedio;
public:
  Alumno();
  Alumno(string linea);
  void setCodigo(int c);
  double getCodigo();
  double promedio();
  void setNotas(double n1, double n2, double n3, double n4, double n5);
  double getNota(int i);
};
