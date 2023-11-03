#include "alumno.h"
#include <string>
#include <iostream>

using namespace std;

Alumno::Alumno(){
  for(int i = 0; i < 5; i++)
    _notas[i] = 0.0;

  _promedio = 0.0;
  _codigo = 0;
}

Alumno::Alumno(string linea){
  size_t t1, t2;
  _promedio = 0.0;

  t1 = linea.find(" ", 0);
  string cod = linea.substr( 0, t1 );
  _codigo = atof( cod.c_str() );
  for( int i = 0; i < 5; i++){
    t2 = linea.find(" ", t1 + 1 );
    cod = linea.substr( t1 + 1, t2 );
    t1 = t2;
    _notas[i] = atof( cod.c_str() );
    cout << _notas[i] << " ";
  }
  _promedio = promedio() ;
  cout << _promedio << endl;
}

void Alumno::setCodigo(int c){
  _codigo = c;
}

double Alumno::getCodigo(){
  return _codigo;
}

double Alumno::promedio(){
  if(_promedio == 0.0 ){
    for(int i = 0;i < 5; i++)
      _promedio += _notas[i];

    _promedio /= 5.0;
  }
  return _promedio;
}

void Alumno::setNotas(double n1, double n2, double n3, double n4, double n5){
  _notas[0] = n1;
  _notas[1] = n2;
  _notas[2] = n3;
  _notas[3] = n4;
  _notas[4] = n5;
}

double Alumno::getNota(int i){
  return _notas[i];
}
