#include <iostream>
#include <curses.h> // biblio to call getch function (used to input clicked key)
#include <cstdlib> // biblio to call system commands
#include <stdio.h>
#include <time.h>

using namespace std;

#include "Map.h"
#include "Actor.h"
#include "Player.h"
#include "Helper.h"

int stages_number = 3;
string f[] = {"stage1.txt", "stage2.txt", "stage3.txt"};
char clicked_char = '\0'; // input char

/**
 * function to scramble stages
 */
void scramble(){
    for(int i=0; i<(stages_number-1); i++){
        srand(time(NULL));
        int j = rand() % stages_number;
        if(i < j){
            string s1 = f[i];
            f[i] = f[j];
            f[j] = s1;
        }
    }
}

int main()
{
    /*
        create a player
    */
    Player player;
    player.setHealth(10);
    player.setProtectionPower(26);
    Coordinates c(15,53); // create coordinates
    player.setCoordinates(&c); // set player in c coordinates
    
    /*
        create arm for player
    */
    Arm arm;
    arm.setHealth(2);
    arm.setProtectionPower(2);

    player.addArm(arm); // give a player arm
    
    scramble(); // scramble stages
    /*for(int i=0; i<3; i++){
        cout << f[i] << endl;
    }*/
    
    Map map(f,stages_number); // create a map with full levels (stages)
    // m.printMonsters();
    map.setPlayerInGame(&player); // set player in map m
    
    system("clear");
    map.printMap();
    
    int code = -1;
    while(true){
        // clicked_char = getchar(); // wait user to click a key and get the clicked key without print it in terminal (lib conio.h does not exist in linux :( )
        do{
            cin >> clicked_char;
            if(clicked_char == '+'){ // click '+' to quit the program
                return 0;
            }
            code = Helper::getKeyCode(clicked_char);
        }while(code == -1);
        // cout << "clicked char is  : " << clicked_char << endl;
        
        system("clear");
        // int code =  Helper::getKeyCode(clicked_char);
        // cout << "Code of clicked key " << code << endl;
        // player.setAction(code);
        // cout << player.getPlayLook() << endl;
        map.setPlayerAction(code);
        // Coordinates *c = player.getCoordinates();
        // cout << "x= " << c->x << " y= " << c->y << endl;
        map.printMap();
        
        // cout << "im out of fight section " << map.checkFight() << endl;
        if(map.checkFight()){
            // cout << "im in fight section" << endl;
            map.printMonsterData();
        }
        
        // cout << "im out of gift section " << map.checkPickGift() << endl;
        if(map.checkPickGift()){
            // cout << "im in gift section" << endl;
            map.printGiftData();
        }
        
        if(map.checkGameOver()){
            break;
        }
    }
    
    return 0;
}