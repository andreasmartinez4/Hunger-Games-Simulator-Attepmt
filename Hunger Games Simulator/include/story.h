/*
 * Andreas Martinez
 * 12.10.2019
 * This class is used to create the story for the hunger games simulator.
 */

#ifndef STORY_H
#define STORY_H

#include <vector>
#include "player.h"
#include "Map.h"
#include "Weapon.h"
#include "Item.h"
#include "Opponent.h"
#include "Events.h"

class Story
{
    public:
        Story(player& playerScource, Map& worldScource, Opponent* opps)
        {
            // Getting Classes from Main
            player = &playerScource;
            map = &worldScource;
            opponents = opps;

            // Shortening Variables
            world = &map->world;

            // Putting all opponents on the alive vector
            for(int i = 0; i < 23; i++)
            {
                alivePlayers.push_back(&opponents[i]);
            }

            generateCornoWeapons();
        }
        const int NORTH = 1;
        const int SOUTH = 2;
        const int EAST = 3;
        const int WEST = 4;
        static int ID_COUNTER;
        int currentYear = generateYear();
        char getBeginning();
        void killPlayer(Opponent&);
        void playerCornucopia();
        void cornucopia();
        void getOpponenetsStart(); // Gets all the starting information for the opponents - weapon they go for, weather they head towards cornucopia
        Item items;

    private:
        // Functions
        int generateYear();
        int makeRandom(int, int);
        void generateCornoWeapons();
        void bloodBath();
        bool isDifferentBiome(int, int, int); // for checking biomes subject to change
        template <typename T> int inputValidation(T, T, T);
        template <typename T> int pickItem(vector<T>);
        string yearType(int);
        string getFirstLowercase(string, bool);
        string getDirection(int);
        string getMultipleDirections(bool, bool, bool, bool, int);

        // Pointers
        player *player = nullptr;
        Map *map = nullptr;
        Opponent *opponents = nullptr;

        Map::biome (*world)[160][50] = nullptr;

        // Shortened Ptr Variables

        // Class Variables
        Events events;
        vector<Weapon> cornoWeapons;
        vector<Opponent*> cornoOpponents;
        vector<Opponent*> alivePlayers;
        vector<Opponent> deadPlayers;
        vector<Weapon> opponentWpnChoice; // Vector containing all opponents weapon choices that go to the cornucopia

};

#endif // STORY_H
