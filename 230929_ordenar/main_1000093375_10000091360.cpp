#include <iostream>
#include <math.h>
#include <fstream>
#include <string>

using namespace std;

struct complejos{
  double real;
  double imagi;
};


double norma_complejo(double re, double im){
    return sqrt(pow(re,2)+pow(im,2));
}

double angulo_complejo(double re, double im){
    return atan2(im,re);
}

bool ordenar (complejos c[],int& tam){
    bool flag;
    do{
        flag=false;
        for (int i=0;i<tam-1;i++){
            if (angulo_complejo(c[i].real,c[i].imagi)>angulo_complejo(c[i+1].real,c[i+1].imagi)){
                complejos aux=c[i];
                c[i]=c[i+1];
                c[i+1]=aux;
                flag=true;
            }
            else if(angulo_complejo(c[i].real,c[i].imagi)==angulo_complejo(c[i+1].real,c[i+1].imagi))
            {
                if (norma_complejo(c[i].real,c[i].imagi)>norma_complejo(c[i+1].real,c[i+1].imagi)){
                    complejos aux=c[i];
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
    complejos vec[i/2];

    i=0;
    int num=0;
    fclose(archivo);
    archivo = fopen( argv[1], "r" );
    while ( fgets(buff, 255, (FILE*) archivo )){
        if (i%2==0){
            vec[num].real=strtod(buff,NULL);
        }else {
            vec[num].imagi=strtod(buff,NULL);
            num++;
        }
        i++;
    }
    double reprom=0;
    double improm=0;
    for (int j=0;j<num;j++){
        if (vec[j].imagi<0){
            cout<<"El complejo "<<j+1<<" es: "<<vec[j].real<<vec[j].imagi<<"j";
        }
        else{
            cout<<"El complejo "<<j+1<<" es: "<<vec[j].real<<"+"<<vec[j].imagi<<"j";            
        }
        cout<<" | Su Norma es: "<<norma_complejo(vec[j].real,vec[j].imagi);
        cout<<" | Su ángulo es (en rad): "<<angulo_complejo(vec[j].real,vec[j].imagi)<<endl;
        reprom+=vec[j].real;
        improm+=vec[j].imagi;
    }
    cout<<"El promedio de los números complejos es: "<<reprom/num<<"+j"<<improm/num<<endl;

    bool flag=ordenar(vec,num);
    if (flag==true){
        cout<<"Los complejos ordenados son: "<<endl;
        for (int j=0;j<num;j++){
            if (vec[j].imagi<0){
            cout<<vec[j].real<<vec[j].imagi<<"j"<<endl;
        }
        else{
            cout<<vec[j].real<<"+"<<vec[j].imagi<<"j"<<endl;            
        }
        }
    }
    else{
        cout<<"No se pudo ordenar"<<endl;
    }
  }
  return 0;
}