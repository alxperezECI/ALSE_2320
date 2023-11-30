#ifndef INT_LUZ_H
#define INT_LUZ_H

#include "sensor.h"

class int_luz : public Sensor
{
public:
    virtual int generarDato();
};

#endif