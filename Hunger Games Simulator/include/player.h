#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Weapon.h"
#include "Opponent.h"

using namespace std;

class player
{
    public:
        struct stats
        {
            string name;
            double speed;
            double health = 10.0;
            double intelligence;
            double reactions = 7.0;
        };

        stats stats;
        char position[160][50];
        int x = 160/2, y = 50/2;

        bool hasWeapon = false;
        Weapon weapon;

    private:

};

#endif // PLAYER_H
