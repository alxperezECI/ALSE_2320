#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <stdlib.h>

using namespace std; // Usar el espacio de nombres std


// Estructura para el complejo
struct complejo{

        double real;
        double imag;

}vector[50], suma;

double norma_complejo(complejo);
double angulo_complejo(complejo);

int main(int argc, char** argv) {
	cout << "\n";
        if (argc < 2) { // Verifica si se proporcionó al menos un argumento (nombre del archivo)
                cerr << "Uso: " << argv[0] << " <datos.txt>" << endl;
                return 1; // Salir con código de error
        }else{
                cout << "Se abrira el archivo " << argv[1] << endl;
                char buff[255];
                int i = -1;
		FILE * archivo = fopen(argv[1], "r");
                while (fgets(buff,255,(FILE*) archivo)){
			i++;
			if (i%2 == 0){
				vector[i/2].real = strtod(buff, NULL);
				suma.real += vector[i/2].real;
			}else{
				vector[(i-1)/2].imag = strtod(buff, NULL);
				suma.imag += vector[(i-1)/2].imag;
				cout << "\n";
				if (vector[(i-1)/2].imag >= 0){
					cout << vector[(i-1)/2].real << "+" << vector[(i-1)/2].imag << "j" << endl;
					cout << "La magnitud del complejo es:\t" << norma_complejo(vector[(i-1)/2]) << endl;
					cout << "El angulo del complejo es:\t" << (angulo_complejo(vector[(i-1)/2])*180)/M_PI <<  "°" <<endl;
				}else{
					cout << vector[(i-1)/2].real << vector[(i-1)/2].imag << "j" << endl;
					cout << "La magnitud del complejo es:\t" << norma_complejo(vector[(i-1)/2]) << endl;
					cout << "El angulo del complejo es:\t" << (angulo_complejo(vector[(i-1)/2])+2*M_PI)*180/M_PI << "°" << endl;
				}

			}

                }
		if (i%2 == 0){
			vector[(i/2)+1].imag = 0;
			cout << vector[(i/2)+1].real << "+" << vector[(i/2)+1].imag <<"j" << endl;
			cout << "La magnitud del complejo es:\t" << norma_complejo(vector[(i/2)+1]) << endl;
			cout << "El angulo del complejo es:\t" << (angulo_complejo(vector[(i/2)+1])*180)/M_PI <<  "°" <<endl;
		}
		if (suma.imag >= 0){
			cout << "\nEl complejo promedio es:\t" << suma.real/((i/2)+1) << "+" << suma.imag/((i/2)+1) << "j" << endl;
		}else{
			cout << "\nEl complejo promedio es:\t" << suma.real/((i/2)+1) << suma.imag/((i/2)+1) << "j" << endl;
 		}
	}

	cout << "\n";
	return 0;
}

//Funcion para calcular la norma de un numero complejo
double norma_complejo(complejo pedro){
	return sqrt(pedro.real * pedro.real + pedro.imag * pedro.imag);
}

// Funcion para calcular el angulo de un complejo
double angulo_complejo(complejo pedro){
	return atan2(pedro.imag,pedro.real);
}
