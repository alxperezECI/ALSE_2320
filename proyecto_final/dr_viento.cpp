#include "dr_viento.h"
#include <cstdlib>
#include <ctime>

dr_viento::Sensor()
{
    std::srand(std::time(0));

    dato = -30 + static_cast<double>(std::rand()) / RAND_MAX * (35 - (-30));
}

double dr_viento::leerDato()
{
    dato += (-1 + static_cast<double>(std::rand()) / RAND_MAX * 2);

    if (dato < -30)
    {
        dato = -30;
    }
    else if (dato > 35)
    {
        dato = 35;
    }

    return dato;
}
