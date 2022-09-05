#include "story.h"
#include "player.h"
#include "Item.h"
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cctype>
#include <limits>

using namespace std;

int Story::ID_COUNTER = 0;

/// Function to get all the information for the beginning of the story
char Story::getBeginning() // Make sure all parts of story goes through main. for example - beginning, cornucopia, day 1 - 7 all are called from main
{
    // seeding the clock
    unsigned int seed = time(0);
    srand(seed);

    int* x = &player->x;
    int* y = &player->y;

    string introduction = "";
    char choice;

    // clearing screen and displaying welcome
    system("cls");

    cout << "CURRENT POS " << (*world)[81][25].mapKey;

    cout << "Welcome " << player->stats.name << " to the annual " << currentYear << yearType(currentYear)
         << " Hunger Games. May the odds be ever in your favor!";

    // set x and y to player-> x pointers
    // test with positions and stuff
    (*world)[*x][*y].isPlayer = true;

    /// This code is for player movement
    /*
    cout << "W for west, S for south, E for east, N for north";
    char direction = 'l';
    while(direction != 'P')
    {

        char currentBiome = (*world)[*x][*y].mapKey;

        cout << "\nYour Current Biome Is: " << currentBiome;


        bool change = false;

        if(isDifferentBiome(*x, *y, NORTH))
        {
            cout << "\nTo your north this is a " << (*world)[*x][*y-1].mapKey;
            change = true;
        }

        if(isDifferentBiome(*x, *y, SOUTH))
        {
            cout << "\nTo your south this is a " << (*world)[*x][*y+1].mapKey;
            change = true;
        }

        if(isDifferentBiome(*x, *y, EAST))
        {
            cout << "\nTo your east this is a " << (*world)[*x+1][*y].mapKey;
            change = true;
        }

        if(isDifferentBiome(*x, *y, WEST))
        {
            cout << "\nTo your west this is a " << (*world)[*x-1][*y].mapKey;
            change = true;
        }

        if(!change)
        {
            cout << "\nThere are no new biome changes";
        }

        cin >> direction;
        switch(direction)
        {
        case 'N':
            (*world)[*x][*y].isPlayer = false;
            (*world)[*x][*y-1].isPlayer = true;
            *y-=1;
            break;
        case 'S':
            (*world)[*x][*y].isPlayer = false;
            (*world)[*x][*y+1].isPlayer = true;
            *y+=1;
            break;
        case 'E':
            (*world)[*x][*y].isPlayer = false;
            (*world)[*x+1][*y].isPlayer = true;
            *x+=1;
            break;
        case 'W':
            (*world)[*x][*y].isPlayer = false;
            (*world)[*x-1][*y].isPlayer = true;
            *x-=1;
            break;
        case 'I':
            map->displayMap();
            break;
        case '0':
            map->generateMap();
            break;
        }


    } */

    // biome desc
    map->dispBiomeDesc();

    // Picks the first sentence in the introduction
    switch((rand() % 3)+1)
    {
    case 1:
        introduction += "Your eyes open and you can see the arena in front of you.";
        break;
    case 2:
        introduction += "As you rise through the elevator, you start to make out the arena.";
        break;
    case 3:
        introduction += "The fog around you begins to disappear, and the arena slowly starts to become visible.";
        break;
    }

    // Pointers to shorten information
    const int *middle_x = &map->middle_x;
    const int *middle_y = &map->middle_y;
    const string *biomeName = &(*world)[*middle_x][*middle_y].name;
    const Map::biomeDescriptions *biomeDesc = &(*world)[*middle_x][*middle_y].desc;

    /// TODO: Better Grammar Handling

    // Describes the biomes surrounding the cornucopia
    // If there are multiple biomes surrounding the cornucopia
    if(isDifferentBiome(*middle_x, *middle_y, NORTH) || isDifferentBiome(*middle_x, *middle_y, SOUTH) || isDifferentBiome(*middle_x, *middle_y, EAST) || isDifferentBiome(*middle_x, *middle_y, WEST))
    {
        // Bools to get the exact locations where there is a different biome
        bool north, south, east, west = false;
        int count = 0;

        if(isDifferentBiome(*middle_x, *middle_y, NORTH))
            { north = true; count++; }

        if(isDifferentBiome(*middle_x, *middle_y, SOUTH))
            { south = true; count++; }

        if(isDifferentBiome(*middle_x, *middle_y, EAST))
            { east = true; count++; }

        if(isDifferentBiome(*middle_x, *middle_y, WEST))
            { west = true; count++; }

        // getMultipleDirections - can be inverted and used if biome is the same by using !north, !south, !east, !west - also use 4-count

        if(true)
        {
            switch((rand() % 1) + 1)
            {
            case 1:
                cout << biomeDesc->mainElement << " surrounds the cornucopia. You notice the " << biomeDesc->mainElement << " continues to the " << getMultipleDirections(!north, !south, !east, !west, 4-count);
            }
        }

    }
    else // If the cornucopia is surronded by one big biome
    {
        switch((rand() % 3) + 1) /// Need better wording based on different biomes - for example if the biome is mountain, change some things
        {
        case 1:
            cout << "The entire area is surrounded by a " << *biomeName;
            break;
        case 2:
            cout << "All you see surrounding the area is " << biomeDesc->mainElement << ". This means you're most likely in the center of a " << *biomeName;
            break;
        case 3:
            cout << biomeDesc->mainElement << " engulfs the entire area. You also notice " << getFirstLowercase(biomeDesc->element2, true) << " leading you to believe you are " << getFirstLowercase(biomeDesc->inOrOn, true) << " " << *biomeName;
            break;
        }
    }

    /// TODO: Appropriate weather information

    // Describes the weather
    switch((rand() % 3)+1)
    {
        // introduction += " describe the weather";
    }

    cout << endl << endl << introduction;

    for(int i = 0; i < cornoWeapons.size(); i++)
    {
        cout << "WEAPON: " << cornoWeapons[i].name << ", ID: " << cornoWeapons[i].wpnID << endl;
    }

    cout << "Would you like to [1] run into the cornucopia. [2] Head to the west... ECT..: ";
    cin >> choice;

    /// TODO: Input Validation

    /// Pre-Code for the cornucopia


    // Determines which opponents go towards the cornucopia based on code in opponenet.cpp
    // Adds all opponents to a vector of those going towards the cornucopia;
    int count = 0;
    for(int opp = 0; opp < 23; opp++)
    {
        if(opponents[opp].cornucopia)
        {
            cornoOpponents.push_back(&opponents[opp]);
            count++;
        }
        else
        {
            // figures out what the rest of the opponenets do
        }

    }
    // Determines which weapon the opponent goes for
    // Adds this weapon choice to a vector
    for(int opp = 0; opp < cornoOpponents.size(); opp++)
    {
        bool bestWpn = false; // Bool that determines weather the opponent has their favorite weapon
        int wpn = rand() % cornoWeapons.size(); // The weapon to attempt to give the user
        int numOfTries = makeRandom(1, 4); // The amt of attempts the opponent tries to look for their favorite weapon

        // Chance that the opponent goes for their favorite weapon
        int counter = 1;
        while(!bestWpn && counter <= numOfTries)
        {
            // If Weapon exceeds the amount of weapons, pick a new random weapon
            if(wpn >= cornoWeapons.size())
                wpn = rand() % cornoWeapons.size();

            // If weapon is set too favorite weapon, attempt to go for it
            if(cornoWeapons[wpn].name == cornoOpponents[opp]->stats.favoriteWeapon.name)
            {
                opponentWpnChoice.push_back(cornoWeapons[wpn]); // Adds a random weapon to the vector
                bestWpn = true;
                cout << endl << cornoOpponents[opp]->stats.name << " has found their favorite wpn of: " << opponentWpnChoice[opp].name << endl;
            }
            wpn++; // Increasing wpn pick
            counter++; // Increasing Counter
        }

        // If user hasn't found their favorite weapon, make them go for a random weapon
        if(!bestWpn)
        {
            opponentWpnChoice.push_back(cornoWeapons[rand() % cornoWeapons.size()]); // Adds a random weapon to the vector
            cout << "\nOpponent hasn't found their favorite weapon, giving them a new one" << endl;
        }

        cout << cornoOpponents[opp]->stats.name << ": Weapon Choice: " << opponentWpnChoice[opp].name << ", ID: " << opponentWpnChoice[opp].wpnID << endl; // Debugging code to display opponents wpn choice
    }

    // Displaying who is going to the cornucopia
    cout << "\nPlayers going to cornucopia: " << count << endl;
    for(int i = 0; i < cornoOpponents.size(); i++)
    {
        cout << cornoOpponents[i]->stats.name << " is going to the cornucopia. " << endl;
    }

    return choice;
}

