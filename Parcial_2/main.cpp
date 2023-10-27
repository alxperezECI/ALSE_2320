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

    vector<Alumnos> vecAlumnnos;
    Alumnos tmp;
    int i = 0;
    ifstream archivo(argv[1]);
    double calif1, calif2, calif3, calif4, calif5;

    if (archivo.is_open())
    {
        while (archivo >> calif1 >> calif2 >> calif3 >> calif4 >> calif5)
        {
            tmp.calif1(calif1);
            tmp.calif2(calif2);
            tmp.calif3(calif3);
            tmp.calif4(calif4);
            tmp.calif5(calif5);
            vecAlumnos.push_back(tmp);
        }
        archivo.close();
    }
    Alumnos promedio;
    for (i = 0; i < vecAlumnos.size(); i++)
    {
        promedio += vecPuntos[i];
    }

    promedio = promedio / vecAlumnos.size();
    cout << "El promedio de las notas cargadas es: " << promedio << endl;

    return 0;
}
