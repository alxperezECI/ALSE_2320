#include<iostream>
#include <sstream>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 
#include <string>
#include "Hum.h"
#include "Luz.h"
#include "Temp.h"
#include "Lluvia.h"
#include "Viento.h"
#include "Vel.h"
#include <unistd.h>

using namespace std;

int sql_ini(){
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    string sqlstr;
    rc = sqlite3_open("sensores.db", &db);
    if( rc != 0 ) {
      fprintf(stderr, "No se puede abrir la base de datos: %s\n", sqlite3_errmsg(db));
      return(1);
    } else {
        fprintf(stdout, "Se abrió correctamente la base de datos\n");
    }

    sqlstr = "CREATE TABLE IF NOT EXISTS humedad (Promedio REAL NOT NULL, Máximo REAL NOT NULL"\
            ", Mínimo REAL NOT NULL , Fecha TEXT NOT NULL);";
    rc = sqlite3_exec(db, sqlstr.c_str(), 0, 0, &zErrMsg);
   
    if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
      return (2);
   }

   sqlstr = "CREATE TABLE IF NOT EXISTS luz (Promedio REAL NOT NULL, Máximo REAL NOT NULL"\
            ", Mínimo REAL NOT NULL , Fecha TEXT NOT NULL);";
    rc = sqlite3_exec(db, sqlstr.c_str(), 0, 0, &zErrMsg);
   
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
      return (2);
   }

    sqlstr = "CREATE TABLE IF NOT EXISTS temperatura (Promedio REAL NOT NULL, Máximo REAL NOT NULL"\
                ", Mínimo REAL NOT NULL , Fecha TEXT NOT NULL);";
    rc = sqlite3_exec(db, sqlstr.c_str(), 0, 0, &zErrMsg);
   
    if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
      return (2);
    }

    sqlstr = "CREATE TABLE IF NOT EXISTS lluvia (Promedio REAL NOT NULL, Máximo REAL NOT NULL"\
                ", Mínimo REAL NOT NULL , Fecha TEXT NOT NULL);";  
    rc = sqlite3_exec(db, sqlstr.c_str(), 0, 0, &zErrMsg);
   
    if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
      return (2);
    }

    sqlstr = "CREATE TABLE IF NOT EXISTS viento (Promedio REAL NOT NULL, Máximo REAL NOT NULL"\
                ", Mínimo REAL NOT NULL , Fecha TEXT NOT NULL);";
    rc = sqlite3_exec(db, sqlstr.c_str(), 0, 0, &zErrMsg);
   
    if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
      return (2);
    }

    sqlstr = "CREATE TABLE IF NOT EXISTS velocidad (Promedio REAL NOT NULL, Máximo REAL NOT NULL"\
                ", Mínimo REAL NOT NULL , Fecha TEXT NOT NULL);";
    rc = sqlite3_exec(db, sqlstr.c_str(), 0, 0, &zErrMsg);
   
    if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
      return (2);
    }
    sqlite3_close(db);
    return 0;
}

int carga_sqlite(int pro, int max, int min, sensor tipo, string fecha){
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    stringstream sql;
    rc = sqlite3_open("sensores.db", &db);
   
    if( rc != 0 ) {
      fprintf(stderr, "No se puede abrir la base de datos: %s\n", sqlite3_errmsg(db));
      return(1);
   } else {
      fprintf(stdout, "Se van a añadir datos\n");
   }
   switch(tipo){
         case humedades:
                sql<<"INSERT INTO humedad (Promedio, Máximo, Mínimo, Fecha) "  \
              "VALUES ("<<pro<<","<<max<<","<<min<<",'"<<fecha<<"'); ";
                break;
          case luces:
                sql<<"INSERT INTO luz (Promedio, Máximo, Mínimo, Fecha) "  \
              "VALUES ("<<pro<<","<<max<<","<<min<<",'"<<fecha<<"'); ";
                break;
          case temperaturas:
                sql<<"INSERT INTO temperatura (Promedio, Máximo, Mínimo, Fecha) "  \
              "VALUES ("<<pro<<","<<max<<","<<min<<",'"<<fecha<<"'); ";
                break;
          case lluvias:
                sql<<"INSERT INTO lluvia (Promedio, Máximo, Mínimo, Fecha) "  \
              "VALUES ("<<pro<<","<<max<<","<<min<<",'"<<fecha<<"'); ";
                break;
          case vientos:
                sql<<"INSERT INTO viento (Promedio, Máximo, Mínimo, Fecha) "  \
              "VALUES ("<<pro<<","<<max<<","<<min<<",'"<<fecha<<"'); ";
                break;
          case velocidades:
                sql<<"INSERT INTO velocidad (Promedio, Máximo, Mínimo, Fecha) "  \
              "VALUES ("<<pro<<","<<max<<","<<min<<",'"<<fecha<<"'); ";
                break;
    }
    rc = sqlite3_exec(db, sql.str().c_str(), 0, 0, &zErrMsg);
    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Datos añadidos\n");
    }
    sql.str(string());
    return 0;
}

int main(int argc, char**argv){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    stringstream fecha;
    if (argc<3){
        cout<<"Debe pasar el nombre de la base de datos y el periodo de adquisión"<<endl;
        return 1;
    }
    if (stoi(argv[2])<5 or stoi(argv[2])>20){
        cout<<"El periodo de adquisición debe ser mayor a 5 y menor a 20"<<endl;
        return 2;
    }

    if (sql_ini()!=0){
        cout<<"Error en la base de datos"<<endl;
        return 3;
    }
    while(true){
        Hum humedad;
        Luz luz;
        Temp temperatura;
        Lluvia lluvia;
        Viento viento;
        Vel velocidad;
        int lim= 60/stoi(argv[2]);
        for (int i=0;i<lim;i++){
            humedad.setdato();
            luz.setdato();
            temperatura.setdato();
            lluvia.setdato();
            viento.setdato();
            velocidad.setdato();
            sleep(stoi(argv[2]));
        }
        int prom,maxi,mini;
        fecha<<1900 + ltm->tm_year;
        fecha<<"-"<<1 + ltm->tm_mon<<"-"<<ltm->tm_mday<<" "<<ltm->tm_hour<<":"<<ltm->tm_min;
        fecha<< ":"<<ltm->tm_sec;
        cout<<fecha.str()<<endl;
        prom=humedad.getprom();
        maxi=humedad.getmax();
        mini=humedad.getmin();
        carga_sqlite(prom,maxi,mini,humedades, fecha.str());
        prom=luz.getprom();
        maxi=luz.getmax();
        mini=luz.getmin();
        carga_sqlite(prom,maxi,mini,luces, fecha.str());
        prom=temperatura.getprom();
        maxi=temperatura.getmax();
        mini=temperatura.getmin();
        carga_sqlite(prom,maxi,mini,temperaturas, fecha.str());
        prom=lluvia.getprom();
        maxi=lluvia.getmax();
        mini=lluvia.getmin();
        carga_sqlite(prom,maxi,mini,lluvias, fecha.str());
        prom=viento.getprom();
        maxi=viento.getmax();
        mini=viento.getmin();   
        carga_sqlite(prom,maxi,mini,vientos, fecha.str());
        prom=velocidad.getprom();
        maxi=velocidad.getmax();
        mini=velocidad.getmin();
        carga_sqlite(prom,maxi,mini,velocidades, fecha.str());
    }
    return 0;

}