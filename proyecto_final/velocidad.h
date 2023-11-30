#ifndef VELOCIDAD_H
#define VELOCIDAD_H

#include "sensor.h"

class velocidad : public Sensor
{
public:
    virtual int generarDato();
};

#endif