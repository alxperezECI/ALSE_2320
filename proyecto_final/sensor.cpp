#include "sensor.h"

Sensor::Sensor()
{
    dato = static_cast<int>(time(0));
    srand(dato);
}