#include <stdio.h>
#include <math.h>
#include <fstream>


double norma_complejo(double re, double im){
  double norma;

  return norma;
}

double angulo_complejo(double re, double im){
  double angulo;

  return angulo;
}


int main(int argc, char** argv){
  if( argc < 2){
    printf("Debe pasar el path del archivo de los datos de entrada.\n");
    return 1;
  }else{
    printf("Se abrirá el archivo %s\n", argv[1]);
    char buff[255];
    FILE * archivo = fopen( argv[1], "r" );
    while ( fgets(buff, 255, (FILE*) archivo )){
      printf("%s", buff );
    }
  }

  return 0;
}
