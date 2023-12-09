#include <iostream>
#include <mysql/mysql.h>

using namespace std;

MYSQL *connection, mysql;
MYSQL_RES *result;
MYSQL_ROW row;
int query_state;

#define HOST "10.10.5.73"  // you must keep the quotes on all four items,
#define USER "cliente"     // the function "mysql_real_connect" is looking for a char datatype,
#define PASSWD "alse@2019" // without the quotes they're just an int.
#define DB "RaspberryTest"

int main(int argc, char **argv)
{
    // initialize database connection
    mysql_init(&mysql);

    // the three zeros are: Which port to connect to, which socket to connect to
    // and what client flags to use.  unless you're changing the defaults you only need to put 0 here

    connection = mysql_real_connect(&mysql, HOST, USER, PASSWD, DB, 0, 0, 0);

    // Report error if failed to connect to database

    if (connection == NULL)
    {
        cout << mysql_error(&mysql) << endl;
        return 1;
    }
    // Send query to database
    query_state = mysql_query(connection, "select * from dato");

    // store result
    result = mysql_store_result(connection);
    while ((row = mysql_fetch_row(result)) != NULL)
    {
        // Print result, it prints row[column_number])
        cout << row[0] << "\t" << row[1] << "\t" << row[2] << "\t"
             << row[3] << "\t" << row[4] << endl;
    }
    return 0;
}
