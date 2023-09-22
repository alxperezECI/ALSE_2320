#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fstream>

struct complejo{
  double re;
  double img;
};


double norma_complejo(complejo c){
  return sqrt( c.re * c.re  + c.img * c.img);
}

double angulo_complejo(complejo c){
  return atan2( c.img , c.re );
}


int main(int argc, char** argv){
  if( argc < 2){
    printf("Debe pasar el path del archivo de los datos de entrada.\n");
    return 1;
  }else{
    printf("Se abrirá el archivo %s\n", argv[1]);
    char buff[255];
    // voy a crear un vector de complejos
    complejo veccplx[50];
    int i = 0;
    FILE * archivo = fopen( argv[1], "r" );
    while ( fgets(buff, 255, (FILE*) archivo )){
      if( i%2 == 0 )
        veccplx[i/2].re = strtod( buff, NULL );
      else
        veccplx[i/2].img = strtod( buff, NULL );

      i++;
    }
  }

  return 0;
}
