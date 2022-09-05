/*
 * 12.21.2019
 * Andreas Martinez
 * This program will handle all the items for the game. It will include all weapons and other items. It will
 * use the weapon class to create the various weapons.
 */

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <Weapon.h>

using namespace std;

class Item
{
    public:
        Item();
        static const int numOfWeapons = 11;
        // Creating all Weapon Items
        Weapon sword{"Sword", true, 7.0, 3.0, 5.0};
        Weapon short_sword{"Short Sword", true, 5.0, 6.0, 2.5};
        Weapon dagger{"Dagger", true, 3.5, 10.0, 1.0};
        Weapon spear{"Spear", true, 8.0, 2.0, 6.0};
        Weapon axe{"Axe", true, 7.5, 2.5, 4.0};
        Weapon bow{"Bow", false, 0, 0, 0}; // Needs work
        Weapon darts{"Darts", false, 0, 0, 0};
        Weapon shurkins{"Shurkins", false, 0, 0, 0};
        Weapon crossbow{"Cross Bow", false, 0, 0, 0};
        Weapon trident{"Trident", true, 0, 0, 0};
        Weapon slingshot{"Sling Shot", false, 0, 0, 0};
        Weapon weapons[numOfWeapons] = {sword, short_sword, dagger, spear, axe, bow, darts, shurkins, crossbow, trident, slingshot};

    private:
};

#endif // ITEM_H
