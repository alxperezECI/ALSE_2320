#ifndef TEMPERATURA_H
#define TEMPERATURA_H

#include "sensor.h"

class temperatura : public Sensor
{
public:
    virtual int generarDato();
};

#endif