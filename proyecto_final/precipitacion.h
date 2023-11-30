#ifndef PRECIPITACION_H
#define PRECIPITACION_H

#include "sensor.h"

class precipitacion : public Sensor
{
public:
    virtual int generarDato();
};

#endif