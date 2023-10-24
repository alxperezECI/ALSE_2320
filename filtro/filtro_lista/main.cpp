#include <iostream>
#include <fstream>
#include <string>
#include "Filtro.h"

using namespace std;

int main(int argc, char** argv){

    int _ventana = 5;

    // El problema es abrir un archivo y guardar los resultados en otro.
    // Primero habro el archivo. Asumo que la ruta será pasado por la consola.

    if( argc < 2){
        cout << "Please provide the path to file that contains the data." << endl;
        cout << "The file with the output will be placed in the same folder." << endl;
        return -1;
    }

    if( argc == 3 ) _ventana = atoi( argv[2] );
    cout << "Probando un filtro de media de tamaño " << _ventana << "." << endl;

    string path = argv[1];
    ifstream archIn;
    archIn.open( path );

    cout << "Se abrirá el archivo: " << path << endl;

    if(archIn.is_open()){
        // Aquí va el codigo que se va a hacer para leer el archivo
        ofstream archOut;
        archOut.open("output.txt");
        if( archOut.is_open() ){
            Filtro filtro( _ventana );
            float _dato;
            do{
              getline(archIn, path);
              _dato = atof( path.c_str() ) ;
              _dato = filtro.salida_filtro( _dato );
              archOut << _dato << endl;
            }while(!archIn.eof());
            archOut.close();
        }
    }

    archIn.close();
    return 0;
}
