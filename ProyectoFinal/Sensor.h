#ifndef _SENSOR_H
#define _SENSOR_H

#include<vector>

class Sensor {
public: 
    
virtual void setdato(int dat);
    
std::vector<int> getdato();
    
float getprom();
    
int getmin();
    
int getmax();
    
Sensor();

Sensor(int a);
    

void setmues(int a);

virtual ~Sensor();
protected: 
    std::vector<int> _dato;
    int _muestreo;
    float _prom;
    int _min;
    int _max;
};

#endif //_SENSOR_H