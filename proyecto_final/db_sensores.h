#ifndef DB_SENSORES_H
#define DB_SENSORES_H

#include <sqlite3.h>
#include <string>

class DBSensores
{
public:
    DBSensores(const std::string &dbPath);
    ~DBSensores();

    int createTables();
    int insert(int datoviento, int datohumedad, int datoluz, int datoprecipitacion, int datotemperatura, int datovelocidad);

private:
    sqlite3 *db;
    std::string dbPath;
};

#endif
