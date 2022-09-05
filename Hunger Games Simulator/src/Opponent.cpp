/*
 * Andreas Martinez
 * 12.17.2019
 * This class holds all the information and interactions between weapons. It will house a player weapon, aswell as a weapon for each of the opponents.
 */

#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include "Opponent.h"
#include "Item.h"

using namespace std;

Opponent::Opponent()
{

}

/// Constructor
Opponent::Opponent(bool isFemale)
{
    if(isFemale)
        isMale = false;
    else
        isMale = true;

    stats.name = getName();
    stats.height = getHeight();
    stats.weight = getWeight();
    stats.BMI = getBMI();
    stats.intelligence = makeRandomDouble(9, 0);
    generateSpeedStats();
    displayStats();
}

/// This function displays all the stats for the opponent
void Opponent::displayStats()
{
    cout << stats.name << " Height: " << stats.height << " Weight: " << stats.weight << " Weapon: " << stats.favoriteWeapon.name << " BMI: " << stats.BMI << " Type: " << stats.type;
    cout << " Speed: " << stats.speed <<   " Strength: " << stats.strength << " intelligence " << stats.intelligence << endl;
}

/// This function uses a file consisting of 1000 male and female
/// names and picks a random one and uses it for their name
string Opponent::getName()
{
    // Creating File Obejct
    fstream file;

    // Opens file for male or female names
    if(isMale)
        file.open("BoyNames.txt", ios::in);
    else
        file.open("GirlNames.txt", ios::in);

    // Gets a random name from file and sets it as name
    if(file.is_open())
    {
        string temp;
        int numLines = 0;
        int random = rand() % 1000;

        while(getline(file, temp))
        {
            numLines++;
            if(numLines == random)
            {
                // Closes file & sends name back to function
                file.close();
                return temp;
            }
        }
    }
    return "ASDF";
}

/// This function determines what kind of play style the character will have
/// It determines weather or not the player is strong, smart, and what kind of weapons they
/// are best with
void Opponent::generateSpeedStats()
{
    // makeRandomDoubleDouble(High, Low)
    // Generates random double between a set range
    // For generating stats - max is 9, min is 0
    // stats range from 10 - 0 as doubles
    // <4 is bad | 5 - 7 avg | 7 - 10 good

    const int high_high = 9;
    const int high_low = 7;

    const int avg_high = 6;
    const int avg_low = 4;

    const int low_high = 3;
    const int low_low = 0;

    if(stats.BMI <= 20.0)
    {
        // fast skinnier, not great fighter
        switch((rand() % 3) + 1)
        {
        case 1: // Mainly Speed, Low Endurance
            stats.type = "Only Speed";
            stats.speed = makeRandomDouble(high_high, high_low);
            stats.endurance = makeRandomDouble(5, 2); // low to avg endurance
            stats.strength = makeRandomDouble(low_low, low_high);
            // more stats
            break;
        case 2: // Balance of Speed and Endurance
            stats.type = "Balanced Speed";
            stats.speed = makeRandomDouble(8, avg_high);
            stats.endurance = makeRandomDouble(avg_high, avg_low);
            stats.strength = makeRandomDouble(avg_low, 2);
            // more stats
            break;
        case 3: // Mainly equipped with longer endurance and avg speed
            stats.type = "Long Endurance";
            stats.speed = makeRandomDouble(high_low, 5);
            stats.endurance = makeRandomDouble(high_high, high_low);
            stats.strength = makeRandomDouble(avg_high, low_high);
            // more stats
            break;
        }

        // 1 in 6 of these types of people decided to go towards the cornucopia
        cornucopia = toCornucopia(6);
        int favoriteWpnReference = (rand() % 6) + 1;

        // Generates favorite weapon, excluding some
        switch(favoriteWpnReference)
        {
        case 1: // Short Sword
            stats.favoriteWeapon = Item().weapons[1];
            break;
        case 2: // Dagger
            stats.favoriteWeapon = Item().weapons[2];
            break;
        case 3: // Bow
            stats.favoriteWeapon = Item().weapons[5];
            break;
        case 4: // Darts
            stats.favoriteWeapon = Item().weapons[6];
            break;
        case 5: // Shurkins
            stats.favoriteWeapon = Item().weapons[7];
            break;
        case  6: // Sling Shot
            stats.favoriteWeapon = Item().weapons[10];
            break;
        }
    }
    else if(stats.BMI < 24.0 && stats.BMI > 20.0)
    {
        // Normal - balance of fast, skinny, fighting - mainly random
        switch((rand() % 3) + 1)
        {
        case 1: // A bit of everything
            stats.type = "Avg Everything";
            stats.speed = makeRandomDouble(high_low, avg_low);
            stats.endurance = makeRandomDouble(high_low, avg_low);
            stats.strength = makeRandomDouble(high_low, avg_low);
            // more stats
            break;
        case 2: // Stronger and slower
            stats.type = "Stronger AVG";
            stats.speed = makeRandomDouble(avg_high, low_high);
            stats.endurance = makeRandomDouble(avg_high, low_high);
            stats.strength = makeRandomDouble(8, avg_high);
            // more stats
            break;
        case 3: // Faster and a bit weaker
            stats.type = "Faster AVG";
            stats.speed = makeRandomDouble(high_high, avg_low);
            stats.endurance = makeRandomDouble(avg_high, low_high);
            stats.strength = makeRandomDouble(5, low_high);
            // more stats
            break;
        }

        // 1 in 4 of these types have a chance at going towards the cornucopia
        cornucopia = toCornucopia(4);

        // These guys are allowed to pick any weapon as their favorite
        stats.favoriteWeapon = Item().weapons[rand() % Item().numOfWeapons];
    }
    else
    {
        const int amntOfWpns = 6; // Amount of Weapons
        const int wpns[amntOfWpns] = {0, 3, 4, 5, 9, 10}; // Array containing all the weapons available -> each number relates to weapon from items.weapon array
        stats.favoriteWeapon = Item().weapons[wpns[rand() % amntOfWpns]]; // Assigning the opponent their favorite weapon

        // Stronger, slower, better with certain types of weapons
        switch((rand() % 3) + 1)
        {
        case 1: // Slow but strong
            stats.type = "Slow and Strong";
            stats.speed = makeRandomDouble(low_high, low_low);
            stats.endurance = makeRandomDouble(low_high, low_low);
            stats.strength = makeRandomDouble(high_high, avg_high);
            // more stats
            break;
        case 2: // Not as slow but still strong
            stats.type = "Less Slow, Less Strong";
            stats.speed = makeRandomDouble(5, low_high);
            stats.endurance = makeRandomDouble(5, low_high);
            stats.strength = makeRandomDouble(8, 5);
            // more stats
            break;
        case 3: // Slow and weak
            stats.type = "Slow & Weak";
            stats.speed = makeRandomDouble(5, low_low);
            stats.endurance = makeRandomDouble(low_high, low_low);
            stats.strength = makeRandomDouble(avg_high, avg_low);
            // more stats
            break;
        }

        // 1 in 3 of these people decide to go towards the cornucopia
        cornucopia = toCornucopia(3);

    }
}

