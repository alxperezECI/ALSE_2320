#ifndef SENSOR_H
#define SENSOR_H

#include <cstdlib>
#include <ctime>

class Sensor
{
public:
    Sensor();
    virtual int generarDato() = 0;

private:
    int dato;
};

#endif
