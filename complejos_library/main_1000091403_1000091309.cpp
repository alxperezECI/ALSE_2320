#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <complex>

// using namespace std::complex_literals; // Usar el espacio de nombres std
using namespace std;

// funcion para ordenar los vectores
bool ordenar(complex<double> c[], int tamano)
{
	// metodo burbuja
	bool band;
	do
	{
		band = false;
		for (int i = 0; i < tamano; i++)
		{
			complex<double> aux;
			if (arg(c[i]) < arg(c[i + 1]))
			{
				// Intercambia los elementos si están en el orden incorrecto
				c[i] = c[i + 1];
				c[i + 1] = aux;
				band = true;
			}
			else if (abs(c[i]) < abs(c[i + 1]))
			{
				c[i] = c[i + 1];
				c[i + 1] = aux;
				band = true;
			}
		}
	} while (band == true);

	return true;
}

int main(int argc, char **argv)
{
	cout << "\n";
	complex<double> vector[100], suma = (0, 0);
	int i = -1;
	if (argc < 2)
	{ // Verifica si se proporcionó al menos un argumento (nombre del archivo)
		cerr << "Uso: " << argv[0] << " <datos.txt>" << endl;
		return 1; // Salir con código de error
	}
	else
	{
		cout << "Se abrira el archivo " << argv[1] << endl;
		char buff[255];

		FILE *archivo = fopen(argv[1], "r");
		while (fgets(buff, 255, (FILE *)archivo))
		{
			i++;
			if (i % 2 == 0)
			{
				vector[i / 2].real(strtod(buff, NULL));
			}
			else
			{
				vector[(i - 1) / 2].imag(strtod(buff, NULL));
				cout << "\n";
				if (vector[(i - 1) / 2].imag() >= 0)
				{
					cout << vector[(i - 1) / 2].real() << "+" << vector[(i - 1) / 2].imag() << "j" << endl;
					cout << "La magnitud del complejo es:\t" << abs(vector[(i - 1) / 2]) << endl;
					cout << "El angulo del complejo es:\t" << (arg(vector[(i - 1) / 2]) * 180) / M_PI << "°" << endl;
				}
				else
				{
					cout << vector[(i - 1) / 2].real() << vector[(i - 1) / 2].imag() << "j" << endl;
					cout << "La magnitud del complejo es:\t" << abs(vector[(i - 1) / 2]) << endl;
					cout << "El angulo del complejo es:\t" << (arg(vector[(i - 1) / 2]) + 2 * M_PI) * 180 / M_PI << "°" << endl;
				}
				suma += vector[(i - 1) / 2];
			}
		}
		if (i % 2 == 0)
		{
			vector[(i / 2) + 1].imag(0);
			cout << vector[(i / 2) + 1].real() << "+" << vector[(i / 2) + 1].imag() << "j" << endl;
			cout << "La magnitud del complejo es:\t" << abs(vector[(i / 2) + 1]) << endl;
			cout << "El angulo del complejo es:\t" << (arg(vector[(i / 2) + 1]) * 180) / M_PI << "°" << endl;
		}
		if (suma.imag() >= 0)
		{
			cout << "\nEl complejo promedio es:\t" << suma.real() / ((i / 2) + 1) << "+" << suma.imag() / ((i / 2) + 1) << "j" << endl;
		}
		else
		{
			cout << "\nEl complejo promedio es:\t" << suma.real() / ((i / 2) + 1) << suma.imag() / ((i / 2) + 1) << "j" << endl;
		}
	}

	// llamar la funcion

	bool flag = ordenar(vector, i / 2);

	cout << "\n";
	return 0;
}
