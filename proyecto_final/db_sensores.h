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

private:
    sqlite3 *db;
    std::string dbPath;
};

#endif
