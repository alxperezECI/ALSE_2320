#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include "Punto.h"
#include <vector>

using namespace std;

int main(int argc, char** argv){

    if( argc < 4){
    cout<<"Debe pasar el path del archivo de los datos de entrada"<<endl;
    return 1;
  }else{
    vector<Punto> vec;
    Punto ini(strtod(argv[2],NULL),strtod(argv[3],NULL));

    int i=0;
    ifstream archivo( argv[1] );
    double x, y;
    if( archivo.is_open() ){
        Punto tmp;
        while ( archivo >> x >> y ){
        tmp.X( x );
        tmp.Y( y );
        vec.push_back( tmp );
    }
    archivo.close();
  }
    double dist,dist1, dist2;
    dist1=1000000.;
    dist2=1000000.;
    int index1=0;
    int index2=0;
    for (i=0;i<vec.size();i++){
        cout<<vec[i]<<endl;
        dist=ini.distancia(vec[i]);
        if (dist<dist1){
            dist2=dist1;
            dist1=dist;
            index1=i;
        }
        else if (dist<dist2){
            dist2=dist;
            index2=i;
        }
    }
    cout<<"Con respecto a: "<<ini<<endl;
    cout<<"El punto más cercano es: "<<vec[index1]<<endl;
    cout<<"La distancia es: "<<dist1<<" m"<<endl;
    cout<<"El segundo punto más cercano es: "<<vec[index2]<<endl;
    cout<<"La distancia es: "<<dist2<<" m"<<endl;
  }
  return 0;
}