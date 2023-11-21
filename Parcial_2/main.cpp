#include <fstream>
#include "alumno.h"
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        cout << "Debe pasar el path del archivo de los datos de entrada ";
        cout << "junto con las coordenadas de consulta.\n"
             << endl;
        return 1;
    }  

    cout << "Se abrirá el archivo: " << argv[1] << endl;

    vector<Alumnos> vecAlumnos;
    ifstream archivo(argv[1]);

    if (archivo.is_open())
    {
        double calif1, calif2, calif3, calif4, calif5;
        int codigoalumno;
        while (archivo >> codigoalumno >> calif1 >> calif2 >> calif3 >> calif4 >> calif5)
        {
            Alumnos tmp(codigoalumno, calif1, calif2, calif3, calif4, calif5);
            vecAlumnos.push_back(tmp);
        }
        archivo.close();
    }

    if (vecAlumnos.empty())
    {
        cout << "No se encontraron datos en el archivo." << endl;
        return 1;
    }

    double promedioTotal = 0;
    double promedioMaximo = 0;
    double promedioMinimo = 100;
    Alumnos mejoralumno;
    Alumnos peoralumno;
    for (const Alumnos &alumno : vecAlumnos)
    {
        double promedioAlumno = alumno.calcularPromedio();
        cout << "El promedio del alumno " << alumno.getcodigoalumno() << " es: " << promedioAlumno << endl;
        promedioTotal += promedioAlumno;
        if (promedioAlumno > promedioMaximo)
        {
            promedioMaximo = promedioAlumno;
            mejoralumno = alumno;
        }
        if (promedioAlumno < promedioMinimo)
        {
            promedioMinimo = promedioAlumno;
            peoralumno = alumno;
        }
    }
    promedioTotal = promedioTotal / (vecAlumnos.size());
    cout << "El promedio del curso es: " << promedioTotal << endl;
    cout << "El estudiante con promedio más alto es: " << mejoralumno.getcodigoalumno() << " con un promedio de " << promedioMaximo << endl;
    cout << "El estudiante con promedio más bajo es: " << peoralumno.getcodigoalumno() << " con un promedio de " << promedioMinimo << endl;

    return 0;
}
