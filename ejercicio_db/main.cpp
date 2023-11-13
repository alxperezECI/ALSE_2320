#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 
#include <string>
#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

std::string get_current_date() {
  std::time_t now = std::time(nullptr);
  char date_str[11];
  std::strftime(date_str, sizeof(date_str), "%Y-%m-%d", std::localtime(&now));
  return std::string(date_str);
}

int main(int argc, char** argv) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    string sqlstr_1;
    string sqlstr_2;
    string nombre = argv[1];
    string apellido = argv[2];
    string cedula_s = argv[3];
    string horas_s = argv[4];
    string fecha = get_current_date();   
    /* Open database */
    rc = sqlite3_open("test.db", &db);
   
    if( rc != 0 ) {
         fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
          return(1);
    }

    /* Create SQL statement */
    sqlstr_1 = "CREATE TABLE IF NOT EXISTS trabajadores (Cedula INTEGER PRIMARY KEY NOT NULL," \
      "Nombre TEXT NOT NULL, Apellido TEXT NOT NULL);";
    rc = sqlite3_exec(db, sqlstr_1.c_str(), 0, 0, &zErrMsg);
    if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
        return (2);
    }
    sqlstr_2 = "CREATE TABLE IF NOT EXISTS horas_extra (Cedula INTEGER NOT NULL," \
      "horas_extra FLOAT, Fecha TEXT NOT NULL);";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sqlstr_2.c_str(), 0, 0, &zErrMsg);

    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return (3);
    }
    sqlite3_close(db);

    /* Open database */
    rc = sqlite3_open("test.db", &db);

    if( rc != 0 ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(4);
    }

    /* Create SQL statement */
    sqlstr_1 = "INSERT OR IGNORE INTO trabajadores (Cedula, Nombre, Apellido) "  \
      "VALUES ('"+ cedula_s +"','" + nombre + "','" + apellido + "');";
    rc = sqlite3_exec(db, sqlstr_1.c_str(), 0, 0, &zErrMsg);

    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }

    sqlstr_2 =  "INSERT INTO horas_extra (Cedula, horas_extra, Fecha) "  \
      "VALUES ('"+ cedula_s +"', '"+ horas_s +"', '"+ fecha +"');";
    
    /* Execute SQL statement */

    rc = sqlite3_exec(db, sqlstr_2.c_str(), 0, 0, &zErrMsg);

    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return (6);
    }

    sqlstr_1 = "SELECT Cedula, SUM(horas_extra) FROM horas_extra GROUP BY Cedula;";
    rc = sqlite3_exec(db, sqlstr_1.c_str(), [](void* data, int argc, char** argv, char** colName) -> int {
        printf("\n");
        printf("El trabajador con %s: %s tiene %s horas extra acumuladas\n", colName[0], argv[0], argv[1]);
        return 0;
    }, NULL, &zErrMsg);

    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return (7);
    }
    printf("\n");
    sqlite3_close(db);
    
    return 0;
}
