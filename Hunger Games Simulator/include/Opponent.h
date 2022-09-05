/*
 * Andreas Martinez
 * 12.17.2019
 * This class holds all the information for the enemies. It gives each opponent different stats, skills,
 * weapons, items, and also handles interactions.
 */
#ifndef OPPONENT_H
#define OPPONENT_H

#include "Weapon.h"
#include <cstdlib>
#include <ctime>

class Opponent
{
    public:
        Opponent();
        Opponent(bool);
        void displayStats();
        struct stats
        {
            bool isAlive = true;
            string name;
            string gender;
            int height;
            int weight;
            double BMI;
            string type;
            double speed;
            double endurance;
            double strength;
            double intelligence;
            double health = 10.0;
            double reactions = 12.0;
            Weapon favoriteWeapon;
        };
        stats stats;
        bool hasWeapon = false;
        Weapon weapon;
        bool cornucopia;
        bool isMale;
        int x;
        int y;

        //Weapon weapon;

    private:
        string getName();
        void generateSpeedStats();
        double getBMI();
        int makeRandom(int, int);
        double makeRandomDouble(int, int);
        int getHeight();
        int getWeight();
        bool toCornucopia(int num);
};

#endif // OPPONENT_H
