#include <iostream>
#include <sqlite3.h>
#include <unistd.h>
#include <sstream>
#include <string>

using namespace std;

static int callback( void *data, int argc, char **argv, char **azColName){
    int* local=(int*)data;
    for(int i=0; i<argc; i++){
        local[i]=atoi(argv[i]);
    }
   return 0;
}

int main(int argc, char**argv){
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    string sqlstr;
    rc = sqlite3_open("/home/juanito/Projects/ALSE_2320/ProyectoFinal/Build/sensores.db", &db);
    if( rc != 0 ) {
      fprintf(stderr, "No se puede abrir la base de datos: %s\n", sqlite3_errmsg(db));
      return(1);
    } else {
        fprintf(stdout, "Se abrió correctamente la base de datos\n");
    }

    while(1!=0){
        int res[3];
        cout<<"Humedad: "<<endl;
        sqlstr="SELECT Promedio, Máximo, Mínimo FROM humedad ORDER BY Inde DESC LIMIT 1";
        rc = sqlite3_exec(db, sqlstr.c_str(), callback, (void*)&res, &zErrMsg);
        if( rc != SQLITE_OK ){
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        }
        for (int i=0; i<3; i++){
            cout<<res[i]<<"\t";
        }
        cout<<"Luz: "<<endl;
        sqlstr="SELECT Promedio, Máximo, Mínimo FROM luz ORDER BY Inde DESC LIMIT 1";
        rc = sqlite3_exec(db, sqlstr.c_str(), callback, (void*)&res, &zErrMsg);
        if( rc != SQLITE_OK ){
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        } 
        for (int i=0; i<3; i++){
            cout<<res[i]<<"\t";
        }
        cout<<"Temperatura: "<<endl;
        sqlstr="SELECT Promedio, Máximo, Mínimo FROM temperatura ORDER BY Inde DESC LIMIT 1";
        rc = sqlite3_exec(db, sqlstr.c_str(), callback, (void*)&res, &zErrMsg);
        if( rc != SQLITE_OK ){
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        }
        for (int i=0; i<3; i++){
            cout<<res[i]<<"\t";
        }
        cout<<"Lluvia: "<<endl;
        sqlstr="SELECT Promedio, Máximo, Mínimo FROM lluvia ORDER BY Inde DESC LIMIT 1";
        rc = sqlite3_exec(db, sqlstr.c_str(), callback, (void*)&res, &zErrMsg);
        if( rc != SQLITE_OK ){
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        }
        for (int i=0; i<3; i++){
            cout<<res[i]<<"\t";
        }
        cout<<"Viento: "<<endl;
        sqlstr="SELECT Promedio, Máximo, Mínimo FROM viento ORDER BY Inde DESC LIMIT 1";
        rc = sqlite3_exec(db, sqlstr.c_str(), callback, (void*)&res, &zErrMsg);
        if( rc != SQLITE_OK ){
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        } 
        for (int i=0; i<3; i++){
            cout<<res[i]<<"\t";
        }
        cout<<"Velocidad: "<<endl;
        sqlstr="SELECT Promedio, Máximo, Mínimo FROM velocidad ORDER BY Inde DESC LIMIT 1";
        rc = sqlite3_exec(db, sqlstr.c_str(), callback, (void*)&res, &zErrMsg);
        if( rc != SQLITE_OK ){
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        }
        for (int i=0; i<3; i++){
            cout<<res[i]<<"\t";
        }
        sleep(60);
    }
    return 0;
}