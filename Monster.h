#ifndef MONSTER_H
#define MONSTER_H

#include "Actor.h"
#include "Arm.h"


class Monster : public Actor
{
    public:
        Monster();
        void setArm(Arm); // set monster arm
        void setGift(Arm); // set hidden gift
        Arm *getArm(); // get monster arm
        Arm *getGift(); // get monster hidden gift
        void printData(); // print monster data

    private:
        Arm arm; // monster arm
        Arm gift; // monster gift

};

#endif // PLAYER_H
