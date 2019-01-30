#ifndef MAP_H
#define MAP_H

#include "Coordinates.h"
#include "Player.h"
#include "Monster.h"


class Map
{
    public:
        static const int map_height;
        static const int map_width;
        
        Map(std::string[], int);
        char **getMap(); // retrun map matrice
        void setMap(std::string); // set map matrice
        void printMap(); // print map
        void printMonsters(); // print monsters 
        void setPlayerInGame(Player *); // set player in a map
        void setPlayerAction(int); // set player action depend on int in map
        int getMonsterIndex(Coordinates); // get monster index
        void fight(int); // fight with monster number int
        int getGiftIndex(Coordinates); // get gift index
        void pickGift(int); // pick gift int
        bool checkPickGift(); // true if player pick gift
        void printGiftData(); // print gift data
        bool checkGameOver(); // check game over
        bool checkFight(); // true if fight
        void printMonsterData(); // print fighting monster data
        void gameStatus(); // reacte to game status 

    private:
        int levels_number; // number of levels
        std::string *levels_map; // map level files name
        int current_level; // map level
        char **matrice;
        int monsters_number;
        Monster *monsters;
        int gifts_number;
        Arm *gifts;
        Player *player;
        char stand_char; // char which player is standing on it
        bool b_fight; // true if fight
        bool b_picked_gift; // true if player pick a gift
        int current_monster_index; // monster fighting player index
        int current_gift_index; // gift that use stand on it
        Arm *picked_gift; // picked gift
        bool game_over; // game over
        int game_status; // game statue (-1: game over, 0: player alive, 1: end game)
        Coordinates vision_length; // vision distance vector
};

#endif // MAP_H
