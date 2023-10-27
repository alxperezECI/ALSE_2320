#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "alumno.h"

using namespace std;

int main(int argc, char **argv)
{

    vector<float> NotaEstudiante;
    vector<Alumno> Estudiante;

    if (argc != 2)
    {
        cout << "El programa no pudo abrir el archivo." << endl;
        return 1;
    }

    std::string path;
    path = argv[1];
    ifstream archivo;
    archivo.open(path);

    cout << "Se abrirá el archivo: " << path << endl;

    if (archivo.is_open())
    {
        // Aquí va el codigo que se va a hacer para leer el archivo
        int i = 0, posicion_max_nota, posicion_min_nota;
        float maxima_nota = 0, minima_nota = 5, Promedio_Curso;
        while (getline(archivo, path))
        {

            NotaEstudiante[i] = Estudiante.PromedioEstudiante(path);

            if (NotaEstudiante[i] > maxima_nota)
            {
                maxima_nota = NotaEstudiante[i];
                posicion_max_nota = i;
            }
            if (NotaEstudiante[i] < minima_nota)
            {
                minima_nota = NotaEstudiante[i];
                posicion_min_nota = i;
            }
            i++;
            cout << "El promedio del estudiante " << i << " es: " << NotaEstudiante[i] << endl;

            archivo.close();
        }

        Promedio_Curso = Estudiante.PromedioCurso(NotaEstudiante);
        cout << "El promedio del curso es: " << Promedio_Curso << endl;
        cout << "La nota maxima es: " << maxima_nota << " y la nota minima es: " << minima_nota << endl;

        return 0;
    }
}