#ifndef HELPER_H
#define HELPER_H


class Helper
{
    public:
        Helper();
        static int getType(char); // get type of point in map
        static void setKeyboard(int); // set user keyboard type
        static int getKeyCode(char); // get clicked key code

        static const char WALL[]; // 0
        static const char FREE_SPACE[]; // 1
        static const char MONSTER[]; // 2
        static const char FLOOR[]; // 3
        static const char CORRIDOR[]; // 4
        static const char STAIR[]; // 5
        static const char REWARD[]; // 6

        static const int WALL_I; // 0
        static const int FREE_SPACE_I; // 1
        static const int MONSTER_I; // 2
        static const int FLOOR_I; // 3
        static const int CORRIDOR_I; // 4
        static const int STAIR_I; // 5
        static const int REWARD_I; // 6
        
        static const int UP_LEFT; // 0
        static const int UP; // 1
        static const int UP_RIGHT; // 2
        static const int LEFT; // 3
        static const int RIGHT; // 4
        static const int DOWN_LEFT; // 5
        static const int DOWN; // 6
        static const int DOWN_RIGHT; // 7
        static const int FIGHT; // 8
        static const int PICK_GIFT; // 9
        static const int SWITCH_ARM; // 10
        
        static const int KEYS_NUMBER; // game buttons number
        static const int QWERT; // 0
        static const int AZERT; // 1
        static int keyboard; // default value 0
        
        static const char QWERT_KEYS[]; // qwert game keys
        static const char AZERT_KEYS[]; // awert game keys
        
};

#endif // HELPER_H