/// Right now everyone only goes for weapons, will need to include items in the future - backpacks, ect...

/// Default cornucopia when player isn't going for the cornucopia
void Story::cornucopia()
{

                    for(int k = 0; k < cornoOpponents.size(); k++)
                    {
                        cout << endl << "Opponent: " << cornoOpponents[k]->stats.name << endl;
                    }

    // Gets the players their weapons and fights if players are going towards the same weapon
    bool isOppContested;
    for(int i = 0; i < cornoOpponents.size(); i++)
    {
        isOppContested = false;
        for(int j = i+1; j < cornoOpponents.size(); j++)
        {
            if(opponentWpnChoice[i].wpnID == opponentWpnChoice[j].wpnID)
            {
                isOppContested = true;
                if(cornoOpponents[i]->hasWeapon)
                {
                    // fight 3rd player
                }
                else if(cornoOpponents[j]->hasWeapon)
                {
                    // fight 3rd player
                }
                else
                {
                    events.whoGetsWeapon(*cornoOpponents[i], *cornoOpponents[j], opponentWpnChoice[i]);
                    events.fight(*cornoOpponents[i], *cornoOpponents[j]);

                    // Killing the opponent
                    if(!cornoOpponents[i]->stats.isAlive)
                    {
                        deadPlayers.push_back(cornoOpponents[i]);
                        cornoOpponents.erase(cornoOpponents.begin()+i);
                    }
                    else
                    {
                        deadPlayers.push_back(cornoOpponents[i]);
                        cornoOpponents.erase(cornoOpponents.begin()+j);
                    }

                    for(int k = 0; k < cornoOpponents.size(); k++)
                    {
                        cout << endl << "Opponent: " << cornoOpponents[k]->stats.name << endl;
                    }
                }
            }
        }

        // If player isn't contested give them their weapon
        if(!isOppContested)
        {
            cornoOpponents[i]->weapon = opponentWpnChoice[i];
            cornoOpponents[i]->hasWeapon = true;
        }
    }

    // Makes the remaining opponents fight
    for(int opp = 0; opp < cornoOpponents.size(); opp++)
    {
        bool leave = false;
        int count = 0;
        while(cornoOpponents[opp]->stats.isAlive || leave)
        {
            int amtOfFights = (rand() % 4); // Opponent is willing to take max three fights
            int opp2 = rand() % cornoOpponents.size();

            // The opponent leaves
            if(amtOfFights == 0)
            {
                leave = true;
                break;
            }

            if(count == amtOfFights)
            {
                leave = true;
                break;
            }

            events.fight(*cornoOpponents[opp], *cornoOpponents[opp2]);
            // Killing the opponent
            if(!cornoOpponents[opp]->stats.isAlive)
            {
                deadPlayers.push_back(cornoOpponents[opp]);
                cornoOpponents.erase(cornoOpponents.begin()+opp);
            }
            else
            {
                deadPlayers.push_back(cornoOpponents[opp2]);
                cornoOpponents.erase(cornoOpponents.begin()+opp2);
            }

            count++;
        }
    }

}

