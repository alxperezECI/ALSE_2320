#include "db_sensores.h"
#include <string>
#include <iostream>

DBSensores::DBSensores(const std::string &path) : db(nullptr), dbPath(path)
{
    int rc = sqlite3_open(dbPath.c_str(), &db);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "No se puede abrir la base de datos: %s\n", sqlite3_errmsg(db));
        exit(1);
    }
    else
    {
        fprintf(stdout, "Base de datos abierta correctamente\n");
    }
}

DBSensores::~DBSensores()
{
    sqlite3_close(db);
}

using namespace std;
int DBSensores::createTables()
{
    char *zErrMsg = 0;
    int rc;
    string sqlstr;
    for (int i = 1; i < 8; i++)
    {
        if (i == 1)
        {
            sqlstr = "CREATE TABLE IF NOT EXISTS viento (Promedio REAL NOT NULL,"
                     "Maximo REAL NOT NULL, Minimo REAL NOT NULL, fecha TEXT NOT NULL);";
        }
        else if (i == 2)
        {
            sqlstr = "CREATE TABLE IF NOT EXISTS humedad (Promedio REAL NOT NULL,"
                     "Maximo REAL NOT NULL, Minimo REAL NOT NULL, fecha TEXT NOT NULL);";
        }
        else if (i == 3)
        {
            sqlstr = "CREATE TABLE IF NOT EXISTS luz (Promedio REAL NOT NULL,"
                     "Maximo REAL NOT NULL, Minimo REAL NOT NULL, fecha TEXT NOT NULL);";
        }
        else if (i == 4)
        {
            sqlstr = "CREATE TABLE IF NOT EXISTS precipitacion (Promedio REAL NOT NULL,"
                     "Maximo REAL NOT NULL, Minimo REAL NOT NULL, fecha TEXT NOT NULL);";
        }
        else if (i == 5)
        {
            sqlstr = "CREATE TABLE IF NOT EXISTS temperatura (Promedio REAL NOT NULL,"
                     "Maximo REAL NOT NULL, Minimo REAL NOT NULL, fecha TEXT NOT NULL);";
        }
        else if (i == 6)
        {
            sqlstr = "CREATE TABLE IF NOT EXISTS velocidad (Promedio REAL NOT NULL,"
                     "Maximo REAL NOT NULL, Minimo REAL NOT NULL, fecha TEXT NOT NULL);";
        }
        else if (i == 7)
        {
            sqlstr = "CREATE TABLE IF NOT EXISTS Datos (dr_viento REAL NOT NULL,"
                     "humedad REAL NOT NULL, int_luz REAL NOT NULL, precipitacion REAL NOT NULL,"
                     "temperatura REAL NOT NULL, velocidad REAL NOT NULL);";
        }

        rc = sqlite3_exec(db, sqlstr.c_str(), 0, 0, &zErrMsg);

        if (rc != SQLITE_OK)
        {
            fprintf(stderr, "SQLcreate error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
            return 2;
        }
        /*else
        {
            cout << "la tabla " << i << " ha sido creada" << endl;
        } */
    }
    sqlite3_close(db);

    return 0;
}

using namespace std;
int DBSensores::insert(int datoviento, int datohumedad, int datoluz, int datoprecipitacion, int datotemperatura, int datovelocidad)
{
    char *zErrMsg = 0;
    int rc;
    string sqlstr;
    sqlstr = "INSERT INTO Datos (dr_viento, humedad, int_luz, precipitacion, temperatura, velocidad) "
             "VALUES (" +
             std::to_string(datoviento) + ", " + std::to_string(datohumedad) + ", " + std::to_string(datoluz) + ", " + std::to_string(datoprecipitacion) + ", " + std::to_string(datotemperatura) + ", " + std::to_string(datovelocidad) + ");";

    rc = sqlite3_exec(db, sqlstr.c_str(), 0, 0, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQLinsert error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout, "Registros insertados correctamente\n");
    }

    sqlite3_close(db);
    return 0;
}
