/**
 * Project Untitled
 */


#ifndef _SENSOR_H
#define _SENSOR_H

class Sensor {
public: 
    
/**
 * @param dat
 */
void setdato(int dat);
    
int getdato();
    
float getprom();
    
int getmin();
    
int getmax();
    
void Sensor();
    
/**
 * @param a
 */
void Sensor(int a);
    
/**
 * @param a
 */
void setmues(int a);
protected: 
    int[] _dato;
    int _muestreo;
    float _prom;
    int _min;
    int _max;
};

#endif //_SENSOR_H