#include<iostream>
#include <sstream>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 
#include <string>

using namespace std;

int main(int argc, char**argv){
    if (argc<2){
        cout<<"Debe pasar el nombre de la base de datos y el periodo de adquisión"<<endl;
        return 1;
    }
    return 0;
}