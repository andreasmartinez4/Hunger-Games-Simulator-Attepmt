/*
 * Andreas Martinez
 * 12.17.2019
 * This class holds all the information and interactions between weapons. It will house a player weapon, aswell as a weapon for each of the opponents.
 */

#include "Weapon.h"

using namespace std;


Weapon::Weapon()
{

}

Weapon::Weapon(string n, bool isMeele, double dmg, double spd, double rnge)
{
    name = n;
    damage = dmg;
    speed = spd;
    range = rnge;
}
