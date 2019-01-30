#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

#include "Arm.h"
#include "Actor.h"


Arm::Arm() : Actor() {
    // srand(time(NULL));
	use_distance = (rand() % 20) - 1; //
}

int Arm::getUseDistance(){
	return use_distance;
}

void Arm::printData(){
	
    cout << "****************************************************************************************************" << endl;
    if(use_distance == -1){
    	cout << "\t\tArm Type \t\t\t\t\t(Bomb)" << endl;
    	health = -health;
    	protection_power = -protection_power;
    }else if(use_distance == 0){
    	cout << "\t\tArm Type \t\t\t\t\t(Energy)" << endl;
    }else{
    	cout << "\t\tArm Type \t\t\t\t\t(Weapon)" << endl;
    }
    cout << "\t\tArm Health \t\t\t\t\t(" << health << ")" << endl;
    cout << "\t\tArm Protection Power \t\t\t\t(" << protection_power << ")" << endl;
    cout << "****************************************************************************************************" << endl;
	
	// cout << " Arm infos ";
	// cout << "Health (" << health << ") ";
	// cout << "Protection (" << protection_power << ") ";
	// cout << "use distance (" << use_distance << ") ";
} 

/*void Arm::setUseDistance(int u){
	use_distance = u;
}*/
