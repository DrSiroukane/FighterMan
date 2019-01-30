#include "Coordinates.h"

Coordinates::Coordinates()
{
    //ctor
}

Coordinates::Coordinates(int x1, int y1)
{
    x = x1;
    y = y1;
}

Coordinates::Coordinates(const Coordinates &c)
{
    x = c.x;
    y = c.y;
}
