#include <iostream>

using namespace std;

class Alumno{
    private:
        int codigo;
        float notas[5];
        float promedio;
    public:
        Alumno();
        void SetCod(int cod);
        int GetCod();
        void SetNotas(float n1, float n2, float n3, float n4, float n5);
        float& GetNotas();
        Alumno(int cod, float n1, float n2, float n3, float n4, float n5);
        Alumno& operator+=(const Alumno &b);
        Alumno& operator/=(const float &b);
        float Getpromedio();
};