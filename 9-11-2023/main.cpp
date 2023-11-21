#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    string sqlstr;

    rc = sqlite3_open("ejercicio.db", &db);

    if (rc != 0)
    {
        fprintf(stderr, "No se puede abrir: %s\n", sqlite3_errmsg(db));
        return (1);
    }
    else
    {
        fprintf(stdout, "DB abierta correctamente\n");
    }

    sqlstr = "CREATE TABLE IF NOT EXISTS horas(Nombre TEXT NOT NULL,"
             "Apellido TEXT NOT NULL, Cedula TEXT NOT NULL,"
             "Horas_acum INTEGER NOT NULL, Dia TEXT NOT NULL );";

    rc = sqlite3_exec(db, sqlstr.c_str(), 0, 0, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return (2);
    }
    else
    {
        fprintf(stdout, "Tabla creada\n");
    }
    string nombre_ = argv[1];
    string apellido_ = argv[2];
    string cedula_ = argv[3];
    string horas_acum_ = argv[4];
    string dia_ = argv[5];
    sqlstr = "INSERT INTO horas (Nombre, Apellido, Cedula, Horas_acum, Dia) "
             "VALUES ('nombre_','apellido_','cedula_','horas_acum','dia_'); ";

    rc = sqlite3_exec(db, sqlstr.c_str(), 0, 0, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout, "Records created successfully\n");
    }
    /////////////////////////////////////////////////////////////////
    sqlite3_close(db);
    return 0;
}
