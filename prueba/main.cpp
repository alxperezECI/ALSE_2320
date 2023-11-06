#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

class Estudiante
{
public:
    Estudiante(const std::string &codigo, const std::vector<double> &calificaciones)
        : codigo(codigo), calificaciones(calificaciones) {}

    double obtenerPromedio()
    {
        double suma = 0;
        for (double calificacion : calificaciones)
        {
            suma += calificacion;
        }
        return suma / calificaciones.size();
    }

    std::string getCodigo()
    {
        return codigo;
    }

private:
    std::string codigo;
    std::vector<double> calificaciones;
};

int main()
{
    std::vector<Estudiante> estudiantes;

    // Nombre del archivo que contiene la lista de estudiantes y sus calificaciones
    std::string nombreArchivo = "lista_estudiantes.txt";
    // Abrir el archivo y cargar la lista de estudiantes
    std::ifstream archivo(nombreArchivo);
    if (!archivo)
    {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }

    std::string linea;
    while (std::getline(archivo, linea))
    {
        std::istringstream ss(linea);
        std::string codigo;
        std::vector<double> calificaciones;

        // Leer el código y las calificaciones de cada línea
        ss >> codigo;
        double calificacion;
        while (ss >> calificacion)
        {
            calificaciones.push_back(calificacion);
        }

        Estudiante estudiante(codigo, calificaciones);
        estudiantes.push_back(estudiante);
    }
    archivo.close();

    // Calcular el promedio del curso
    double promedioCurso = 0.0;
    for (const Estudiante &estudiante : estudiantes)
    {
        promedioCurso += estudiante.obtenerPromedio();
    }
    promedioCurso /= estudiantes.size();

    // Encontrar al estudiante con el promedio más alto y más bajo
    Estudiante estudiantePromedioAlto = estudiantes[0];
    Estudiante estudiantePromedioBajo = estudiantes[0];
    for (const Estudiante &estudiante : estudiantes)
    {
        if (estudiante.obtenerPromedio() > estudiantePromedioAlto.obtenerPromedio())
        {
            estudiantePromedioAlto = estudiante;
        }
        if (estudiante.obtenerPromedio() < estudiantePromedioBajo.obtenerPromedio())
        {
            estudiantePromedioBajo = estudiante;
        }
    }

    // Imprimir resultados
    std::cout << "Promedio del curso: " << std::fixed << std::setprecision(2) << promedioCurso << std::endl;
    std::cout << "Estudiante con el promedio más alto: Código " << estudiantePromedioAlto.getCodigo() << ", Promedio " << estudiantePromedioAlto.obtenerPromedio() << std::endl;
    std::cout << "Estudiante con el promedio más bajo: Código " << estudiantePromedioBajo.getCodigo() << ", Promedio " << estudiantePromedioBajo.obtenerPromedio() << std::endl;

    return 0;
}