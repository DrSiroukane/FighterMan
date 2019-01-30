#ifndef PLAYER_H
#define PLAYER_H

#include "Actor.h"
#include "Arm.h"
// #include "Map.h"


class Player : public Actor
{
    public:
        Player();
        char getLook(); 
        void setLook(char);
        void setAction(int); // set player action depend on int command
        Coordinates getFront(); // get player front case coordinates
        void addArm(Arm); // add arm
        void throwArm(int);
        void setEnergy(Arm *); // add energy to player
        void printData(); // print player data
        Arm *getArm(); // get player current arm
        void switchArm(int); // switch between existing arms

    private:
        char player_look; // char that present player in a map ()
        Arm *arms; // list of player arms
        int arms_number; // number of player arms
        int current_arm_index; // index of current player arm
        
        static const char LOOK[]; 
        static const int LOOK_UP; // 0
        static const int LOOK_LEFT; // 1
        static const int LOOK_RIGHT; // 2
        static const int LOOK_DOWN; // 3

};

#endif // PLAYER_H
