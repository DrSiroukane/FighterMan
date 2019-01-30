#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <time.h>

#include "Map.h"
#include "Helper.h"
#include "Coordinates.h"
#include "Player.h"

using namespace std;

const int Map::map_height = 25; // number of lines
const int Map::map_width = 100; // number of columns

/**
 * Constructor
 * fill map matrice from file name s
 */
Map::Map(string map_files[], int files_number)
{
    // cout << "map_height " << map_height << endl;
    // cout << "map_width " << map_width << endl;
    monsters_number = 0; // number of monsters
    gifts_number = 0; // number of gifts
    matrice = new char * [map_width]; // map_matrice
    monsters = new Monster[20]; // max monsters = 20
    gifts = new Arm[20]; // max gifts = 20
    current_monster_index = -1; // no monster fighting
    current_gift_index = -1; // no monster fighting
    b_fight = false; // no fight yet
    b_picked_gift = false; // player not picking gift
    game_over = false;
    game_status = 0;
    vision_length = Coordinates(4,15);
    
    levels_number = files_number; // number of levels
    levels_map = map_files; // map level files name
    current_level = 0; // map level
    setMap(levels_map[current_level]); // set first map
}

/**
 * Method that return map matrice
 * 
 * @return
 */
char **Map::getMap()
{
    return matrice;
}

/**
 * Method that set Map into matrice from file(s)
 * 
 * @param s 
 */
void Map::setMap(string s){
    monsters_number = 0; // number of monsters
    // cout << "string s = " << s << endl;
    string line;
    ifstream myfile(s);
    int i = 0;
    if (myfile.is_open())
    {
        while ( getline (myfile, line) )
        {
            // cout << "read line " << i << endl;
            char * writable = new char[line.size() + 1];
            copy(line.begin(), line.end(), writable);
            writable[line.size()] = '\0';
            matrice[i] = writable;
            for(int j=0; j<map_width; j++){
                //cout << writable[j];
                if(Helper::MONSTER_I == Helper::getType(writable[j])){
                    Coordinates c(i,j);
                    Monster m; // create monster
                    Arm a; // create his arm
                    Arm gift; // create hidden gift
                    
                    if(Helper::MONSTER[0] == matrice[i][j]){
                        m.setHealth(20*current_level);
                        m.setProtectionPower(5*current_level);
                        
                        a.setHealth(2*current_level);
                        a.setProtectionPower(5*current_level);
                    }else{
                        m.setHealth(30*current_level);
                        m.setProtectionPower(5*current_level);
                        
                        a.setHealth(5*current_level);
                        a.setProtectionPower(7*current_level);
                    }
                    
                    srand(time(NULL));
                    gift.setHealth(rand() % 15); // health power
                    gift.setProtectionPower(rand() % 10); // protection power
                    
                    m.setArm(a); // set monster arm
                    m.setGift(gift); // set monster hidden gift
                    m.setCoordinates(&c); // set monster coordinates
                    
                    monsters[monsters_number++] = m;
                    // m.printData();
                    // cout << "monster found at ( " << c.x << " , " << c.y << ") " << endl;
                }
            }
            // cout << endl;
            i++;
            // cout << "go read line " << i << endl;
        }
        myfile.close();
        // cout << "monsters_numbers " << monsters_number << endl;
    }
}

/**
 * Method that print map
 */
