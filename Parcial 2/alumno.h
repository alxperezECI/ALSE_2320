#ifndef _ALUMNO_H_
#define _ALUMNO_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Alumno
{
private:
    vector<float> nota;
    int codigo;

public:
    Alumno(string path);
    float PromedioEstudiante();
    float PromedioCurso();
    float PromedioEstudiante(string path);
    float PromedioCurso(const vector<float> Promedio);
    int getCodigo();
    long getCodigo(string path);
    void setCodigo(int codigo);
    float getNota(int i);
    void setNota(float nota1, float nota2, float nota3, float nota4, float nota5);
};

#endif // _ALUMNO_H_
