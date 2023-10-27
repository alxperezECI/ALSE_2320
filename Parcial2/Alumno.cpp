#include "Alumno.h"
#include <iostream>
#include <cmath>

using namespace std;

Alumno::Alumno(){
    codigo = 0;
    notas[0] = 0;
    notas[1] = 0;
    notas[2] = 0;
    notas[3] = 0;
    notas[4] = 0;
}

Alumno::Alumno(int cod, float n1, float n2, float n3, float n4, float n5){
    codigo = cod;
    notas[0] = n1;
    notas[1] = n2;
    notas[2] = n3;
    notas[3] = n4;
    notas[4] = n5;
}

void Alumno::SetCod(int cod){
    codigo = cod;
}

int Alumno::GetCod(){
    return codigo;
}

void Alumno::SetNotas(float n1, float n2, float n3, float n4, float n5){
    notas[0] = n1;
    notas[1] = n2;
    notas[2] = n3;
    notas[3] = n4;
    notas[4] = n5;
}

float& Alumno::GetNotas(){
    float* ptr = notas;
    return *ptr;
}

Alumno& Alumno::operator+=(const Alumno &b){
    for(int i = 0; i < 5; i++){
        notas[i] += b.notas[i];
    }
    return *this;
}

Alumno& Alumno::operator/=(const float &b){
    for(int i = 0; i < 5; i++){
        notas[i] /= b;
    }
    return *this;
}

float Alumno::Getpromedio(){
    float prom = 0;
    for(int i = 0; i < 5; i++){
        prom += notas[i];
    }
    prom /= 5;
    return prom;
}