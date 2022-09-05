/*
 * Andreas Martinez
 * 12.10.2019
 * This class randomly generates a map for the game to take place on.
 */

#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>

using namespace std;

class Map
{
    public:
        Map();
        struct biomeDescriptions // Used for the story generator to get distinct features for eat biome
        {
            string discription; // Description of biome
            string mainElement; // The main distinct feature of the biome
            string element2;
            string inOrOn;
        };
        struct biome // All information for a biome
        {
            string name; // Biome Name
            biomeDescriptions desc;
            char mapKey; // Char for Map
            double visibility; // How open the biome is
            bool isLand; // Checks if biome is land
            bool isPlayer; // Checks if player is occupying the biome
        };
        void displayMap(); // Displays the Map
        void generateMap(); // Function to generate the map
        void dispBiomeDesc();
        static const int world_border_x = 160; // X Border
        static const int world_border_y = 50; // Y Border
        const int middle_x = world_border_x/2; // Center Map X
        const int middle_y = world_border_y/2; // Center Map Y
        biome world[world_border_x][world_border_y]; // Array of Map

    private:
        int addOrSubtract(int, int); // Function to add or subtract two numbers
        biome generateBiome(); // Gets the biome to generate
        void getUseableBiomes(int); // Populated use able biomes vector with use able biomes based on map temp
        void populateRivers(int, int, int, int, int, int, int, int, biome, bool); // Function to populate rivers
        void populateLand(int, int, int, int, int, biome); // Function to populate land
        int makeRandom(int, int, int); // Makes a random number between a range
        static const int amtOfBiomes = 10;
        biome biomes[amtOfBiomes] = // All the biomes in an array
        {{"Forest", {"A biome containing mainly trees with few hostile creatures", "Trees", "Leaves", "In"}, 'F', .75, true},
        {"Plain", {"A large flat open biome with very little cover.", "Grass", "Open Space", "On"}, 'P', 0, true},
        {"Jungle", {"A very dense humid biome packed with trees and creatures.", "Jungle", "Lots of foliage", "In"}, 'J', 1, true},
        {"Swamp", {"A flat marsh filled with trees and mud.", "Marsh", "Mud", "In"}, 'S', .30, true},
        {"Desert", {"Barren empty biome filled with pretty much nothing but sand.", "Sand", "Dunes", "In"}, 'D', 0, true},
        {"Tundra", {"Fro", "Trees", ""}, 'T', .25, true}, // not currently in use - make later
        {"Mountain", {"High land filled with cliffs and peaks, can be tough to pass through.", "Mountains", "Cliffs", "On"}, 'M', .40, true},
        {"Hill", {"Small vertical bumps of elevation filled with light trees and open fields.", "Hills", "Lots of grass and some trees", "On"}, 'H', .30,true},
        {"Lake", {"element", "Trees", "", "In"}, 'L', 0, false}, // ltr
        {"River", {"Body of flowing water, can be hard to cross at times.", "Rivers", "Flowing water", "In"}, 'R', .20, false}};
        vector<biome> useableBiomes; // All the biomes used for the current map
        void SetColor(int); // Sets the color of text to display
};

#endif // MAP_H
