#ifndef _SENSOR_H
#define _SENSOR_H

#include<vector>

enum sensor{
    humedades=1,
    luces,
    temperaturas,
    lluvias,
    vientos,
    velocidades
};

class Sensor {
public: 
    
virtual void setdato();
    
std::vector<int> getdato();
    
float getprom();
    
int getmin();
    
int getmax();
    
Sensor();

virtual ~Sensor();
protected: 
    std::vector<int> _dato;
    float _prom;
    int _min;
    int _max;
};

#endif //_SENSOR_H