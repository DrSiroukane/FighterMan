#ifndef ACTOR_H
#define ACTOR_H

#include "Coordinates.h"

class Arm;

class Actor
{
    public:
        Actor();
        void setHealth(int);
        void setProtectionPower(int);
		void setCoordinates(Coordinates *);
        int getHealth();
		int getProtectionPower();
		Coordinates *getCoordinates();
		void setShot(Arm *); // shot by arm
		virtual void printData();

    protected:
        int health; // health
        int protection_power; // protection
        Coordinates coordinates; // coordination
};

#endif // ACTOR_H
