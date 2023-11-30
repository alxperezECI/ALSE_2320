#ifndef DR_VIENTO_H
#define DR_VIENTO_H

#include "sensor.h"

class dr_viento : public Sensor
{
public:
    virtual int generarDato();
};

#endif