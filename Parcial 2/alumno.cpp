#include <iostream>
#include "alumno.h"

using namespace std;

float Alumno::PromedioEstudiante(string path)
{
    float promedio = 0;
    size_t posicion = 0;
    posicion = path.find(" ");
    for (int i = 0; i < 5; i++)
    {
        size_t siguiente_posicion = path.find(" ", posicion + 1);
        promedio += atof(path.substr(posicion + 1, siguiente_posicion - posicion - 1).c_str());
        posicion = siguiente_posicion;
    }
    promedio /= 5;
    return promedio;
}

float Alumno::PromedioCurso(const vector<float> promedio)
{
    float promediocurso = 0;
    for (int i = 0; i < promedio.size(); i++)
    {
        promediocurso += promedio[i];
    }
    promediocurso /= promedio.size();
    return promediocurso;
}

int Alumno::getCodigo()
{
    return 0;
}

long Alumno::getCodigo(string path)
{
    return atol(path.substr(0, path.find(" ")).c_str());
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
