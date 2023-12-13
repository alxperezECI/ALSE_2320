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
                     "temperatura REAL NOT NULL, velocidad REAL NOT NULL, fecha TEXT NOT NULL);";
        }

        rc = sqlite3_exec(db, sqlstr.c_str(), 0, 0, &zErrMsg);

        if (rc != SQLITE_OK)
        {
            fprintf(stderr, "SQLcreate error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
            return 2;
        }
        else
        {
            cout << "la tabla " << i << " ha sido creada" << endl;
        }
    }
    sqlite3_close(db);

    return 0;
}

int DBSensores::insert(int datoviento, int datohumedad, int datoluz, int datoprecipitacion, int datotemperatura, int datovelocidad)
{
    using namespace std;
    char *zErrMsg = 0;
    int rc;
    string sqlstr;

    sqlstr = "INSERT INTO Datos (dr_viento, humedad, int_luz, precipitacion, temperatura, velocidad, fecha) "
             "VALUES (" +
             to_string(datoviento) + ", " + to_string(datohumedad) + ", " + to_string(datoluz) + ", " + to_string(datoprecipitacion) + ", " + to_string(datotemperatura) + ", " + to_string(datovelocidad) + ", datetime('now', 'localtime'));";

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

    return 0;
}

int DBSensores::insertPMMF()
{
    char *zErrMsg = 0;
    int rc;
    string sqlstr;

    for (int o = 1; o < 7; o++)
    {
        if (o == 1)
        {
            sqlstr = "INSERT INTO viento (Promedio, Maximo, Minimo, fecha) VALUES ((SELECT AVG(dr_viento) FROM Datos), (SELECT MAX(dr_viento) FROM Datos), (SELECT MIN(dr_viento) FROM Datos), datetime('now', 'localtime'));";
        }
        else if (o == 2)
        {
            sqlstr = "INSERT INTO humedad (Promedio, Maximo, Minimo, fecha) VALUES ((SELECT AVG(humedad) FROM Datos), (SELECT MAX(humedad) FROM Datos), (SELECT MIN(humedad) FROM Datos), datetime('now', 'localtime'));";
        }
        else if (o == 3)
        {
            sqlstr = "INSERT INTO luz (Promedio, Maximo, Minimo, fecha) VALUES ((SELECT AVG(int_luz) FROM Datos), (SELECT MAX(int_luz) FROM Datos), (SELECT MIN(int_luz) FROM Datos), datetime('now','localtime'));";
        }
        else if (o == 4)
        {
            sqlstr = "INSERT INTO precipitacion (Promedio, Maximo, Minimo, fecha) VALUES ((SELECT AVG(precipitacion) FROM Datos), (SELECT MAX(precipitacion) FROM Datos), (SELECT MIN(precipitacion) FROM Datos), datetime('now','localtime'));";
        }
        else if (o == 5)
        {
            sqlstr = "INSERT INTO temperatura (Promedio, Maximo, Minimo, fecha) VALUES ((SELECT AVG(temperatura) FROM Datos), (SELECT MAX(temperatura) FROM Datos), (SELECT MIN(temperatura) FROM Datos), datetime('now','localtime'));";
        }
        else if (o == 6)
        {
            sqlstr = "INSERT INTO velocidad (Promedio, Maximo, Minimo, fecha) VALUES ((SELECT AVG(velocidad) FROM Datos), (SELECT MAX(velocidad) FROM Datos), (SELECT MIN(velocidad) FROM Datos), datetime('now','localtime'));";
        }

        rc = sqlite3_exec(db, sqlstr.c_str(), 0, 0, &zErrMsg);

        if (rc != SQLITE_OK)
        {
            fprintf(stderr, "SQLinsertmax error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        }
        else
        {
            fprintf(stdout, "PMMF insertados correctamente\n");
        }
    }
    return 0;
}