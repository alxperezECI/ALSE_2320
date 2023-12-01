#include "Sensor.h"

void Sensor::setdato() {
}

std::vector<int> Sensor::getdato() {
    return _dato;
}


float Sensor::getprom() {
    for (int i = 0; i < _dato.size(); i++) {
        _prom += _dato[i];
    }
    return _prom/_dato.size();
}

int Sensor::getmin() {
    _min = _dato[0];
    for (int i = 0; i < _dato.size(); i++) {
        if (_dato[i] < _min) {
            _min = _dato[i];
        }
    }
    return _min;
}


int Sensor::getmax() {
    _max = _dato[0];
    for (int i = 0; i < _dato.size(); i++) {
        if (_dato[i] > _max) {
            _max = _dato[i];
        }
    }
    return _max;
}

Sensor::Sensor() {
    _prom = 0;
    _min = 0;   
    _max = 0;
}


Sensor::~Sensor() {;
}