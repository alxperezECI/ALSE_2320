#inlcude "vec2d.h"

using namespace std;

Vec2D Vec2D::operator+(const Vec2D B)
{
    Vec2D C = Punto::operator+(*this, B);
    return C;
}