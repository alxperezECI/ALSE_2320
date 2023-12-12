#include <iostream>
#include <math.h>
#include <fstream>
#include <string>

using namespace std;

double norma_complejo(double re, double im){
    double norm;
        norm=sqrt(pow(re,2)+pow(im,2));
    return norm;
}

double angulo_complejo(double re, double im){
    double ang;
        ang= atan2(im,re);
    return ang;
}


int main(int argc, char** argv){

    if( argc < 2){
    printf("Debe pasar el path del archivo de los datos de entrada.\n");
    return 1;
  }else{
    printf("Se abrirá el archivo %s\n", argv[1]);
    char buff[255];
    FILE * archivo = fopen( argv[1], "r" );
    int i=0;
    while ( fgets(buff, 255, (FILE*) archivo )){
        i++;
    }
    double real[i/2];
    double imagi[i/2];

    i=0;
    int r=0;
    int im=0;
    fclose(archivo);
    archivo = fopen( argv[1], "r" );
    while ( fgets(buff, 255, (FILE*) archivo )){
        if (i%2==0){
            real[r]=strtod(buff,NULL);
            r++;
        }else {
            imagi[im]=strtod(buff,NULL);
            im++;
        }
        i++;
    }
    double reprom=0;
    double improm=0;
    for (int j=0;j<im;j++){
        cout<<"El complejo "<<j+1<<" es: "<<real[j]<<"+j"<<imagi[j];
        cout<<" | Su Norma es: "<<norma_complejo(real[j],imagi[j]);
        cout<<" | Su ángulo es (en rad): "<<angulo_complejo(real[j],imagi[j])<<endl;
        reprom+=real[j];
        improm+=imagi[j];
    }
    cout<<"El promedio de los números complejos es: "<<reprom/im<<"+j"<<improm/im<<endl;
  }
  return 0;
}