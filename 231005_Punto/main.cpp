#include <fstream>
#include "punto.h"
#include <iostream>
#include <vector>


int main(int argc, char** argv){
  if( argc < 2){
    std::cout << "Debe pasar el path del archivo de los datos de entrada ";
    std::cout << "junto con las coordenadas de consulta.\n" << std::endl;
    return 1;
  }

  std::cout << "Se abrirá el archivo: " << argv[1] << std::endl;
  //char buff[255];
  // Crear el punto de test llamando el construtor por parámetros
  Punto test( strtod( argv[2], NULL ), strtod( argv[3], NULL ) );
  // voy a crear un vector de puntos  
  std::vector<Punto> vecPuntos;
  Punto tmp;   // tmp se contruye con el constructor por omisión
  int i = 0;
  //FILE * archivo = fopen( argv[1], "r" );
  std::ifstream archivo( argv[1] );
  double x, y;
  if( archivo.is_open() ){
    while ( archivo >> x >> y ){
      tmp.X( x );
      tmp.Y( y );
      vecPuntos.push_back( tmp );
    }
    archivo.close();
  }

  double dist,dist1, dist2;
  dist1 = dist2 = 1000000000.;
  int indx1, indx2;
  indx1 = indx2 = 0;

  for( i = 0; i < vecPuntos.size(); i++){
    //std::cout << "( " << vecPuntos[i].X() << ", " << vecPuntos[i].Y() << " )" << std::endl;
    std::cout << vecPuntos[i] ;
    dist = test.distancia ( vecPuntos[i] ); 
    std::cout << ", distancia= " << dist << std::endl;
    if( dist < dist1 ){
      dist2 = dist1;
      indx2 = indx1;
      dist1 = dist;
      indx1 = i;
    }else if( dist < dist2 ){
      dist2 = dist;
      indx2 = i;
    }
  }
 
  std::cout << "Los dos puntos más cercanos a " << test << " son:" << std::endl;
  std::cout << vecPuntos[indx1] << std::endl;
  std::cout << vecPuntos[indx2] << std::endl;

  /* A continuación deben calcular el centroide de los puntos cargados y calcular
     la distacia del punto de test a ese centroide.
     Para ello deben implementar la sobrecarga del operador de suma y del 
     operador división por un escalar.
  */

  return 0;
}
