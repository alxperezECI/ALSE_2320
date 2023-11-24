#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <ostream>
#include <iostream>
#include <sqlite3.h>
#include <string>
#include <ctime>

using namespace std;

int main(int argc, char *argv[])
{
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    string sqlstr;

    rc = sqlite3_open("db_sensores", &db); // nombre base de datos

    if (rc != 0)
    {
        fprintf(stderr, "No se puede abrir la base de datos: %s\n", sqlite3_errmsg(db));
        return (1);
    }
    else
    {
        fprintf(stdout, "Base de datos abierta correctamente\n");
    }

    for (int i = 1; i < 6; i++) // creación tablas
    {
        if (i == 1)
        {
            sqlstr = "CREATE TABLE IF NOT EXISTS viento (Promedio REAL NOT NULL,"
                     "Maximo REAL NOT NULL, Minimo REAL NOT NULL);";
        }
        else if (i == 2)
        {
            sqlstr = "CREATE TABLE IF NOT EXISTS humedad (Promedio REAL NOT NULL,"
                     "Maximo REAL NOT NULL, Minimo REAL NOT NULL);";
        }
        else if (i == 3)
        {
            sqlstr = "CREATE TABLE IF NOT EXISTS luz (Promedio REAL NOT NULL,"
                     "Maximo REAL NOT NULL, Minimo REAL NOT NULL);";
        }
        else if (i == 4)
        {
            sqlstr = "CREATE TABLE IF NOT EXISTS precipitacion (Promedio REAL NOT NULL,"
                     "Maximo REAL NOT NULL, Minimo REAL NOT NULL);";
        }
        else if (i == 5)
        {
            sqlstr = "CREATE TABLE IF NOT EXISTS temperatura (Promedio REAL NOT NULL,"
                     "Maximo REAL NOT NULL, Minimo REAL NOT NULL);";
        }
        else if (i == 6)
        {
            sqlstr = "CREATE TABLE IF NOT EXISTS velocidad (Promedio REAL NOT NULL,"
                     "Maximo REAL NOT NULL, Minimo REAL NOT NULL);";
        }

        rc = sqlite3_exec(db, sqlstr.c_str(), 0, 0, &zErrMsg);

        if (rc != SQLITE_OK)
        {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
            return (3);
        }
        else
        {
            cout << "la tabla " << i << " ha sido creada" << endl;
        }
    }
    sqlite3_close(db);
    return 0;
}
