#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fstream>

struct complejo
{
  double re;
  double img;
};

double norma_complejo(complejo c)
{
  return sqrt(c.re * c.re + c.img * c.img);
}

double angulo_complejo(complejo c)
{
  return atan2(c.img, c.re);
}

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
    complejo veccplx[50];
    int i = 0;
    FILE *archivo = fopen(argv[1], "r");

    while (fgets(buff, 255, archivo))
    {
      if (i % 2 == 0) // en archivo: linea impar
      {

        veccplx[i / 2].re = strtod(buff, NULL);
      }
      else
      {

        veccplx[i / 2].img = strtod(buff, NULL);
      }
      i++;
    }
    printf("-----------------------------------------------------\n");
    complejo temp;
    int j = 0;
    int k = 0;
    for (j = 0; j < ((i / 2) - 1); j++)
    {
      for (k = 0; k < ((i / 2) - 1); k++)
      {
        if (norma_complejo(veccplx[k]) > norma_complejo(veccplx[(k) + 1]))
        {
          temp = veccplx[k];
          veccplx[k] = veccplx[k + 1];
          veccplx[k + 1] = temp;
        }
        if (norma_complejo(veccplx[k]) == norma_complejo(veccplx[k + 1]))
        {
          if (angulo_complejo(veccplx[k]) > angulo_complejo(veccplx[(k) + 1]))
          {
            temp = veccplx[k];
            veccplx[k] = veccplx[k + 1];
            veccplx[k + 1] = temp;
          }
        }
      }
    }

    int l = 0;
    for (l = 0; l < i / 2; l++)
    {
      printf("El complejo %d es: %f + %f i\n", l, veccplx[l].re, veccplx[l].img);
    }
    fclose(archivo);
  }

  return 0;
}
