#include <stdio.h>
#include <math.h>
#include <fstream>
#include <iostream>


int main(int argc, char** argv){
  if( argc < 2){
    printf("Debe pasar el path del archivo de los datos de entrada.\n");
    return 1;
  }else{
    printf("Las coordenadas de archivo.txt son:\n");
    char buff[255];
    FILE * archivo = fopen( argv[1], "r" );
    while ( fgets(buff, 255, (FILE*) archivo )){
      printf("%s", buff );
    }
  }
  FILE * archivo = fopen( argv[1], "r" );
  char buff[255];
 
  printf("El valor de X es:  %s\n", argv[2] );
  float x = atof( argv[2] );

  printf("El valor de y es:  %s\n", argv[3] );
  float y = atof( argv[3] );



  fgets(buff, 255, (FILE*) archivo );
  printf("El valor de X1 es:  %s\n", buff );  
  float x1 = atof( buff );  
  fgets(buff, 255, (FILE*) archivo );
  printf("El valor de Y1 es:  %s\n", buff );
  float y1 = atof( buff );
  fgets(buff, 255, (FILE*) archivo );
  printf("El valor de X2 es:  %s\n", buff );
  float x2 = atof( buff );
  fgets(buff, 255, (FILE*) archivo );
  printf("El valor de Y2 es:  %s\n", buff );
  float y2 = atof( buff );
  fgets(buff, 255, (FILE*) archivo );
  printf("El valor de X3 es:  %s\n", buff );
  float x3 = atof( buff );
  fgets(buff, 255, (FILE*) archivo );
  printf("El valor de Y3 es:  %s\n", buff );





  float distance = sqrt(pow((x1-x),2)+pow((y1-y),2));
  float distance = sqrt(pow((x1-x),2)+pow((y1-y),2));
  float distance = sqrt(pow((x1-x),2)+pow((y1-y),2));
  float distance = sqrt(pow((x1-x),2)+pow((y1-y),2));
  printf("La distancia entre los dos puntos es: %f\n", distance);

  



  return 0;
}
