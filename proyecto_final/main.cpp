#include <iostream>
#include "dr_viento.h"
#include "humedad.h"
#include "precipitacion.h"
#include "int_luz.h"
#include "temperatura.h"
#include "velocidad.h"

using namespace std;
int main()
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

    return 0;
}
