/*
 * Andreas Martinez
 * 12.27.2019
 * This class will handle all events such as determining who wins in fights, and such.
 */

#ifndef EVENTS_H
#define EVENTS_H

#include <iostream>
#include "Opponent.h"
#include "Weapon.h"
#include "player.h"
#include <limits>

using namespace std;

class Events
{
    public:
        Events(); // Ctor
        bool isPlayerFaster(player*, Opponent*, bool);
        bool isOpponentFaster(Opponent*, player*, bool);
        void whoGetsWeapon(Opponent&, Opponent&, Weapon&);
        void whoGetsWeapon(player&, Opponent&, Weapon&);
        void playerWhoGetsWeapon(player&, Opponent&, Weapon&);
        void fight(Opponent&, Opponent&); // Handles fights between two opponents
        void fight(player*, Opponent*);
        string getRandomDeath();
        string getFightingDeath(Opponent);

    private:
        /// Functions like -> whos strong, faster, smarter so you don't have to class it so much
        int fistFightMenu(); // Menu for fist fighting
        int inputValidation(int, int, int); // Checks if the user used proper input
        int makeRandom(int, int); // Makes a random number
        void attack(bool, int, int, player*, Opponent*); // Kick Or Punch attack
        double makeRandomDouble(int, int); // Generates a random number as a double
        string successfullAction(int, player*, Opponent*);
        string opponentSuccessfullAction(int, int, Opponent&);
        string playerMiss(int, int, string&);
        string generateAttackArea(int);
        string getFirstLowercase(string, bool);
        string getActionName(int);
        string getGenderPronouns(bool);
};

#endif // EVENTS_H
