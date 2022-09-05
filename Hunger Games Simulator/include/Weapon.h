/*
 * Andreas Martinez
 * 12.17.2019
 * This class holds all the information and interactions between weapons. It will house a player weapon, aswell as a weapon for each of the opponents.
 */

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <vector>

using namespace std;

class Weapon
{
    public:
        int wpnID;
        string name;
        double damage;
        double speed;
        double range;
        string type = "Weapon";
        Weapon();
        Weapon(string, bool, double, double, double);

    private:


};

#endif // WEAPON_H
