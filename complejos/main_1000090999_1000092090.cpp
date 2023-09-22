#include <stdio.h>
#include <math.h>
#include <fstream>
#include <iostream>

using namespace std;

struct complejo{
	double re;
	double im;
};

double norma_complejo(complejo c){
  return sqrt(c.re * c.re + c.im *  c.im);
}
double angulo_complejo(complejo c){
  return atan2 ( c.im , c.re );
}

int main(int argc, char** argv){
  if( argc < 2){
    printf("Debe pasar el path del archivo de los datos de entrada.\n");
    return 1;
  }else{
    printf("Se abrirá el archivo %s\n", argv[1]);
    char buff[255];
    // vector complejos
    complejo veccplx[50];
    complejo suma;
    suma.re=0;
    suma.im=0;
    FILE * archivo = fopen( argv[1], "r" );
    double numero;
    int i=0;
    int num=0;
    while ( fgets(buff, 255, (FILE*) archivo )){
    numero = strtod( buff, NULL );
    if (i%2 == 0){
      veccplx[num].re = numero;
      suma.re += veccplx[num].re;
    }else{
      veccplx[num].im = numero;
      suma.im += veccplx[num].im;
      num++;
    }
    i++;
    }
    for (int j=0;j<num;j++){	
	   cout << veccplx[j].re<< "+" << veccplx[j].im << "j" << endl;
	   cout << "La magnitud del complejo es: " << norma_complejo(veccplx[j]) << endl;
	   cout << "El angulo del complejo es: " << angulo_complejo(veccplx[j]) << " rad" <<endl<<endl;
    }
    cout <<"El promedio es: "<<suma.re/num<<"+"<<suma.im/num<<endl;
  }

  return 0;
}
