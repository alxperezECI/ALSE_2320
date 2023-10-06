#include <fstream>
#include "punto.h"
#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char **argv)
{
  if (argc < 2)
  {
    cout << "Debe pasar el path del archivo de los datos de entrada ";
    cout << "junto con las coordenadas de consulta.\n"
         << endl;
    return 1;
  }

  cout << "Se abrirá el archivo: " << argv[1] << endl;
  // char buff[255];
  //  Crear el punto de test llamando el construtor por parámetros
  Punto test(strtod(argv[2], NULL), strtod(argv[3], NULL));
  // voy a crear un vector de puntos
  vector<Punto> vecPuntos;
  Punto tmp; // tmp se contruye con el constructor por omisión
  int i = 0;
  // FILE * archivo = fopen( argv[1], "r" );
  ifstream archivo(argv[1]);
  double x, y;
  if (archivo.is_open())
  {
    while (archivo >> x >> y)
    {
      tmp.X(x);
      tmp.Y(y);
      vecPuntos.push_back(tmp);
    }
    archivo.close();
  }

  double dist, dist1, dist2;
  dist1 = dist2 = 1000000000.;
  int indx1, indx2;
  indx1 = indx2 = 0;

  for (i = 0; i < vecPuntos.size(); i++)
  {
    // std::cout << "( " << vecPuntos[i].X() << ", " << vecPuntos[i].Y() << " )" << std::endl;
    cout << vecPuntos[i];
    dist = test.distancia(vecPuntos[i]);
    cout << ", distancia= " << dist << endl;
    if (dist < dist1)
    {
      dist2 = dist1;
      indx2 = indx1;
      dist1 = dist;
      indx1 = i;
    }
    else if (dist < dist2)
    {
      dist2 = dist;
      indx2 = i;
    }
  }

  cout << "Los dos puntos más cercanos a " << test << " son:" << endl;
  cout << vecPuntos[indx1] << endl;
  cout << vecPuntos[indx2] << endl;

  Punto centroide;
  for (i = 0; i < vecPuntos.size(); i++)
  {
    centroide += vecPuntos[i];
  }

  centroide = centroide / vecPuntos.size();
  cout << "El centroide de los puntos cargados es: " << centroide << endl;
  cout << "La distancia del punto test al centroide: " << test.distancia(centroide) << endl;

  /* 231006: Una vez encontrado el centroide y la distancia al punto de test,
     listar los puntos del archivo que queden inscritos dentro de la circunferencia
     con centro en test y radio = distancia(test, centroide). El archivo deberá
     contener al menos 50 puntos diferentes distribuidos uniformemente en el plano
     XY.
  */
  double radio = test.distancia(centroide);
  cout << "El radio es: " << radio << endl;
  cout << "Los puntos dentro de la circunferencia son: " << endl;

  for (i = 0; i < vecPuntos.size(); i++)
  {
    if (test.distancia(vecPuntos[i]) < radio)
    {
      cout << vecPuntos[i] << endl;
    }
    else if (test.distancia(vecPuntos[i]) == radio)
    {
      cout << vecPuntos[i] << endl;
    }
  }
  return 0;
}
