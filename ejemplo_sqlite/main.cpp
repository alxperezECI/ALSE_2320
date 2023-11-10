#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string>
#include <iostream>
#include <ctime>

using namespace std;

int main(int argc, char *argv[])
{
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    string sql, sqlstr;
    string name = argv[1], lastname = argv[2], cedula = argv[3], hour = argv[4];
    float hours = atof(hour.c_str());

    /* Open database */
    rc = sqlite3_open("test.db", &db);

    if (rc != 0)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return (1);
    }
    else
    {
        fprintf(stdout, "Opened database successfully\n");
    }

    // first table for workers information
    sqlstr = "CREATE TABLE IF NOT EXISTS trabajadores (NOMBRE TEXT NOT NULL,"
             "APELLIDO TEXT NOT NULL, CEDULA INTEGER PRIMARY KEY NOT NULL)";
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sqlstr.c_str(), 0, 0, &zErrMsg);
    // create table
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return (2);
    }
    else
    {
        fprintf(stdout, "Table created successfully\n");
    }

    // second table for insert information
    sqlstr = "CREATE TABLE IF NOT EXISTS horas_extra (CEDULA INTEGER PRIMARY KEY NOT NULL,"
             "HORAS INTEGER NOT NULL, FECHA TEXT )";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sqlstr.c_str(), 0, 0, &zErrMsg);
    // create table
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return (2);
    }
    else
    {
        fprintf(stdout, "Table created successfully\n");
    }

    // insert extra hours, cedula and date
    sql = "INSERT INTO horas_extra (CEDULA,HORAS,FECHA) "
          "VALUES ('cedula','hours','date')";

    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout, "Records created successfully\n");
    }
    // insert information of hours extra and insert workers if not exist
    sql = "INSERT INTO usuario (NOMBRE,APELLIDO,CEDULA) "
          "VALUES ('name','lastname','cedula',)";
    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout, "Records created successfully\n");
    }
    // show information of workers and extra hours

    sqlite3_close(db);
    return 0;
}