/// Function for if the player is going towards the cornucopia
void Story::playerCornucopia() // bool to determine if player if going towards conocopia
{
    system("cls");

    const int distance_from_cornucopia = 30; // Distance from cornucopia is 30 meters

    char itemChoice;
    int wpnChoice;
    bool properInput = false;
    vector<Weapon> wpnsAvailableToPlayer; // A vector containing some of the weapons from
    int amtOfAvailableWpns = makeRandom(10, 7); // Generates random number of weapon the user can choose from

    /// Opponents


    /// Basic fight for opponents when player doesn't go towards cornucopia

    // Determines if any one is going for the same weapon, if so, make them fight
    for(int opp1 = 0; opp1 < opponentWpnChoice.size(); opp1++)
    {
        for(int opp2 = opp1+1; opp2 < opponentWpnChoice.size(); opp2++)
        {
            if(opponentWpnChoice[opp1].wpnID == opponentWpnChoice[opp2].wpnID && opp1 != opp2)
            {
                events.whoGetsWeapon(*cornoOpponents[opp1], *cornoOpponents[opp2], opponentWpnChoice[opp1]);
                events.fight(*cornoOpponents[opp1], *cornoOpponents[opp2]);
            }
        }
    }

    /// Player

    // Populating Available Weapons Vector Vector
    int start = rand() % cornoWeapons.size();
    for(int i = 0; i < amtOfAvailableWpns; i++)
    {
        if(start == cornoWeapons.size())
        {
            start = 0;
        }

        wpnsAvailableToPlayer.push_back(Weapon());
        wpnsAvailableToPlayer[i] = cornoWeapons[start];
        start++;
    }

    // First sentence for cornucopia
    switch((rand() % 1)+1)
    {
    case 1:
        cout << "You instantly bolt towards the cornucopia. ";
        break;
    }

    // Describes everyone else headed towards the cornucopia
    switch((rand() % 1)+1)
    {
    case 1:
        // Gets the players and whos going to cornucopia and putting it as text
        for(int i = 0; i < cornoOpponents.size(); i++)
        {
            cout << "You notice " << cornoOpponents[i]->stats.name << " sprinting towards the cornucopia. ";
        }
        cout << " Players doing this and that and ect...";
        break;
    }

    // Describes the items inside the cornucopia
    switch((rand() % 1)+1)
    {
    case 1:
        cout << " As you get nearer, you start to make out all the items. You first notice a bunch of weapons sprawled across the floor. Which one do you go for?\n";



        /// TODO: INPUT CHOICE -> INPUT VALIDATION

        break;
    }

    /// Displaying the weapons the user can pick from and getting input with validation
    wpnChoice = pickItem<Weapon>(wpnsAvailableToPlayer);

    cout << "PLAYER SPEED: " << player->stats.speed << endl;

    int amtOfContests = 0;
    bool isContested = false;
    vector<int> contestedOpponents;

    // Handles the actions if an opponent is going towards the same weapon
    for(int opp = 0; opp < cornoOpponents.size(); opp++)
    {
        if(opponentWpnChoice[opp].wpnID == wpnsAvailableToPlayer[wpnChoice].wpnID)
        {
            amtOfContests++; // Records number of people contesting
            isContested = true;
            contestedOpponents.push_back(opp);

            // Ptrs to clean code
            string *pWeaponName = &wpnsAvailableToPlayer[wpnChoice].name;
            string *opponentName = &cornoOpponents[opp]->stats.name;

            // Alerts the player that someone else is going for the weapon - insight changes based on player inteligene
            // If smarter, give them more information
            if(player->stats.intelligence > 5.0)
            {
                // If the player will get there first
                if(events.isPlayerFaster(player, cornoOpponents[opp], false))
                {
                    switch((rand() % 5) + 1)
                    {
                    case 1:
                        cout << *opponentName << " also appears to be sprinting towards you weapon, however, you appear to be a faster runner and it seems like you will get there first. ";
                        break;
                    case 2:
                        cout << "You notice " << *opponentName << " also heading towards the " << *pWeaponName << ". However, you notice that you will get the weapon first. ";
                        break;
                    case 3:
                        cout << *opponentName << " is also heading for the same weapon, but you are faster and will get their first. ";
                        break;
                    // These next two aren't as accurate to make intelligence not always tell you the direct answer
                    case 4:
                        cout << "As you get closer to the " << *pWeaponName << " you notice " << *opponentName << " also heading towards it.";
                        break;
                    case 5:
                        cout << "You notice " << *opponentName << " running towards the " << *pWeaponName << " and you aren't sure who's going to get to it first";
                        break;
                    }

                }
                else // If the player won't get there first
                {
                    switch((rand() % 5) + 1)
                    {
                    case 1:
                        cout << "You notice " << *opponentName << " is matching you pace and is heading for the same weapon. You aren't sure weather or not you will make it in time. ";
                        break;
                    case 2:
                        cout << *opponentName << " is also sprinting towards the " << *pWeaponName << " and you aren't sure if you will get it first. ";
                        break;
                    case 3:
                        cout << " As run towards the " << *pWeaponName << " you notice that " << *opponentName << " is also running towards it. You're not sure who will get to it first. ";
                        break;
                    case 4:
                        // These two aren't as accurate
                        cout << *opponentName << " appears to also be heading for the weapon. And it seems that you might get there first. ";
                        break;
                    case 5:
                        cout << " You notice " << *opponentName << " is heading for the " << *pWeaponName << ". You think you will get there first. ";
                        break;

                    }
                }
            }
            else // If not, just notify them that a player is going for their weapon
            {
                switch((rand() % 3) + 1)
                {
                case 1:
                    cout << "You sprint closer to the " << wpnsAvailableToPlayer[wpnChoice].name << " you notice that " << cornoOpponents[opp]->stats.name << " is also going for it. ";
                    break;
                case 2:
                    cout << "You notice " << cornoOpponents[opp]->stats.name << " is also going for the weapon. ";
                    break;
                case 3:
                    cout << "You notice " << cornoOpponents[opp]->stats.name << " also running towards the " << wpnsAvailableToPlayer[wpnChoice].name;
                    break;
                }
            }


            /// From here on:
            /// If going for the weapon, the player who gets their first gets the weapon
            /// The opponent might choose to back out if they realize they wont get their on time - this is based on opponents inteligence stats
            /// Player can go for a different weapon or item
            /// Player can dip back towards something else

            /// Depending on what happens, player could end up in a fight regardless
        }
    }

    if(isContested)
    {
        // Code that gives the user options to pick from
        cout << "\nYou have to make a quick decision on what to do: ";
        cout << "\n[1] Continue for the weapon and possibly fight";
        cout << "\n[2] Pick a different weapon";
        cout << "\n[3] Leave the cornucopia";
        cout << "\nOption: ";

        int option;
        cin >> option;

        // Making sure input is proper
        inputValidation<int>(1, 3, option);
 /// PUT IN DO WHILE LOOP CAUSE CASE 2 WOULD NEED CASE 1 CODE
        switch(option)
        {
        case 1: // If user decides to continue towards the weapon
        {
            string *pWeaponName = &wpnsAvailableToPlayer[wpnChoice].name; // Ptr
            vector<bool> isLeaving; // If the opponent decides to continue towards weapon
            vector<bool> isPlayerFaster;

            for(int i = 0; i < contestedOpponents.size(); i++)
            {
                // Throw Away Line
                cornoOpponents[contestedOpponents[i]]->displayStats(); cout << endl;
                string *opponentName = &cornoOpponents[contestedOpponents[i]]->stats.name; // Ptr

                // Used to figure out who will get the weapon first
                if(events.isPlayerFaster(player, cornoOpponents[contestedOpponents[i]], false))
                    isPlayerFaster.push_back(true);
                else
                    isPlayerFaster.push_back(false);

                // If opponent is smart, have them do a smart move
                if(cornoOpponents[contestedOpponents[i]]->stats.intelligence > 5.0)
                {
                    if(events.isPlayerFaster(player, cornoOpponents[contestedOpponents[i]], false))
                        isLeaving.push_back(true);
                    else
                        isLeaving.push_back(false);
                }
                else // Picks weather or not they back off or not
                {
                    if(rand() % 8 == 0)
                        isLeaving.push_back(true);
                    else
                        isLeaving.push_back(false);
                }
            }

            cout << "\nOpponent status picked." << endl;


            // Displaying if the player is leaving
            for(int i = 0; i < contestedOpponents.size(); i++)
            {
                string *opponentName = &cornoOpponents[contestedOpponents[i]]->stats.name;
                if(isLeaving[i])
                {
                    // Displaying that they are leaving
                    switch((rand() % 3) + 1)
                    {
                    case 1:
                        cout << "As you get closer to the " << *pWeaponName << " you notice that " << *opponentName << " is no longer going for the same weapon.";
                        break;
                    case 2:
                        cout << *opponentName << " appears to back off and let you get the " << *pWeaponName;
                        break;
                    case 3:
                        cout << "You approach the weapon, to notice that " << *opponentName << " has disappeared.";
                        break;
                    default:
                        break;
                    }
                }
                cout << endl;

            }

            bool isFastest = true;
            int fastestOpponent;

            // Gives weapon to the player who is fastest
            for(int i = 0; i < contestedOpponents.size(); i++)
            {
                cout << "\nis the opponent faster?\n";
                // If opponent is faster, make sure game knows that
                if(!isPlayerFaster[i])
                {
                    isFastest = false;

                    // Record highest speed
                    double highest = cornoOpponents[contestedOpponents[0]]->stats.speed;
                    fastestOpponent = 0;
                    for(int j = 0; j < contestedOpponents.size(); j++)
                    {
                        // If opponent has a faster speed, set them to be the fastest;
                        if(cornoOpponents[contestedOpponents[j]]->stats.speed-2 > highest)
                        {
                            highest = cornoOpponents[contestedOpponents[j]]->stats.speed;
                            fastestOpponent = j;
                        }
                    }
                }
            }

            // Giving the weapons and displaying a bit of story about who gets weapons
            if(isFastest)
            {
                cout << "here";
                player->weapon = wpnsAvailableToPlayer[wpnChoice];
                player->hasWeapon = true;
                cout << "\nPlayer has got weapon\n";

                // DISPLAY INFO ABOUT HOW THEY GOT THEIR WEAPON
                // Fight
            }
            else if(!isFastest)
            {
                string *pOpponentName = &cornoOpponents[contestedOpponents[fastestOpponent]]->stats.name; //Ptr

                // If they are the same speed no weapon just fists
                if(!events.isOpponentFaster(cornoOpponents[contestedOpponents[fastestOpponent]], player, false))
                {
                    switch((rand() % 5) + 1)
                    {
                    case 1:
                        cout << "You arrive at the weapon at the same time " << *pOpponentName << ".";
                        break;
                    case 2:
                        cout << "As you grab the " << *pWeaponName << " you try to take it, but " << *pOpponentName << " also grabs it.";
                        break;
                    case 3:
                        cout << "As you reach for the weapon, " << *pOpponentName << " also reaches for it, and you start to fight over it.";
                        break;
                    case 4:
                        cout << "You attempt to grab the " << *pWeaponName << " but, " << *pOpponentName << " also has hold of it.";
                        break;
                    case 5:
                        cout << "You reach the " << *pWeaponName << " first but unfortunately, " << *pOpponentName << " was close enough that they also have a grip on the weapon.";
                        break;
                    }

                    // Fist Fight
                    events.fight(player, cornoOpponents[contestedOpponents[fastestOpponent]]);
                }
                else
                {
                    // Giving the opponent the weapon
                    cout << "\ngiving the opponent the weapon\n";
                    cornoOpponents[contestedOpponents[fastestOpponent]]->weapon = wpnsAvailableToPlayer[wpnChoice];
                    cornoOpponents[contestedOpponents[fastestOpponent]]->hasWeapon = true;

                    string *pOpponentName = &cornoOpponents[contestedOpponents[fastestOpponent]]->stats.name;

                    // Display story for opponent getting weapon
                    switch((rand() % 5) + 1)
                    {
                    case 1:
                        cout << "You race towards the weapon, just to notice that " << *pOpponentName << " got their first and is charging at you with the " << *pWeaponName;
                        break;
                    case 2:
                        cout << "You reach for the " << *pWeaponName << " but you are too late. " << *pOpponentName << " grabs it just before you get it in reach. ";
                        break;
                    case 3:
                        cout << "You grab the weapon, just to have it taken out of your hands from " << *pOpponentName;
                        break;
                    case 4:
                        cout << "As you reach for the weapon, " << *pOpponentName << " grabs it.";
                        break;
                    case 5:
                        cout << "You grab the weapon, but your grip fails and " << *pOpponentName << " takes it from you.";
                        break;
                    }

                    // FIGHTTTT
                }
            }

            // Fighting the remaining plays that are headed towards the weapon
            for(int i = 0; i < contestedOpponents.size(); i++)
            {
                if(contestedOpponents[i] != contestedOpponents[fastestOpponent] && !isLeaving[i])
               {
                    events.fight(player, cornoOpponents[contestedOpponents[i]]);
               }

            }

            /// BLOOD BATH COMMENCE
        }
        break;
        case 2: // Picking a new weapon
            // Deleting their previous weapon choice off the vector
            wpnsAvailableToPlayer.erase(wpnsAvailableToPlayer.begin()+wpnChoice);
            wpnChoice = pickItem(wpnsAvailableToPlayer);

            /// ONCE WEAPON CODE GETS FIGURED OUT -> BLOOD BATH

            break;
        case 3:
            // leaving the cornucopia
            break;
        }
    }


}

