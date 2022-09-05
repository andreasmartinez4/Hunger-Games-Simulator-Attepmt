/*
 * Andreas Martinez
 * 12.10.2019
 * This program is a hunger game simulator. This main function will handle every aspect of the story for the game, including the time system and when things happen
 */

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include "player.h"
#include "story.h"
#include "Map.h"
#include "Opponent.h"
#include "Weapon.h"
#include "Item.h"
#include "Events.h"

using namespace std;

int main()
{
    /// TODO: fix the pointer system to be more efficent, don't need to create to many diff pointers, see story(x, x, opponenets for example)

    // Male or Female variable set to true or false
    enum gender {MALE = 0, FEMALE = 1};

    // Seeding the Clock
    unsigned int seed = time(0);
    srand(seed);

    Item allItems();

    // Creating Classes
    player mainCharacter; // Main Player Class

    // Opponents array with gender
  /*  Opponent opponenets[23] = {Opponent(FEMALE), Opponent(MALE), Opponent(FEMALE), Opponent(MALE), Opponent(FEMALE), Opponent(MALE), Opponent(FEMALE),
    Opponent(MALE), Opponent(FEMALE), Opponent(MALE), Opponent(FEMALE), Opponent(MALE), Opponent(FEMALE), Opponent(MALE), Opponent(FEMALE),
    Opponent(MALE), Opponent(FEMALE), Opponent(MALE), Opponent(FEMALE), Opponent(MALE), Opponent(FEMALE), Opponent(MALE), Opponent(FEMALE)};

    //Weapon opponenetsWeapon[23]; */
    Map map;


   /* Events event;

    // Creating Pointers
    player *ptr_player = &mainCharacter;
    Map *ptr_world = &map;
    Opponent (*ptr_opponents)[23] = &opponenets;

    Story story(*ptr_player, *ptr_world, opponenets);

    ptr_player->stats.speed = 2;
*/
    // Variables
    char choice;

    /*cout << "Welcome to the Hunger Games Simulator.";
    cout << "\nBefore we being, you will get the option to customize your calculator.";
    cout << "\nPlayer Name: ";
    getline(cin, mainCharacter.stats.name);
    cout << "\nIntelligence Stats: ";
    cin >> mainCharacter.stats.intelligence;



    // Gets the users starting choice
    // story.getOpponenetsStart();
    switch(story.getBeginning())
    {
    case '1':
        /// POTENTIAL CRASH SOMEWHERE HERE
        story.playerCornucopia();
        break;
    case '2':
        story.cornucopia();
        break;
    }

    event.fight(&mainCharacter, &opponenets[rand() % 23]);
    */

    while(true)
    {
        char i;
        map.generateMap();
        map.displayMap();
        cin >> i;

        system("cls");
    }


    cout << endl;

    return 0;
}
