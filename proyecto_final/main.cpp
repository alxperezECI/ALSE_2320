#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
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

    for (int i = 0; i < 5; i++)

        rc = sqlite3_exec(db, sqlstr.c_str(), 0, 0, &zErrMsg);

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

    sqlstr = "CREATE TABLE IF NOT EXISTS sensor (id_medida INTEGER PRIMARY KEY NOT NULL,"
             "Temperatura REAL NOT NULL, Humedad REAL NOT NULL,"
             "Fecha TEXT NOT NULL );";

    rc = sqlite3_exec(db, sqlstr.c_str(), 0, 0, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return (3);
    }
    else
    {
        fprintf(stdout, "Table created successfully\n");
    }

    sqlite3_close(db);
    return 0;
}
