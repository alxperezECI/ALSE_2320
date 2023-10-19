#include <fstream>
#include "vec2d.h"
#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "Debe pasar el path del archivo de los datos de entrada ";
        std::cout << "junto con las coordenadas de consulta.\n" << std::endl;
        return 1;
    }

    double x1, y1, x2, y2;

    x1 = stod(argv[1]);
    y1 = stod(argv[2]);
    x2 = stod(argv[3]);
    y2 = stod(argv[4]);

    Vec2D A(x1, y1), B(x2, y2);
    Vec2D c = A + B;

    return 0;
}
