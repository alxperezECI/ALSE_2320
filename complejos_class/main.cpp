#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include <complex>
#include <iostream>

using namespace std;
void ordenar(complex<double> c[], complex<double> temp, int j, int k, int i)
{
    for (j = 0; j < ((i / 2) - 1); j++)
    {
        for (k = 0; k < ((i / 2) - 1); k++)
        {
            if (arg(c[k]) > (arg(c[(k) + 1])))
            {
                temp = c[k];
                c[k] = c[k + 1];
                c[k + 1] = temp;
            }
            if (arg(c[k]) == arg(c[k + 1]))
            {
                if (abs(c[k]) > abs(c[(k) + 1]))
                {
                    temp = c[k];
                    c[k] = c[k + 1];
                    c[k + 1] = temp;
                }
            }
        }
    }
}

using namespace std;
int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Debe pasar el path del archivo de los datos de entrada.\n");
        return 1;
    }
    else
    {

        printf("Se abrirá el archivo %s\n", argv[1]);
        char buff[255];
        // voy a crear un vector de complejos
        complex<double> veccplx[50];
        int i = 0;
        FILE *archivo = fopen(argv[1], "r");

        while (fgets(buff, 255, archivo))
        {
            if (i % 2 == 0) // en archivo: linea impar
            {

                veccplx[i / 2].real(strtod(buff, NULL));
            }
            else
            {

                veccplx[i / 2].imag(strtod(buff, NULL));
            }
            i++;
        }

        complex<double> temp;
        int j = 0;
        int k = 0;
        ordenar(veccplx, temp, j, k, i);

        int l = 0;
        for (l = 0; l < i / 2; l++)
        {
            cout << "El complejo " << l << " es :" << veccplx[l] << endl;
        }
        fclose(archivo);
    }

    return 0;
}
