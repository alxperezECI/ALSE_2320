#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;


int main(int argc, char** argv){

    if( argc < 4 ){
    printf("Debe pasar los parámetros completos.\n");
    return 1;
  }else{
    printf("Se abrirá el archivo %s\n", argv[1]);
    char buff[255];
    float x [20];
    float y [20];
    int i=0;
    FILE * archivo = fopen( argv[1], "r" );
    while ( fgets(buff, 255, (FILE*) archivo )){
        stringstream input_stringstream(buff);
        string xnum, ynum;
        getline(input_stringstream, xnum, ' ');
        getline(input_stringstream, ynum, ' ');
        x[i] = stoi(xnum);
        y[i] = stoi(ynum);
        i++;
    }
    fclose(archivo);
    int n = 0;
    int n2=0;
    float distanciaM=10000.0;
    float distanciam=10000.0;
    for(i=0;i<20;i++){
        float distancia = sqrt(pow((x[i]-atof(argv[2])),2)+pow((y[i]-atof(argv[3])),2));
        if(distancia<distanciaM){
            distanciaM=distancia;
            n=i;
        }
        else if(distancia<distanciam && distancia>=distanciaM){
            distanciam=distancia;
            n2=i;
        }
        
    }
    cout<<"El punto más cercano es: ("<<x[n]<<","<<y[n]<<")"<<endl;
    cout<<"La distancia es: "<<setprecision(4)<<distanciaM<<" m"<<endl;
    cout<<"El segundo punto más cercano es: ("<<x[n2]<<","<<y[n2]<<")"<<endl;
    cout<<"La distancia es: "<<setprecision(4)<<distanciam<<" m"<<endl;
  }   
  return 0;
}