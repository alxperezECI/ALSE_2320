#ifndef HUMEDAD_H
#define HUMEDAD_H

#include "sensor.h"

class humedad : public Sensor
{
public:
    virtual int generarDato();
};

#endif