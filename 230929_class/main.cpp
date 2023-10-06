#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include <complex>
#include <iostream>


using namespace std;

int main(int argc, char** argv){
  if( argc < 2){
    printf("Debe pasar el path del archivo de los datos de entrada.\n");
    return 1;
  }else{
    printf("Se abrirá el archivo %s\n", argv[1]);
    char buff[255];
    // voy a crear un vector de complejos
    complex<double> veccplx[50];
    int i = 0;
    FILE * archivo = fopen( argv[1], "r" );
    while ( fgets(buff, 255, (FILE*) archivo )){
      if( i%2 == 0 )
        veccplx[i/2].real( strtod( buff, NULL ) );
      else
        veccplx[i/2].imag( strtod( buff, NULL ) );

      i++;
    }
    
   i = i/2;
   for( int j = 0; j<i; j++){
     cout << veccplx[j] << endl; 
     cout << "Magnitud: " << abs( veccplx[j] ) << " y ángulo " << arg( veccplx[j] ) << endl;
     cout << "Su conjugado es: " << conj( veccplx[j] ) << endl;
     cout << veccplx[j] * conj( veccplx[j] ) << endl;
   }

  }

  return 0;
}
