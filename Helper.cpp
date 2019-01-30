#include <iostream>

using namespace std;

#include "Helper.h"

const char Helper::WALL[] = {'-', '|'}; // 0
const char Helper::FREE_SPACE[] = {' '}; // 1
const char Helper::MONSTER[] = {'i', 'I'}; // 2
const char Helper::FLOOR[] = {'.'}; // 3
const char Helper::CORRIDOR[] = {'#'}; // 4
const char Helper::STAIR[] = {'='}; // 5
const char Helper::REWARD[] = {'$'}; // 6

const int Helper::WALL_I = 0;
const int Helper::FREE_SPACE_I = 1;
const int Helper::MONSTER_I = 2;
const int Helper::FLOOR_I = 3;
const int Helper::CORRIDOR_I = 4;
const int Helper::STAIR_I = 5;
const int Helper::REWARD_I = 6;

const int Helper::UP_LEFT = 0;
const int Helper::UP = 1;
const int Helper::UP_RIGHT = 2;
const int Helper::LEFT = 3;
const int Helper::RIGHT = 4;
const int Helper::DOWN_LEFT = 5;
const int Helper::DOWN = 6;
const int Helper::DOWN_RIGHT = 7;
const int Helper::FIGHT = 8;
const int Helper::PICK_GIFT = 9;
const int Helper::SWITCH_ARM = 10;

const int Helper::KEYS_NUMBER = 11;
const int Helper::QWERT = 0;
const int Helper::AZERT = 1;
int Helper::keyboard = 0;

const char Helper::QWERT_KEYS[] = {'q','w','e','a','d','z','s','c','f','x', 'r'}; // 0
const char Helper::AZERT_KEYS[] = {'a','z','e','q','d','w','s','c','f','x', 'r'}; // 1

Helper::Helper()
{
    //ctor
}

/**
 * Method that return what is the char type
 * 
 * 0: wall {'-', '|'}
 * 1: free_space {' '}
 * 2: ground {'.'}
 * 3: corridor {'#'}
 * 4: stair {'='}
 * 5: monster {'i', 'I'}
 * 6: reward {'$'}
 * -1: else
 *
 * @param  c
 * @return
 */
int Helper::getType(char c)
{
    // cout << c << endl;
    if((c == WALL[0]) || (c == WALL[1])){
        return WALL_I;
    }else if(c == FREE_SPACE[0]){
        return FREE_SPACE_I;
    }else if((c == MONSTER[0]) || (c == MONSTER[1])){
        return MONSTER_I;
    }else if(c == FLOOR[0]){
        return FLOOR_I;
    }else if(c == CORRIDOR[0]){
        return CORRIDOR_I;
    }else if(c == STAIR[0]){
        return STAIR_I;
    }else if(c == REWARD[0]){
        return REWARD_I;
    }else{
        return -1;
    }
}

/**
 * Method to set user keyboard configuration
 */
void Helper::setKeyboard(int k){
    if(k == 0){
        keyboard = QWERT;
    }else{
        keyboard = AZERT;
    }
}


/**
 * Method to return code of pressed key
 */
int Helper::getKeyCode(char c){
    switch(keyboard){
        case 0:
            for(int i=0; i< KEYS_NUMBER; i++){
                if(c == QWERT_KEYS[i]){
                    return i;
                }
            }
            break;
        default:
            for(int i=0; i< KEYS_NUMBER; i++){
                if(c == AZERT_KEYS[i]){
                    return i;
                }
            }
            break;
    }
    
    return -1;
}
