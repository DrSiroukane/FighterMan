#include <iostream>

using namespace std;

#include "Monster.h"
#include "Actor.h"

Monster::Monster() : Actor() {
    //ctor
}

void Monster::setArm(Arm a){
    arm = a;
}

void Monster::setGift(Arm a){
    gift = a;
}

Arm *Monster::getArm(){
    return &arm;
}

Arm *Monster::getGift(){
    return &gift;
}

void Monster::printData(){
    cout << "****************************************************************************************************" << endl;
    cout << "\t\tMonster Health \t\t\t\t\t(" << health << ")" << endl;
    cout << "\t\tMonster Protection Power \t\t\t(" << protection_power << ")" << endl;
    cout << "\t\tMonster Arm Health Shot \t\t\t(" << arm.getHealth() << ")" << endl;
    cout << "\t\tMonster Arm Protection Power Shot \t\t(" << arm.getProtectionPower() << ")" << endl;
    cout << "****************************************************************************************************" << endl;
    
    // cout << "\t\tMonster Coordinates (" << coordinates.x << " , " << coordinates.y << ")" << endl;
    
    // cout << "Monster info " << endl;
    // cout << "Health (" << health << ") ";
    // cout << "Protection (" << protection_power << ") ";
    
    // cout << " Arm info ";
    // arm.printData();
    
    // cout << " Gift info ";
    // gift.printData();
}

/*void Monster::setShot(Arm *a){
    health = health - a->getHealth();
    protection_power = protection_power - a->getProtectionPower();
}*/