/// This function is for what happens when the player and opponents fight at the cornucopia
/// It will generate all the fights that happen and revolves around the player fighting
void Story::bloodBath()
{

}

/// Populates the corno weapons vector with all the weapons
/// that will be placed in the coronocopia
void Story::generateCornoWeapons()
{
    int numOfWeapons = makeRandom(8, 15); // Num of weapons in cornucopia

    for(int i = 0; i < numOfWeapons; i++)
    {
        int random = rand() % items.numOfWeapons;
        cornoWeapons.push_back(Weapon());
        cornoWeapons[i] = items.weapons[random];
        cornoWeapons[i].wpnID = ID_COUNTER++;
    }
}

void Story::killPlayer(Opponent& opp)
{
    deadPlayers.push_back(&opp);
    //alivePlayers.erase(remove(alivePlayers.begin(), alivePlayers.end(), opp), alivePlayers.end());
}

/// Generates the year for the games
int Story::generateYear()
{
    return (rand() % 98) + 2;
}

/// Function to pick an Item
template <typename T> int Story::pickItem(vector<T> itemType)
{
    int wpnChoice;

    // Displaying Available Items
    for(int i = 0; i < itemType.size(); i++)
    {
        cout << "[" << i+1 << "] " << itemType[i].name << " ID: " << itemType[i].wpnID << endl;
    }

    // Getting item choice with input validation
    cout << itemType[0].type << " to Attempt to Grab: ";
    cin >> wpnChoice;
    wpnChoice = inputValidation<int>(1, itemType.size(), wpnChoice);
    wpnChoice -= 1; // Sets wpn choice to correspond to array

    // Returning it
    return wpnChoice;
}