void Map::printMap(){
    if(game_status == 0){
        cout << "****************************************************************************************************" << endl;
        cout << "\t\tMap level \t\t\t\t\t(" << (current_level + 1) << ")" << endl;
        cout << "\t\tMap Monsters Numbers \t\t\t\t(" << monsters_number << ")" << endl;
        cout << "\t\tMap Current Gifts Number \t\t\t(" << gifts_number << ")" << endl;
        // cout << "****************************************************************************************************" << endl;
        
        player->printData();
        
        if(vision_length.x == 0){ // print all map
            // for (int i = 0; i < map_height; i++)
            for (int i = 0; i < map_height; i++)
            {
                cout << matrice[i] << endl;
            }
        }else{ // print map depend on vision length
            Coordinates *p_c = player->getCoordinates();
    		int i_b = (p_c->x - vision_length.x);
            int i_f = (p_c->x + vision_length.x);
            if(i_b < 0){
                i_b = 0;
                i_f = 2 * vision_length.x + 1;
            }else if(map_height < i_f){
                i_b = map_height - 2 * vision_length.x;
                i_f = map_height;
            }
            
            int j_b = (p_c->y - vision_length.y);
            int j_f = (p_c->y + vision_length.y);
            if(j_b < 0){
    		    j_b = 0;
    		    j_f = 2 * vision_length.y + 1;
    		}else if(map_width < j_f){
    		    j_b = map_width - 2 * vision_length.y;
    		    j_f = map_width;
    		}
    		
            cout << "\t\t\t________________________________" << endl;
            for (int i=i_b; i<i_f; i++){
                cout << "\t\t\t";
                for (int j=j_b; j<j_f; j++){
                   cout << matrice[i][j];
                }
                // cout << "|";
                cout << endl;
            }
            cout << "\t\t\t________________________________" << endl;
        } 
    }else{
        gameStatus();
        player->printData();
    }
        
}

/**
 * Method that print monsters coordinates
 * Which they are in a map
 */
void Map::printMonsters(){
    cout << "print monsters " << monsters_number << endl;
    for(int i=0; i<monsters_number; i++){
        // Coordinates *c = monsters[i].getCoordinates();
        // cout << "Monster number " << i << "\n x= " << c->x << "\n y= " << c->y << endl;
        monsters[i].printData();
        // cout << endl;
    }
}

/**
 * Method that inject player in a map for first time 
 * 
 */
void Map::setPlayerInGame(Player *p){
    player = p;
    // player->setCurrentMap(this);
    Coordinates *c = player->getCoordinates();
    stand_char = matrice[c->x][c->y]; // set stand char
    matrice[c->x][c->y] = player->getLook();
}

/**
 * Method to set player action in a map
 * 
 */
void Map::setPlayerAction(int a){
    // cout << " begin map set player action " << a << endl;

    player->setAction(a);

    if(a < 8){ // move action
        // cout << "move" << endl;
        Coordinates next_move = *player->getCoordinates();
        // if(!player->getMoved()){ // a in [0, 7]
            if((a == Helper::UP_LEFT) || (a == Helper::UP) || (a == Helper::UP_RIGHT)){ // go up
                next_move.x--;
            }
            
            if((a == Helper::DOWN_LEFT) || (a == Helper::DOWN) || (a == Helper::DOWN_RIGHT)){ // go down
                next_move.x++;
            }
    
            if((a == Helper::UP_LEFT) || (a == Helper::LEFT) || (a == Helper::DOWN_LEFT)){ // go left
                next_move.y--;
            }
    
            if((a == Helper::UP_RIGHT) || (a == Helper::RIGHT) || (a == Helper::DOWN_RIGHT)){ // go right
                next_move.y++;
            }
            
            Coordinates *c = player->getCoordinates();
            int type = Helper::getType(matrice[next_move.x][next_move.y]);
            if(2 < type){
                // cout << Helper::STAIR_I << "=" << type << endl;
                if((Helper::STAIR_I == type) && (monsters_number == 0)){
                    current_level++; // go to next level
                    if(current_level < levels_number){
                        setMap(levels_map[current_level]);
                        c->x = 19;
                        c->y = 88;
                        player->setLook('^');
                    }else{
                        game_status = 1;
                    }
                }
                
                if((Helper::STAIR_I != type) || (monsters_number == 0)){
                    matrice[c->x][c->y] = stand_char;
                    stand_char = matrice[next_move.x][next_move.y];
                    c->x = next_move.x;
                    c->y = next_move.y;
                }
            }
            matrice[c->x][c->y] = player->getLook();
            
            // player->setMoved(true);
        // }
    }else if(a == Helper::FIGHT){ // fight action
        // cout << "fight" << endl;
        Coordinates c = player->getFront();
        // cout << "Player front coordinates x= " << c.x << " y= " << c.y << endl;
        // cout << matrice[c.x][c.y] << endl;
        if(Helper::MONSTER_I == Helper::getType(matrice[c.x][c.y])){
            b_fight = true;
            int current_monster_index = getMonsterIndex(c);
            // cout << "current_monster_index " << current_monster_index << endl;
            fight(current_monster_index);
        }else{
            b_fight = false;
        }
    }else if(a == Helper::PICK_GIFT){ // pick gift
        // cout << "pick gift" << endl;
        if(stand_char == '$'){
            b_picked_gift = true;
            pickGift(getGiftIndex(*player->getCoordinates()));
            stand_char = '.';
        }else{
            b_picked_gift = false;
        }
    }
    
    // cout << " end map set player action" << a << endl;
    
}

