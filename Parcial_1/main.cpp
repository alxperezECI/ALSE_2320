#include <iostream>
#include <fstream>
#include <string>
#include <complex>
#include <cmath>
#include <stdlib.h>


using namespace std;

struct Punto {
    float x;
    float y;
}p,pun,puntoMasCercano[2];

double calcularDistancia(Punto,Punto);

int main(int argc, char** argv) {
    
    if( argc < 2){
        printf("Debe pasar el path del archivo de los datos de entrada.\n");
        return 1;
    
        
    }else{
        printf("Se abrirá el archivo %s\n", argv[1]);
        
        string linea;
        int contador = 0; // cuenta lineas
        
        FILE * archivo = fopen( argv[1], "r" );
        
        double distanciaMinima[2]={10000,10000}; // cuenta la distancia minima de 1 y de otro y los guarda
        pun.x = atoi(argv[3]);
        pun.y = atoi(argv[4]);
            
        while (getline(archivo, linea)){
            if (sscanf(linea.c_str(), "%f %f", &p.x, p.y) == 2) {
                
                float distancia = calcularDistancia(pun,p);
                
                if(distancia <= distanciaMinima[0]){
                    
                    distanciaMinima[1] = distanciaMinima[0];
                    puntoMasCercano[1] = puntoMasCercano[0];
                    distanciaMinima[0] = distancia;
                    puntoMasCercano[0] = p;
                    
                } else if(distancia <= distanciaMinima[1]){
                    
                    distanciaMinima[1] = distancia;
                    puntoMasCercano[1] = p;
                }
                contador++;
            } else {
                // Error al analizar la línea
                cerr << "Error al analizar la línea " << contador << ": " << linea << endl;
            }
        }
    
    }
    
    cout << "Los dos puntos más cercanos al punto de consulta (" << pun.x << ", " << pun.y << ") son:" << endl;
    //cout << "1er punto: (" << puntoMasCercano[1].x << ", " << puntoMasCercano[1].y << ") - Distancia: " << calcularDistancia(pun, p) << " metros" << endl;
    //cout << "2do punto: (" << puntoMasCercano[2].x << ", " << puntoMasCercano[2].y << ") - Distancia: " << calcularDistancia(pun, p) << " metros" << endl;

    printf("1er punto: (%.3f,%.3f)\tDistancia: %.3f metros.\n",puntoMasCercano[0].x,puntoMasCercano[0].x,calcularDistancia(pun,p));
    printf("2er punto: (%.3f,%.3f)\tDistancia: %.3f metros.\n",puntoMasCercano[1].x,puntoMasCercano[1].x,calcularDistancia(pun,p));
    

    archivo.close(); // Cierra el archivo al finalizar
    return 0; // Retorna 0 para indicar éxito
}

double calcularDistancia(Punto p1,punto p2) {
    float dx = p1.x - p2.x;
    float dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

