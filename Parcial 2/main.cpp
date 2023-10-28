#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "alumno.h"

using namespace std;

int main(int argc, char **argv)
{

    vector<float> NotaEstudiante;
    vector<Alumno*> Estudiante;

    if (argc != 2)
    {
        cout << "El programa no pudo abrir el archivo." << endl;
        return 1;
    }

    std::string path;
    path = argv[1];
    ifstream archivo;
    archivo.open(path);

    cout << "Se abrirá el archivo: " << path << "\n" <<endl;

    if (archivo.is_open())
    {
        // Aquí va el codigo que se va a hacer para leer el archivo
        int i = 0;
        float maxima_nota = 0, minima_nota = 5, Promedio_Curso;
        string linea;
        long id = 0, id_max_nota = 0, id_min_nota = 0; 
        while (getline(archivo, linea))
        {
            NotaEstudiante.resize(i+1);
            Estudiante.resize(i+1);

            NotaEstudiante[i] = Estudiante[i]->PromedioEstudiante(linea);

            if (NotaEstudiante[i] > maxima_nota)
            {
                maxima_nota = NotaEstudiante[i];
                id_max_nota = Estudiante[i]->getCodigo(linea);
            }
            if (NotaEstudiante[i] < minima_nota)
            {
                minima_nota = NotaEstudiante[i];
                id_min_nota = Estudiante[i]->getCodigo(linea);
            }
            id = Estudiante[i]->getCodigo(linea);
            i++;
            cout << "El promedio del estudiante " << id << " es: " << NotaEstudiante[i-1] << endl;
        }

        archivo.close();

        float sum = 0;
        for (int i = 0; i < NotaEstudiante.size(); i++) {
            sum += NotaEstudiante[i];
        }
        Promedio_Curso = sum / NotaEstudiante.size();
        cout << "\nEl promedio del curso es: " << Promedio_Curso << endl;
        cout << "La nota maxima es: " << maxima_nota << " del estudiante " << id_max_nota << endl;
        cout << "La nota minima es: " << minima_nota << " del estudiante " << id_min_nota << "\n" << endl;

        return 0;
    }
}