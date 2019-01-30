#ifndef COORDINATES_H
#define COORDINATES_H


class Coordinates
{
    public:
        int x;
        int y;
        Coordinates();
        Coordinates(int x1, int y1);
        Coordinates(const Coordinates &);
};

#endif // COORDINATES_H