/********************************************/

int Map::getMonsterIndex(Coordinates cc){
    // cout << "monsters number " << endl;
    for(int i=0; i<monsters_number; i++){
        Coordinates *c = monsters[i].getCoordinates();
        // monsters[i].printData();
        // cout << "(" << c->x << " == " << cc.x << ") && (" << c->y << " == " << cc.y << ")" << endl;
        if((c->x == cc.x) && (c->y == cc.y)){
            return i;   
        }
    }
    return -1;
}

void Map::fight(int i){
    // cout << "im in fight method " << i << endl;
    current_monster_index = i;
    player->setShot(monsters[i].getArm());
    monsters[i].setShot(player->getArm());
    
    if(player->getHealth() <= 0){
        b_fight = false;
        game_over = true;
        game_status = -1;
    }
    
    if(monsters[i].getHealth() <= 0){
        Arm *a = monsters[i].getGift(); // get monster hidden gift
        matrice[monsters[i].getCoordinates()->x][monsters[i].getCoordinates()->y] = '$';
        a->setCoordinates(monsters[i].getCoordinates()); // give gift monster coordinates
        gifts[gifts_number++] = *a; // add gift to the list
        monsters[i] = monsters[--monsters_number]; // let last monster take the dead one place & decrement monsters number
        current_monster_index = -1;
        b_fight = false;
    }
}

bool Map::checkFight(){
    return b_fight;
}

void Map::printMonsterData(){
    // cout << "im in print monster method " << current_monster_index << endl;
    if(current_monster_index != -1){
        monsters[current_monster_index].printData();
    }
}

/********************************************/

int Map::getGiftIndex(Coordinates cc){
    for(int i=0; i<gifts_number; i++){
        Coordinates *c = gifts[i].getCoordinates();
        if((c->x == cc.x) && (c->y == cc.y)){
            return i;   
        }
    }
    return -1;
}

void Map::pickGift(int i){
    picked_gift = &gifts[i];
    if(picked_gift->getUseDistance() == -1){ // bomb
        player->setShot(picked_gift);
        if(player->getHealth() <= 0){
            game_over = true;
        }
    }else if(picked_gift->getUseDistance() == 0){ // energy
        player->setEnergy(picked_gift);
    }else{ // arm
        player->addArm(*picked_gift);
    }
    gifts[i] = gifts[--gifts_number]; // let last gift take the picked one place & decrement gifts number
}

bool Map::checkPickGift(){
    return b_picked_gift;
}

void Map::printGiftData(){
    // cout << "im in print gift method " << current_monster_index << endl;
    if(b_picked_gift){
        picked_gift->printData();
    }
    b_picked_gift = false;
}

/********************************************/

bool Map::checkGameOver(){
    return game_over;
}

/*void Map::gameOver(){
    cout << "****************************************************************************************************\n" << endl;
    cout << "\t\t\t\t\tgame over\n" << endl;
    cout << "****************************************************************************************************" << endl;
}*/

void Map::gameStatus(){
    if(game_status == -1){ // game over
        cout << "****************************************************************************************************\n" << endl;
        cout << "\t\t\t\t\tgame over\n" << endl;
        // cout << "****************************************************************************************************" << endl;
    }else if(game_status == 1){ // end game
        cout << "****************************************************************************************************\n" << endl;
        cout << "\t\t\t\t\tend game\n" << endl;
        // cout << "****************************************************************************************************" << endl;
        game_over = true;
    }
}