/// Function gets proper input
template <typename T> int Story::inputValidation(T low, T high, T choice)
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

/// Gets the char ending for the year
string Story::yearType(int year)
{
    // Outliers
    if(year == 11 || year == 12 || year == 13)
    {
        return "th";
    }

    // Returns the proper ending based on the last number in year
    switch(year % 10)
    {
    case 1:
        return "st";
        break;
    case 2:
        return "nd";
        break;
    case 3:
        return "rd";
        break;
    case 0:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        return "th";
        break;
    }

    // If nothing else is met, return nothing
    return "";
}

/// Returns a string with a lowercase or capital letter for the first character
string Story::getFirstLowercase(string str, bool isLow)
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

/// Function to return a string value of a direction
string Story::getDirection(int direction)
{
    if(direction == NORTH)
    {
        return "North";
    }
    else if(direction == SOUTH)
    {
        return "South";
    }
    else if(direction == EAST)
    {
        return "East";
    }
    else if(direction == WEST)
    {
        return "West";
    }
    else
    {
        return "ERROR IN GET DIRECTION";
    }
}

/// Returns the proper string of directions for where the biomes have changed
string Story::getMultipleDirections(bool north, bool south, bool east, bool west, int amtOfDirections)
{
    string directions; // String to be returned
    int count = 0; // Amt of times direction has been changed

    if(north) // If direction is different to the north
    {
        count++;
        if(amtOfDirections == count) // If the amt of biome changes meets the max number of biome changes
            return "north";
        else
            directions += "north"; // If there were more, add it to the string
    }

    if(south) // If the direction is different to the south
    {
        count++;
        if(amtOfDirections == count) // If the amt of biome changes meets the max number of biome changes
        {
            if(count == 1) // If there was only 1 biome change, return it
                return "south";
            else
                return directions += " and south"; // If this was the last change, return it
        }
        else if(count == 1)
            directions += "south"; // If south is the first biome change, add it
        else
            directions += ", south"; // If there are still more, add it to a comma list
    }

    if(east)
    {
        count++;
        if(amtOfDirections == count) // If the amt of biome changes meets the max number of biome changes
        {
            if(count == 1) // If there was only 1 biome change, return it
                return "east";
            else if(count == 2)
                return directions += " and east"; // Return proper grammar if only two directions were used
            else
                return directions += ", and east"; // Return with comma if 3 of more directions were used
        }
        else if(count == 1)
            directions += "east"; // If count is the first biome change, add it
        else
            directions += ", east"; // Add onto the comma chain
    }

    if(west)
    {
        count++;
        if(count == 1) // If there was only 1 biome change, return it
            return "west";
        else if(count == 2)
            directions += " and west"; // If only two directions used, use proper grammar
        else
            directions += ", and west"; // Finishing based on appropriate amt of directions used
    }

    return directions; // If not returned before, return it

}

/// Function to determine if a new biome is in the players range
bool Story::isDifferentBiome(int x, int y, int direction)
{
    // May possibly add diagonal directions

    switch(direction)
    {
    case 1:
        if((*world)[player->x][player->y].mapKey != (*world)[player->x][player->y-1].mapKey) // NORTH
            return true;
            break;
    case 2:
        if((*world)[player->x][player->y].mapKey != (*world)[player->x][player->y+1].mapKey) // SOUTH
            return true;
            break;
    case 3:
        if((*world)[player->x][player->y].mapKey != (*world)[player->x+1][player->y].mapKey) // EAST
            return true;
            break;
    case 4:
        if((*world)[player->x][player->y].mapKey != (*world)[player->x-1][player->y].mapKey) // WEST
            return true;
            break;
    default:
        break;
    }

    return false;
}

/// Function to generate a random number between a range
int Story::makeRandom(int high, int low)
{
    int num = (rand() % (high - low + 1)) + low;

    return num;
}



