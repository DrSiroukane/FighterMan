#include <iostream>

using namespace std;

#include "Actor.h"
#include "Coordinates.h"
#include "Arm.h"

Actor::Actor()
{
    //ctor
}

void Actor::setHealth(int h){
    health = h;
}

/*void Actor::setAttackPower(int a){
	attack_power = a;
}*/

void Actor::setProtectionPower(int p){
	protection_power = p;
}

void Actor::setCoordinates(Coordinates *c){
    coordinates = *c;
}

int Actor::getHealth(){
    return health;
}

/*int Actor::getAttackPower(){
	return attack_power;
}*/

int Actor::getProtectionPower(){
	return protection_power;
}

Coordinates *Actor::getCoordinates(){
    return &coordinates;
}

void Actor::setShot(Arm *a){
    health = health - a->getHealth();
    protection_power = protection_power - a->getProtectionPower();
    if(protection_power < 0){
        protection_power = 0;
    }
}

void Actor::printData(){
    cout << "Health (" << health << ")" << endl;
    cout << "Protection (" << protection_power << ")" << endl;
}