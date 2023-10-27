#include <iostream>
#include "Alumno.h"
#include <list>
#include <fstream>

using namespace std;

void promEst(list<Alumno> alumni) {
    float prom = 0;
    for (auto it = alumni.begin(); it != alumni.end(); ++it) {
        cout << "El estudiante con código: " << it->GetCod() << " tiene un promedio de: " << it->Getpromedio() << endl;
    }
}

void promCurso(list<Alumno> alumni) {
    float prom = 0;
    for (auto it = alumni.begin(); it != alumni.end(); ++it) {
        prom += it->Getpromedio();
    }
    cout << "\nEl promedio del curso es: " << prom / alumni.size() << endl;
}

void promEstMAX(list<Alumno> alumni) {
    float prom = 0;
    int cod = 0;
    for (auto it = alumni.begin(); it != alumni.end(); ++it) {
        if (it->Getpromedio() > prom) {
            prom = it->Getpromedio();
            cod = it->GetCod();
        }
    }
    cout << "\nEl estudiante con código: " << cod << " tiene el promedio más alto con: " << prom << endl;
}

void promEstMIN(list<Alumno> alumni) {
    float prom = alumni.begin()->Getpromedio();
    int cod = alumni.begin()->GetCod();
    for (auto it = alumni.begin(); it != alumni.end(); ++it) {
        if (it->Getpromedio() < prom) {
            prom = it->Getpromedio();
            cod = it->GetCod();
        }
    }
    cout << "\nEl estudiante con código: " << cod << " tiene el promedio más bajo con: " << prom << endl;
}

int main(int argc, char** argv){

    if( argc < 2){
        cout << "Debe pasar el path del archivo de los datos de entrada "<<endl;
        return 1;
    }
    cout << "Se abrirá el archivo: " << argv[1] << endl<<endl;
    list<Alumno> listaAlumnos;
    Alumno tmp;
    ifstream archivo( argv[1] );
    int cod;
    float nota[5];
    if( archivo.is_open() ){
        while ( archivo >> cod >> nota[1] >> nota[2] >> nota[3] >> nota[4] >> nota[5] ){
            tmp.SetCod(cod);
            tmp.SetNotas(nota[1], nota[2], nota[3], nota[4], nota[5]);
            listaAlumnos.push_back(tmp);
        }
        archivo.close();
    }

    promEst(listaAlumnos);
    promCurso(listaAlumnos);
    promEstMAX(listaAlumnos);
    promEstMIN(listaAlumnos);

    return 0;
}