#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include<complex>

using namespace std;


bool ordenar (complex<double> c[],int& tam){
    bool flag;
    do{
        flag=false;
        for (int i=0;i<tam-1;i++){
            if (arg(c[i])>arg(c[i+1])){
                complex<double> aux=c[i];
                c[i]=c[i+1];
                c[i+1]=aux;
                flag=true;
            }
            else if(arg(c[i])==arg(c[i+1]))
            {
                if (abs(c[i])>abs(c[i+1])){
                    complex<double> aux=c[i];
                    c[i]=c[i+1];
                    c[i+1]=aux;
                    flag=true;
                }
            }   
        }
    }while (flag==true);
    return true; 
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

    complex<double> vec [i/2];

    i=0;
    int num=0;
    fclose(archivo);
    archivo = fopen( argv[1], "r" );
    while ( fgets(buff, 255, (FILE*) archivo )){
        if (i%2==0){
            vec[num].real(strtod(buff,NULL));
        }else {
            vec[num].imag(strtod(buff,NULL));
            num++;
        }
        i++;
    }
    double reprom=0;
    double improm=0;
    for (int j=0;j<num;j++){
        if (vec[j].imag()<0){
            cout<<"El complejo "<<j+1<<" es: "<<vec[j].real()<<vec[j].imag()<<"j";
        }
        else{
            cout<<"El complejo "<<j+1<<" es: "<<vec[j].real()<<"+"<<vec[j].imag()<<"j";            
        }
        cout<<" | Su Norma es: "<<abs(vec[j]);
        cout<<" | Su ángulo es (en rad): "<<arg(vec[j])<<endl;
        reprom+=vec[j].real();
        improm+=vec[j].imag();
    }
    cout<<"El promedio de los números complejos es: "<<reprom/num<<"+j"<<improm/num<<endl;

    bool flag=ordenar(vec,num);
    if (flag==true){
        cout<<"Los complejos ordenados son: "<<endl;
        for (int j=0;j<num;j++){
            if (vec[j].imag()<0){
            cout<<vec[j].real()<<vec[j].imag()<<"j"<<endl;
        }
        else{
            cout<<vec[j].real()<<"+"<<vec[j].imag()<<"j"<<endl;            
        }
        }
    }
    else{
        cout<<"No se pudo ordenar"<<endl;
    }
  }
  return 0;
}