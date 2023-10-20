#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <stdlib.h>

using namespace std; // Usar el espacio de nombres std

struct complejo
{

	double real;
	double imag;
} complex;

double norma_complejo(complejo);
double angulo_complejo(complejo);

int main(int argc, char **argv)
{
	if (argc < 2)
	{ // Verifica si se proporcionó al menos un argumento (nombre del archivo)
		cerr << "Uso: " << argv[0] << " <datos.txt>" << endl;
		return 1; // Salir con código de error
	}
	else
	{
		cout << "Se abrira el archivo " << argv[1];
		char buff[255];
		int i = 0;
		FILE *archivo = fopen(argv[1], "r");
		while (fgets(buff, 255, (FILE *)archivo))
		{
			if (i % 2 == 0)
			{
				complex.real = strtod(buff, NULL);
			}
			else
			{
				complex.imag = strtod(buff, NULL);
				cout << "\n";
				if (complex.imag >= 0)
				{
					cout << complex.real << "+" << complex.imag << "j" << endl;
					cout << "La magnitud es:\t" << norma_complejo(complex) << endl;
					cout << "El angulo es:\t" << angulo_complejo(complex) << endl;
				}
				else
				{
					cout << complex.real << complex.imag << "j" << endl;
					cout << "La magnitud es:\t" << norma_complejo(complex) << endl;
					cout << "El angulo es:\t" << angulo_complejo(complex) << endl;
				}
			}
			i++;
		}
	}

	return 0; // Retorna 0 para indicar éxito
}

// Función para calcular la norma de un número complejo
double norma_complejo(complejo nume)
{
	return sqrt(nume.real * nume.real + nume.imag * nume.imag);
}

// Función para calcular el ángulo de un número complejo
double angulo_complejo(complejo nume)
{
	return atan2(nume.imag,nume.real);
}