/// This function gets a height for the opponent
int Opponent::getHeight()
{
    if(isMale)
        return makeRandom(78, 60);
    else
        return makeRandom(73, 55);

    return 0;
}

/// This function gets the weight for the opponent
/// Needs to be proportiante to height
int Opponent::getWeight()
{
    if(isMale)
    {
        if(stats.height <= 65 && stats.height >= 60)
            return makeRandom(150, 90);
        else if(stats.height <= 70 && stats.height > 65)
            return makeRandom(180, 140);
        else if(stats.height <= 75 && stats.height > 70)
            return makeRandom(200, 150);
        else
            return makeRandom(250, 160);
    }
    else
    {
        if(stats.height <= 60 && stats.height >= 55)
            return makeRandom(125, 80);
        else if(stats.height <= 65 && stats.height > 60)
            return makeRandom(150, 100);
        else if(stats.height <= 70 && stats.height > 65)
            return makeRandom(170, 120);
        else
            return makeRandom(200, 135);
    }

    return 0;
}

/// This function gets the BMI of the player
/// This is important to decide weather the player is fast,
/// strong, and ect...
double Opponent::getBMI()
{
    return 703 * (static_cast<double>(stats.weight) / pow(static_cast<double>(stats.height), 2));
}

/// Function to generate a random number between a range
int Opponent::makeRandom(int high, int low)
{
    int num = (rand() % (high - low + 1)) + low;

    return num;
}

/// Function to make a random double to two decimal places
double Opponent::makeRandomDouble(int high, int low)
{
    /// Possibility of going over 10 - make sure the +1 doesnt mean i can get a higher number than 10.0
    int mainNum = (rand() % (high - low + 1)) + low; // Num before decimal

    int decimal = (rand() % (100 - 0 +1)) + low; // Num after decimal

    return static_cast<double>(mainNum+(decimal*.01)); // Converts after decimal to actual decimal, then adds two nums together
}

bool Opponent::toCornucopia(int num)
{
    if(rand() % num == 1)
        return true;
    else
        return false;
}
