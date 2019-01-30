#include <iostream>

using namespace std;

#include "Player.h"
#include "Coordinates.h"
#include "Helper.h"

const char Player::LOOK[] = {'^','<','>','v'}; // different look
const int Player::LOOK_UP = 0; // 0
const int Player::LOOK_LEFT = 1; // 1
const int Player::LOOK_RIGHT = 2; // 2
const int Player::LOOK_DOWN = 3; // 3

Player::Player() : Actor(){
    player_look = '^';
    arms_number = 0;
    arms = new Arm[50];
    current_arm_index = 0;
}

/**
 * Method that return player look
 * >: look right, <: look left
 * ^: look up, v: look down
 */
char Player::getLook(){
    return player_look;
}

/**
 * Method to set player look
 */
void Player::setLook(char c){
    player_look = c;
}

/**
 * Method to set Player action and return 
 * the action or -1 if a do not belong to
 * player actions
 * 
 */
void Player::setAction(int a){
    // cout << a << endl;
    if(a != -1){
        if(a < 8){ // move action
            if(a < 3){ // 0 1 2
                player_look = LOOK[LOOK_UP];
            }else if(a == 3){ // 3
                player_look = LOOK[LOOK_LEFT];
            }else if(a == 4){ // 4
                player_look = LOOK[LOOK_RIGHT];
            }else if(a < 8){ // 5 6 7
                player_look = LOOK[LOOK_DOWN];
            }
            
            // moved = false;
            // movePlayer(a);
        }else if(a == Helper::SWITCH_ARM){
            current_arm_index =(current_arm_index + 1) % arms_number;
        }
    }
}

/**
 * Method return the player front case coordinates 
 */
Coordinates Player::getFront(){
    Coordinates c = coordinates;
    if(player_look == LOOK[LOOK_UP]){
        c.x--;
    }else if(player_look == LOOK[LOOK_DOWN]){
        c.x++;
    }else if(player_look == LOOK[LOOK_LEFT]){
        c.y--;
    }else if(player_look == LOOK[LOOK_RIGHT]){
        c.y++;
    }
    
    return c;
}

void Player::addArm(Arm a){
    arms[arms_number++] = a;
}

void Player::throwArm(int i){
    arms[i] = arms[--arms_number];
}

void Player::setEnergy(Arm *a){
    health = health + a->getHealth();
    protection_power = protection_power + a->getProtectionPower();
}

void Player::printData(){
    cout << "****************************************************************************************************" << endl;
    cout << "\t\tPlayer Health \t\t\t\t\t(" << health << ")" << endl;
    cout << "\t\tPlayer Protection Power \t\t\t(" << protection_power << ")" << endl;
    cout << "\t\tPlayer Arms Number \t\t\t\t(" << arms_number << ")" << endl;
    cout << endl;
    cout << "\t\tPlayer Current Arm Number \t\t\t(" << (current_arm_index + 1) << ")" << endl;
    cout << "\t\tPlayer Current Arm Health Shot \t\t\t(" << arms[current_arm_index].getHealth() << ")" << endl;
    cout << "\t\tPlayer Current Arm Protection Power Shot \t(" << arms[current_arm_index].getProtectionPower() << ")" << endl;
    cout << "****************************************************************************************************" << endl;
}

Arm *Player::getArm(){
    return &arms[current_arm_index];
}

void Player::switchArm(int i){
    if(i < arms_number){
        current_arm_index = i;
    }
}