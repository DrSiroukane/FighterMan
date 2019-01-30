#ifndef ARM_H
#define ARM_H

#include "Actor.h"


class Arm : public Actor
{
    public:
        Arm();
        int getUseDistance();
        void printData(); // print arm data

    private:
        int use_distance; // distance of use
};

#endif // ARM_H
