#include <iostream>
#include "alumno.h"

using namespace std;

float Alumno::PromedioEstudiante(string path)
{
    float promedio = 0;
    size_t posicion = 0;
    for (int i = 1; i < 5; i++)
    {
        posicion = path.find(" ");
        promedio += atof(path.substr(i, posicion).c_str());
    }
    promedio /= 5;
    return promedio;
}

float Alumno::PromedioCurso(const vector<float> promedio)
{
    float promediocurso = 0;
    for (int i = 0; i < promedio.size(); i++) // mirar
    {
        promediocurso += promedio[i];
    }
    promediocurso /= promedio.size();
    return promediocurso;
}

Alumno::Alumno(string path)
{
}

float Alumno::PromedioEstudiante()
{
    return 0.0f;
}

float Alumno::PromedioCurso()
{
    return 0.0f;
}
