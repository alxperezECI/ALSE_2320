
#include "alumno.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

double promedio_alumnos( vector<Alumno> &alumnos ){
  double prom_curso = 0.0;
  for (int i = 0; i < alumnos.size(); i++){
    prom_curso += alumnos[i].promedio();
  }
  prom_curso /= alumnos.size();
  return prom_curso;
}

int alumno_menor( vector<Alumno> &alumnos ){
    double prom_menor = alumnos[0].promedio();
    int est_menor = 0;
    for(int i = 1; i < alumnos.size(); i++){
      if( alumnos[i].promedio() < prom_menor){
        prom_menor = alumnos[i].promedio();
        est_menor = i;
      }
    }
    return alumnos[ est_menor ].getCodigo();
}

int alumno_mayor( vector<Alumno> &alumnos ){
    double prom_mayor = alumnos[0].promedio();
    int est_mayor = 0;
    for(int i = 1; i < alumnos.size(); i++){
      if( alumnos[i].promedio() > prom_mayor){
        prom_mayor = alumnos[i].promedio();
        est_mayor = i;
      }
    }
    return alumnos[ est_mayor ].getCodigo();
}


int main(int argc, char** argv){
    vector<Alumno> vAlumnos;

    if(argc != 2){
        cout << "El programa se usa así:" << endl;
        cout << "promedios path_to_file" << endl;
        cout << "Se debe indicar la ruta al archivo a leer" << endl;
        return 1;
    }

    string path;
    path = argv[1];
    ifstream archivo;
    archivo.open(path);

    cout << "Se abrirá el archivo: " << path << endl;

    if(archivo.is_open()){
        // Aquí va el codigo que se va a hacer para leer el archivo

        while( getline(archivo, path) ){
          vAlumnos.push_back( Alumno( path ) );
        }
        cout << vAlumnos.size() << " estudiantes cargados." << endl;
        archivo.close();
    }

    double prom_curso = promedio_alumnos( vAlumnos );

    int est_bajo = alumno_menor( vAlumnos );

    int est_alto = alumno_mayor( vAlumnos );

    cout << "El curso tiene un promedio de " << prom_curso << " y el estudiante destacado es " << est_alto << "." << endl;
    cout << "El estudiante con menor promedio es " << est_bajo << "." << endl;
    return 0;
}
