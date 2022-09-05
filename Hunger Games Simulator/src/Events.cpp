#include <iostream>
#include "Events.h"
#include "Weapon.h"
#include "player.h"
#include "Opponent.h"

using namespace std;

Events::Events()
{
    //ctor
}

/// Function to determine if opponent is faster than player
bool Events::isOpponentFaster(Opponent* opp, player* player, bool long_distance)
{
    // Pointers
    double *o_speed = &opp->stats.speed; // Opponent Speed
    double *p_speed = &player->stats.speed; // Player Speed

    if(long_distance)
    {
        // Factor in endurance into the equation
    }
    else
    {
        if(*o_speed-2.0 > *p_speed)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}


/// Function to determine if player is faster than the opponent
bool Events::isPlayerFaster(player* player, Opponent* opp, bool long_distance)
{
    // Pointers
    double *o_speed = &opp->stats.speed; // Opponent Speed
    double *p_speed = &player->stats.speed; // Player Speed

    if(long_distance)
    {
        // Factor in endurance into the equation
    }
    else
    {
        if(*p_speed-2.0 > *o_speed)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

/// This function determines who will get to the weapon fist based on opponent.stats.speed
void Events::whoGetsWeapon(Opponent& opp1, Opponent& opp2, Weapon& weapon)
{
    opp1.displayStats();
    opp2.displayStats();
    if(opp1.stats.speed-1 > opp2.stats.speed) // Gives the weapon to whoever got their first
    {
        opp1.weapon = weapon; // Gives the faster opponent the weapon
        opp1.hasWeapon = true; // Sets weapon status to true
        cout << endl << opp1.stats.name << " has " << weapon.name << endl;
    }
    else if(opp2.stats.speed-1 > opp1.stats.speed)
    {
        opp2.weapon = weapon; // Gives the faster opponent the weapon
        opp2.hasWeapon = true; // Sets weapon status to true
        cout << endl << opp2.stats.name << " has " << weapon.name << endl;
    }
    else
    {
        // fight with fists and stuff
        cout << "FIST FIGHT!!!";
    }
}

/// This function determines who will get the weapon between a player and opponent
void Events::whoGetsWeapon(player& player, Opponent& opp, Weapon& weapon)
{
    // Pointers
    double *o_speed = &opp.stats.speed; // Opponent Speed
    double *p_speed = &player.stats.speed; // Player Speed

    cout << "\nTest For Speed: " << endl;
    opp.displayStats();

    if(o_speed-2 > p_speed)
    {
        opp.weapon = weapon;
        opp.hasWeapon = true;
    }
    else if(p_speed-2 > o_speed)
    {
        player.weapon = weapon;
        player.hasWeapon = true;
    }
    else
    {


        // fight with fists and stuff
    }

}

/// This function will get a message to describe a successful punch
string Events::successfullAction(int action, player* player, Opponent* opp)
{
    // Pointers
    string* pOppName = &opp->stats.name;
    string heOrShe = getGenderPronouns(opp->isMale);
    string attackArea = generateAttackArea(action);

    switch(action)
    {
    case 1: // Message for Punch
        {
            switch((rand() % 5) + 1)
            {
            case 1:
                return "You successfully land a punch in the " + attackArea + ".";
            case 2:
                return "You throw a punch towards " + *pOppName + "'s " + attackArea + " and it lands!";
            case 3:
                return "You aim for the " + attackArea + " and successfully land a punch.";
            case 4:
                return "Your punch successfully hit " + *pOppName + " in the " + attackArea;
            case 5:
                return "You ball your firsts and aim for the " + attackArea + ". " + *pOppName + " didn't react fast enough, and you successfully landed a punch. ";
            }
        }
        break;
    case 2: // Message for Kick
        {
            switch((rand() % 5) + 1)
            {
            case 1:
                return "You kick " + *pOppName + " in the " + attackArea + " before " + heOrShe + " has time to react.";
            case 2:
                return "You aim for the " + attackArea + " and kick. ";
            case 3:
                return "As " + *pOppName + " is advancing, you go for a kick to their " + attackArea + ". ";
            case 4:
                return "You kick " + *pOppName + " in the " + attackArea + ".";
            case 5:
                return "You aim for the " + attackArea + " and kick.";
            }
        }
        break;
    default: // If input without proper action, just pick a random one
        successfullAction((rand() % 2) + 1, player, opp);
        break;
    }
}

/// This function will return a message about the opponent getting a hit on the player
string Events::opponentSuccessfullAction(int action, int oppAction, Opponent& opp)
{
    // Ptrs & Name Shorteners
    string* pOppName = &opp.stats.name;
    string s_oppAction = getFirstLowercase(getActionName(oppAction), true);
    string s_oppTarget = getFirstLowercase(generateAttackArea(oppAction), true);

    switch((rand() % 2) + 1)
    {
    case 1:
        return "Before you have time to react, " + *pOppName + " " + s_oppAction + "s you in the " + s_oppTarget + ".";
        break;
    case 2:
        return "You decide to go for a " + s_oppAction + ", but " + *pOppName + " reacts faster and " + s_oppAction + "s you in the " + s_oppTarget + ".";
        break;
        /// TODO MORE
    }
}

/// This function generates a random spot on the body where the attack happened for fist fights
string Events::generateAttackArea(int action)
{
    if(1) // Has to be a punch
    {
        switch((rand() % 5) + 1)
        {
        case 1:
            return "Head";
        case 2:
            return "Shoulder";
        case 3:
            return "Chest";
        case 4:
            return "Throat";
        case 5:
            return "Stomach";
        }
    }
    else // Has to be a kick
    {
        switch((rand() % 5) + 1)
        {
        case 1:
            return "Legs";
        case 2:
            return "Groin";
        case 3:
            return "Stomach";
        case 4:
            return "Shin";
        case 5:
            return "Thighs";
        }
    }
}

/// This function returns the name in a string based on the action
string Events::getActionName(int action)
{
    switch(action)
    {
    case 1:
        return "Punch";
    case 2:
        return "Kick";
    case 3:
        return "Block";
    case 4:
        return "dodge";
    case 5:
        return "Duck";
    default:
        return " ";
    }
}

/// Returns a string with a lowercase or capital letter for the first character
string Events::getFirstLowercase(string str, bool isLow)
{

    if(isLow)
    {
        str[0] = tolower(str[0]);
    }
    else
    {
        str[0] = toupper(str[0]);
    }

    return str;
}

/// Returns He or She based on their gender
string Events::getGenderPronouns(bool isMale)
{
    if(isMale)
        return "he";
    else
        return "she";
}

/// Returns a message for the player missing the opponent
string Events::playerMiss(int action, int oppAction, string& oppName)
{
    string playerAction = getFirstLowercase(getActionName(action), true);
    string playerTarget = getFirstLowercase(generateAttackArea(action), true);

    string s_oppAction = getFirstLowercase(getActionName(oppAction), true);

    switch((rand() % 1) + 1)
    {
    case 1:
        return "You go for a " + playerAction + " at " + oppName + " " + playerTarget + ", but unfortunately, " + oppName + " expects that, and " + s_oppAction + ".";
    }
}

/// This function determines how a fight between the player and an opponent will happen
void Events::fight(player* player, Opponent* opp)
{
    // Opponent Pts
    string *pOppName = &opp->stats.name;
    double *pOppHealth = &opp->stats.health;
    double *pOppReactions = &opp->stats.reactions;

    // Player Ptrs
    double *pPlayerHealth = &player->stats.health;
    double *pPlayerReactions = &player->stats.reactions;


    bool isPlayerFirst;

    if(*pOppReactions > *pPlayerReactions)
        isPlayerFirst = false;
    else
        isPlayerFirst = true;


    if(player->hasWeapon)
    {
        if(!opp->hasWeapon)
        {
            // Code that mades opponent run away or fight
        }
        else
        {
            // Main fight code
        }
    }
    else if(opp->hasWeapon)
    {
        // code that gives the user a chance to fight or run
    }
    else
    {
        // fist fight
        bool fight = true;
        int action;

        opp->displayStats();
        cout << endl;

        action = fistFightMenu();

        // Continue the fight while they are still alive, or no one is leaving
        while(fight)
        {
            const int punch = 1;
            const int kick = 2;
            const int block = 3;
            const int dodge = 4;
            const int duck = 5;
            const int leave = 6;

            int opponentAction;
            int variation = (rand() % 3);
            bool isVariation = false;
            bool playerHit = false;
            bool oppHit = false;

            // Gives some variation so the player doesn't always go first
            if(variation == 2)
                isVariation = true;
            else
                variation = false;

            if(*pPlayerHealth < 5)
            {
                cout << "\nYOU ARE GETTING LOW\n";
            }

            if(*pOppHealth < 5)
            {
                cout << "\nOpponent is getting weak\n";
            }

            if(*pOppHealth < 0)
            {
                cout << "\nOpponent is dead\n";
                fight = false;
            }

            // If player is first, give them a fight option, else let them pick after the opponent has show what they are going to do
            if(isPlayerFirst || variation)
            {

                // If the opponent is fast enough, the will attempt to dodge/duck/block, otherwise, they will randomly pick an action
                if(action == 1 || action == 2)
                {
                    if(*pOppReactions > 5.0)
                    {
                        opponentAction = makeRandom(3, 5);
                    }
                    else
                    {
                        opponentAction = makeRandom(1, 5);
                    }
                }
            }
            else
            {
                opponentAction = (rand() % 3) + 1;

                switch((rand() % 1) + 1)
                {
                case 1:
                    cout << "It appears that " << *pOppName << " is going for a " << getFirstLowercase(getActionName(opponentAction), true) << " to your " << getFirstLowercase(generateAttackArea(opponentAction), true);
                    break;
                    /// Add more and get more detailed
                }

                // Display the opponents attack
            }

            cin >> action;
            inputValidation(1, 6, action);

            switch(action)
            {
            case punch:
                {
                    attack(isPlayerFirst, action, opponentAction, player, opp);
                }
                break;
            case kick:
                {
                    attack(isPlayerFirst, action, opponentAction, player, opp);
                }
                break;
            case block:
                {
                    // If player is first

                        // If the opponent is also doing a dodge thing
                        if(opponentAction > 2 && opponentAction < 6)
                        {
                            cout << "You dodged / block / hit for nothing!!!!";
                        }
                        else if(opponentAction == 6)
                        {
                            fight = false;
                        }
                        else
                        {
                            cout << "Attack dodged!!! / Blocked / hit!";
                        }

                    /// Proper follow up like
                    /// if player successfully dodges, they get a better follow up
                    /// if player does a useless dodge, the opponent gets better follow up
                    /// ect...
                }
                break;
            case dodge:
                {


                        // If the opponent is also doing a dodge thing
                        if(opponentAction > 2 && opponentAction < 6)
                        {
                            cout << "You dodged / block / hit for nothing!!!!";
                        }
                        else if(opponentAction == 6)
                        {
                            fight = false;
                        }
                        else
                        {
                            cout << "Attack dodged!!! / Blocked / hit!";

                    }
                }
                break;
            case duck:
                {

                    // If player is first

                        // If the opponent is also doing a dodge thing
                        if(opponentAction > 2 && opponentAction < 6)
                        {
                            cout << "You dodged / block / hit for nothing!!!!";
                        }
                        else if(opponentAction == 6)
                        {
                            fight = false;
                        }
                        else
                        {
                            cout << "Attack dodged!!! / Blocked / hit!";
                        }

                }
                break;
            case leave:
                {
                    fight = false;
                    // leave
                }
                break;
            }
        }

    }
}

/// This function generates the story for a players attack
void Events::attack(bool isPlayerFirst, int action, int opponentAction, player* player, Opponent* opp)
{
    // Player Variables
    double* pPlayerHealth = &player->stats.health;

    // Opponent Variables
    string* pOppName = &opp->stats.name;
    double* pOppHealth = &opp->stats.health;

    // throwing a punch
    if(opponentAction > 2 && opponentAction < 6)
    {
        int success = (rand() % 3) + 1;

        // If its a hit
        if(success == 2)
        {
            switch((rand() % 1) + 1)
            {
            case 1:
                cout << "You go for a punch at their " << generateAttackArea(action) << ". " << *pOppName << " Attempts to dodge, but they are too slow.";
                break;
            }

            *pOppHealth -= makeRandomDouble(1, 0);
        }
        else
        {
            // Displaying that you missed
            cout << playerMiss(action, opponentAction, opp->stats.name);
        }
    }
    else
    {
        // the opp is trying to land a hit also so keep note of that
        if(isPlayerFirst)
        {
            // Display Successful hit and also take health away
            cout << successfullAction(action, player, opp);

            ///TODO: BASED ON OPPONENT STATS MAKE THEM TAKE MORE OR LESS DAMAGE
            *pOppHealth -= makeRandomDouble(1, 0);
        }
        else
        {
            // Whos hit will land first

            if((rand() % 2) + 1 == 2)
            {
                // Display Successful hit and also take health away
                switch((rand() % 2) + 1)
                {
                case 1:
                    cout << *pOppName << " takes a " << getFirstLowercase(getActionName(opponentAction), true) << " at your " << getFirstLowercase(generateAttackArea(action), true) << ". But you were faster and landed a " << getFirstLowercase(getActionName(action), true) << " at their " << getFirstLowercase(generateAttackArea(action), true) << ".";
                    break;
                case 2:
                    cout << *pOppName << " lunges forwards and attempts to " << getFirstLowercase(getActionName(opponentAction), true) << " your " << getFirstLowercase(generateAttackArea(opponentAction), true) << ". " << getFirstLowercase(getGenderPronouns(opp->isMale), false) << " misses, and you follow up with a " << getFirstLowercase(getActionName(action), true) << " to the " << getFirstLowercase(generateAttackArea(action), true) << ".";
                    break;
                    /// MORE

                }

                ///TODO: BASED ON OPPONENT STATS MAKE THEM TAKE MORE OR LESS DAMAGE
                *pOppHealth -= makeRandomDouble(1, 0);
            }
            else
            {
                // Opponent hits first
                cout << opponentSuccessfullAction(action, opponentAction, *opp);
                *pPlayerHealth -= makeRandom(1, 0);
            }
        }
    }
}

/// Function to get the user choice for a fist fight
int Events::fistFightMenu()
{
    int choice;

    cout << "\n[1] Punch Opponent";
    cout << "\n[2] Kick Opponent";
    cout << "\n[3] Block";
    cout << "\n[4] dodge";
    cout << "\n[5] Duck";
    cout << "\n[6] Attempt to flee";

    cout << "\nOption: ";
    cin >> choice;

    choice = inputValidation(1, 6, choice);

    return choice;
}

/// This function will determine who wins in a fight based on their stats
void Events::fight(Opponent& opp1, Opponent& opp2)
{
    double chance_1 = 0.0; // chance for opp1
    double chance_2 = 0.0; // chance for opp2

    // Who is faster
    if(opp1.stats.speed > opp2.stats.speed)
    {
        chance_1 += 1;
    }
    else
    {
        chance_2 += 1;
    }

    // Who has more endurance
    if(opp1.stats.endurance > opp2.stats.endurance)
    {
        chance_1 += 1;
    }
    else
    {
        chance_2 += 1;
    }

    if(opp1.hasWeapon)
    {
        if(opp2.hasWeapon)
        {
            // code to figure out who wins based on better weapon
        }

        if(!opp2.hasWeapon)
        {
            chance_1 += 3; // If first opponent has wpn but second one doesn't, give him a better chance of winning fight
        }
    }

    if(opp2.hasWeapon)
    {
        if(!opp1.hasWeapon)
        {
            chance_2 += 3; // If second opponent has wpn but first one doesn't, give him better chance of winning fight
        }
    }

    if(chance_1 > chance_2)
    {
        cout << opp1.stats.name << " has won the battle" << endl;
        cout << opp2.stats.name << " has died." << endl;
        opp2.stats.isAlive = false;

    }
    else
    {
        cout << opp2.stats.name << " has won the battle" << endl;
        cout << opp1.stats.name << " has died." << endl;
        opp1.stats.isAlive = false;
    }
}

/// Function gets proper input
int Events::inputValidation(int low, int high, int choice)
{
    while(choice < low || choice > high || cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a number that corresponds to the options: ";
        cin >> choice;
    }

    return choice;
}

/// Function to make a random double to two decimal places
double Events::makeRandomDouble(int high, int low)
{
    /// Possibility of going over 10 - make sure the +1 doesnt mean i can get a higher number than 10.0
    int mainNum = (rand() % (high - low + 1)) + low; // Num before decimal

    int decimal = (rand() % (100 - 0 +1)) + low; // Num after decimal

    return static_cast<double>(mainNum+(decimal*.01)); // Converts after decimal to actual decimal, then adds two nums together
}

/// Function to generate a random number between a range
int Events::makeRandom(int high, int low)
{
    int num = (rand() % (high - low + 1)) + low;

    return num;
}
