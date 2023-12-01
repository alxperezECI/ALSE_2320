#include <iostream>
#include "dr_viento.h"
#include "humedad.h"
#include "precipitacion.h"
#include "int_luz.h"
#include "temperatura.h"
#include "velocidad.h"
#include "db_sensores.h"
#include <chrono>
#include <thread>

using namespace std;
int main(int argc, char **argv)
{

    while (true)
    {
        int pathfr = stoi(argv[2]);
        if (argc != 3)
        {
            cout << "No se ingresó un nombre de base de datos o periodo de toma de datos" << endl;
            return 1;
        }
        if (pathfr < 5 || pathfr > 20)
        {
            cout << "El periodo de toma de datos debe ser mayor a 5 segundos y menor a 20 segundos" << endl;
            return 1;
        }
        else
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

            string dbPath(argv[1]);

            DBSensores dbSensores(dbPath);
            cout << "Tomando datos de los sensores" << endl;
            dbSensores.insert(datoviento, datohumedad, datoluz, datoprecipitacion, datotemperatura, datovelocidad);

            this_thread::sleep_for(chrono::seconds(pathfr));
        }
    }

    return 0;
}
