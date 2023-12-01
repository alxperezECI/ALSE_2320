#include <iostream>
#include "dr_viento.h"
#include "humedad.h"
#include "precipitacion.h"
#include "int_luz.h"
#include "temperatura.h"
#include "velocidad.h"
#include "db_sensores.h"

using namespace std;
int main(int argc, char **argv)
{
    dr_viento Sensorviento;
    humedad Sensorhumedad;
    int_luz Sensorluz;
    precipitacion Sensorprecipitacion;
    temperatura Sensortemperatura;
    velocidad Sensorvelocidad;

    int datoviento = Sensorviento.generarDato();
    cout << "Dato generado por dr_viento: " << datoviento << "° Norte" << endl;

    int datohumedad = Sensorhumedad.generarDato();
    cout << "Dato generado por humedad: " << datohumedad << " %" << endl;

    int datoluz = Sensorluz.generarDato();
    cout << "Dato generado por int_luz: " << datoluz << " Lumen" << endl;

    int datoprecipitacion = Sensorprecipitacion.generarDato();
    cout << "Dato generado por precipitacion: " << datoprecipitacion << " mm" << endl;

    int datotemperatura = Sensortemperatura.generarDato();
    cout << "Dato generado por temperatura: " << datotemperatura << "° C" << endl;

    int datovelocidad = Sensorvelocidad.generarDato();
    cout << "Dato generado por velocidad: " << datovelocidad << " m/s" << endl;

    if (argc != 2)
    {
        cerr << "Uso: " << argv[0] << " <path_de_base_de_datos>" << endl;
        return 1;
    }

    string dbPath(argv[1]);
    DBSensores dbSensores(dbPath);

    dbSensores.createTables();

    return 0;
}
