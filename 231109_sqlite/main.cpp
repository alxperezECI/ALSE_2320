#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 
#include <string>
#include <iostream>
#include <sstream>
#include <ctime>

using namespace std;

static int callback1( void *data, int argc, char **argv, char **azColName){  
   bool* local = (bool*)data;
   *local = true;
   return 0;
}

static int callback( void *data, int argc, char **argv, char **azColName){
   int i;
   for (i=0; i<argc; i++){
      cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << "\t";
   }
   cout<<endl;
   return 0;
}

int main(int argc, char** argv){
   time_t now = time(0);
   tm *ltm = localtime(&now);

    if( argc < 4){
        cout << "Debe pasar el Nombre, Apellido, # Cédula, Horas extras"<<endl;
        return 1;
    }
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   string sqlstr;
   stringstream sql;

   rc = sqlite3_open("empresa.db", &db);
   
   if( rc != 0 ) {
      fprintf(stderr, "No se puede abrir la base de datos: %s\n", sqlite3_errmsg(db));
      return(1);
   } else {
      fprintf(stdout, "Se abrió correctamente la base de datos\n");
   }

   sqlstr = "CREATE TABLE IF NOT EXISTS trabajadores (Nombre TEXT NOT NULL, Apellido TEXT NOT NULL" \
            ", Cedula INTEGER PRIMARY KEY);";

   rc = sqlite3_exec(db, sqlstr.c_str(), 0, 0, &zErrMsg);
   
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
      return (2);
   }
   sqlstr = "CREATE TABLE IF NOT EXISTS tiempo (Cedula INTEGER NOT NULL," \
      "Horas REAL NOT NULL, Fecha TEXT NOT NULL, FOREIGN KEY(Cedula) REFERENCES trabajadores(Cedula));";

   rc = sqlite3_exec(db, sqlstr.c_str(), 0, 0, &zErrMsg);

   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
      return (3);
   }
    int ced;
    double time;
    bool flag=false;
    ced= atoi(argv[3]);
    time= atoi(argv[4]);
    sql << "SELECT Cedula FROM trabajadores WHERE Cedula = " << ced << ";";
    
   rc = sqlite3_exec(db, sql.str().c_str(), callback1, (void*)&flag, &zErrMsg);
   if( rc != SQLITE_OK ) {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Operación exitosa\n");
   }
   sql.str(string());
   if (flag==false){
        sql<<"INSERT INTO trabajadores (Nombre, Apellido, Cedula) "  \
          "VALUES ('"<<argv[1]<<"','"<<argv[2]<<"',"<<ced<<"); ";
        rc = sqlite3_exec(db, sql.str().c_str(), 0, 0, &zErrMsg);
        if( rc != SQLITE_OK ){
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        } else {
            fprintf(stdout, "Datos añadidos\n");
        }
   }
   sql.str(string());
   sql<<"INSERT INTO tiempo (Cedula, Horas, Fecha) "  \
          "VALUES ("<<ced<<","<<time<<",'";
      sql<<1900 + ltm->tm_year;
      sql<<"-"<<1 + ltm->tm_mon<<"-"<<ltm->tm_mday<<" "<<ltm->tm_hour<<":"<<ltm->tm_min;
      sql<< ":"<<ltm->tm_sec<<"');";
    rc = sqlite3_exec(db, sql.str().c_str(), 0, 0, &zErrMsg);
    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Datos añadidos\n");
    }
   sql.str(string());

   
   cout<<"Las horas extras de los trabajadores son: "<<endl;
   sqlstr = "SELECT trabajadores.Cedula, sum(Horas) from trabajadores" \
       " left join tiempo on trabajadores.Cedula=tiempo.Cedula GROUP by trabajadores.Cedula;";
   rc = sqlite3_exec(db, sqlstr.c_str(), callback, 0, &zErrMsg);
    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Datos mostrados\n");
    }
   sql.str(string());
   sqlite3_close(db);
   return 0;
}