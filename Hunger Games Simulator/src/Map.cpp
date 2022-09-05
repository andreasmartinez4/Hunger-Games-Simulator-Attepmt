#include "Map.h"
#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>
#include <windows.h>
#include <stdio.h>
#include "conio.h"

using namespace std;

Map::Map()
{

}

/// This function is a constructor that is used to generate the map
/// It populates the world[][] array with biomes
void Map::generateMap()
{
    // declaring variables
    bool isGenerated = false;
    unsigned int start_x = 0;
    unsigned int start_y = 0;
    int count_x = 0;
    int count_y = 0;
    int temperature;
    int r_x; // Limits x range
    int r_y; // Limits y range
    int r_x_variation; // Sets the variation in x pos
    int start_variation; // Changes the variation in start pos

    // Generating map constraints
    temperature = 70;//makeRandom(110, makeRandom(60, 0, -10), -10);


    // Gets the biomes that can be used based on map temperature
    getUseableBiomes(temperature);

    // Sets the entire map to X
    for(int y = 0; y < world_border_y; y++)
    {
        for(int x = 0; x < world_border_x; x++)
        {
            world[x][y].mapKey = 'X';
        }
    }

    cout << "\nGenerated X's\n";

    // Map Generation
    for(int i = 0; i < 30; i++) // Amount of times to run the map over
    {
        // gets the biome to place in map
        biome currentBiome = generateBiome();

        // Switch statement generates biomes in different ways
        // Specific generation for rivers, lakes, ect...
        switch(currentBiome.mapKey)
        {
        case 'L': // Lakes

            break;
        case 'R': // Rivers
            switch((rand() % 2)+1)
            {
            case 1:
                {
                    cout << "\nAttempting to generate vertical river\n";
                    r_x = makeRandom(6, 2, -10);
                    r_y = makeRandom(world_border_y, world_border_y/2, 0);
                    start_x = makeRandom(world_border_x/1.05, 0, start_x); // Starting point for x cords
                    start_y = makeRandom(world_border_y/2, 0, start_x); // Starting point for y cords
                    count_x = 0;
                    count_y = 0;

                    populateRivers(start_x, start_y, r_x, r_y, world_border_x, world_border_y, 3, 3, currentBiome, false);

                    cout << "\nVertical River Generated\n";

              /*      int variation = (rand() % 3)+1;
                    int changeVariation;

                    // populates the y cords with biome
                    for(int y = start_y; y < world_border_y && count_y < r_y; y++)
                    {
                        start_variation = rand() % 3;
                        r_x_variation = rand() % 3;

                        changeVariation = (rand() % 3)+1;

                        if(changeVariation == 1)
                        {
                            variation = (rand() % 3)+1;
                        }

                        switch(variation)
                        {
                        case 1:
                            start_x = addOrSubtract(start_x, start_variation);
                            r_x = addOrSubtract(r_x, r_x_variation);
                            break;
                        case 2:
                            start_x += start_variation;
                            r_x += r_x_variation;
                            break;
                        case 3:
                            start_x -= start_variation;
                            r_x -= r_x_variation;
                        }

                        while(start_x < 1)
                        {
                            start_x += rand() % 3;
                            cout << "fixing" << endl;
                        }

                        while(r_x > 6)
                        {
                            r_x -= rand() % 3;
                            cout << "fixing too big river" << endl;
                        }

                        while(r_x < 1)
                        {
                            r_x += rand() % 3;
                            cout << "fixing r x" << endl;
                        }

                        count_x = 0;

                        // populates the x cords with the biome
                        for(int x = start_x; x < world_border_x && count_x < r_x; x++)
                        {
                            world[x][y] = currentBiome;
                            count_x++;
                        }
                            count_y++;
                    }*/
                }

                break;
            case 2: // river generates to run horizontally
                {
                    cout << "\nAttempting to generate horzontal rivers\n";
                    r_x = makeRandom(world_border_x, world_border_x/2, 0); // limits x range
                    r_y = makeRandom(4, 2, 0); // limits y range
                    start_x = makeRandom(world_border_x/1.05, 0, start_x); // Starting point for x cords
                    start_y = makeRandom(world_border_y/2, 0, start_x); // Starting point for y cords
                    count_x = 0;
                    count_y = 0;

                    populateRivers(start_y, start_x, r_y, r_x, world_border_y, world_border_x, 3, 3, currentBiome, true);

                    cout << "\nHorozontal Rivers Generated Succesfully\n";
/*

                    for(int x = start_x; x < world_border_x && count_x < r_x; x++)
                    {
                        count_y = 0;

                        start_variation = rand() % 2;
                        start_y = addOrSubtract(start_y, start_variation);

                        while(start_y < 1)
                        {
                            start_y += rand() % 2;
                        }

                        for(int y = start_y; y < world_border_y && count_y < r_y; y++)
                        {
                            world[x][y] = currentBiome;
                            count_y++;
                        }
                        count_x++;
                    } */

                    /*// populates the y cords with biome
                    for(int y = start_y; y < world_border_y && count_y < r_y; y++)
                    {
                        start_variation = rand() % 3;
                        start_x = addOrSubtract(start_x, start_variation);

                        r_x_variation = rand() % 3;
                        r_x = addOrSubtract(r_x, r_x_variation);

                        while(start_x < 1)
                        {
                            start_x += rand() % 3;
                            cout << "fixing" << endl;
                        }

                        while(r_x > 6)
                        {
                            r_x -= rand() % 3;
                            cout << "fixing too big river" << endl;
                        }

                        while(r_x < 1)
                        {
                            r_x += rand() % 3;
                            cout << "fixing r x" << endl;
                        }

                        count_x = 0;

                        // populates the x cords with the biome
                        for(int x = start_x; x < world_border_x && count_x < r_x; x++)
                        {
                            world[x][y] = currentBiome;
                            count_x++;
                        }
                            count_y++;
                    }
                    */
                }
                break;
            default:
                break;
            }
                break;
            default:
                {
                    cout << "\nAttempting to generate land\n";
                    r_x = makeRandom(world_border_x/2, world_border_x/8, 0); // Limits range for biomes x cords
                    r_y = makeRandom(world_border_y/2, world_border_y/6, 0); // Limits range for biomes y cords
                    start_x = makeRandom(world_border_x/1.05, 0, start_x); // Starting point for x cords
                    start_y = makeRandom(world_border_y/1.05, 0, start_x); // Starting point for y cords
                    count_x = 0; // counter for limiting x range
                    count_y = 0;

                    populateLand(start_x, start_y, r_x, r_y, 10, currentBiome);

                    cout << "\nLand Generated Successfully\n";
/*
                    cout << "\nRX: " << r_x;
                    cout << "\nRY: " << r_y;
                    cout << "\nStart X: " << start_x;
                    cout << "\nStart Y: " << start_y;
                    cout << "\nBIOME: " << currentBiome << endl; */

                }

            break;

        }


    }

    /*
    while(!isGenerated)
    {
        int r = rand() % 50;
        int total = 0;

        for(int i = 0; i < x; i++)
        {

        }
    }
    */
}

/// This function displays the map in different colors
void Map::displayMap()
{
    int mostAmtOfSpaces[world_border_y] = {0};
    int highest = 0;
    char myBiome;
    int spaces = 0;

    /*
    for(int currentBiome = 0; currentBiome < useableBiomes.size(); currentBiome++)
    {
        myBiome = useableBiomes[currentBiome].mapKey;
        for(int y = 0; y < world_border_y; y++)
        {
            spaces = 0;
            for(int x = 0; x < 90; x++)
            {
                if(world[x-1][y] != myBiome && world[x][y] == myBiome)
                {
                    for(int x_shift = x; x_shift < 90; x_shift++)
                    {
                        shownMap[x_shift+1][y] = shownMap[x_shift][y];
                    }
                    shownMap[x][y] = ' ';
                    cout << endl << "Spaces: " << spaces;
                }
                else if(world[x][y] == myBiome  && x + spaces < 90)
                {
                    shownMap[x][y] = myBiome;
                }
            }
        }
    }*/

    // Displays Map
    for(int y = 0; y < world_border_y; y++)
    {
        for(int x = 0; x < world_border_x; x++)
        {
            // Sets color according to biome
            switch(world[x][y].mapKey)
            {
            case 'F':
                SetColor(10);
                break;
            case 'P':
                SetColor(2);
                break;
            case 'J':
                SetColor(6);
                break;
            case 'S':
                SetColor(8);
                break;
            case 'D':
                SetColor(14);
                break;
            case 'T':
                SetColor(15);
                break;
            case 'M':
                SetColor(7);
                break;
            case 'H':
                SetColor(13);
                break;
            case 'L':
                SetColor(1);
                break;
            case 'R':
                SetColor(9);
                break;
            default:
                SetColor(11);
                break;
            }

            if(world[x][y].isPlayer) // if player occupies space, display player icon
            {
                cout << ".";
            }
            else if(x == middle_x && y == middle_y)
            {
                cout << "C";
            }
            else
            {
                cout << world[x][y].mapKey; // Displaying Map
            }
        }
        cout << endl;
    }

    SetColor(7); // Sets color back to normal

    cout << endl << endl << endl;



   /* for(int y = 0; y < world_border_y; y++)
    {

        for(int x = 0; x < world_border_x; x++)
        {
            if(world[x-1][y] != world[x][y])
            {
                mostAmtOfSpaces[y]++;
            }

            if(world[x-1][y] != world[x][y])
            {
                cout << " ";

            }

            cout << world[x][y];
        }

        if(mostAmtOfSpaces[y] > highest)
        {
            highest = mostAmtOfSpaces[y];
            cout << "New high;";
        }

        cout << endl;
    }
    cout << "\nMost AMT OF SPACES: " << highest << endl;

    for(int i = 0; i < world_border_y; i++)
    {
        cout << mostAmtOfSpaces[i] << endl;
    }*/

}

/// Function that pulls the biomes and gives them to the generator
Map::biome Map::generateBiome()
{
    int r = (rand() % useableBiomes.size());
    switch(r)
    {
    case 0:
        return useableBiomes[0];
        break;
    case 1:
        return useableBiomes[1];
        break;
    case 2:
        return useableBiomes[2];
        break;
    case 3:
        return useableBiomes[3];
        break;
    case 4:
        return useableBiomes[4];
        break;
    case 5:
        return useableBiomes[5];
        break;
    case 6:
        return useableBiomes[6];
        break;
    case 7:
        return useableBiomes[7];
        break;
    case 8:
        return useableBiomes[8];
        break;
    case 9:
        return useableBiomes[9];
        break;
    }
}

/// Function to generate a random number between a range
int Map::makeRandom(int high, int low, int exclude)
{
    int num = (rand() % (high - low + 1)) + low;

    while(num > exclude+4 && num < exclude-4)
    {
        cout << "Possible crash????" << endl;
        int num = (rand() % (high - low + 1)) + low;
        cout << "IN THIS USLESS LOOP SEND HELP" << endl;
    }

    return num;
}

/// Function tog et the useable biomes based on temperature
/// If cold, make the useablebiomes vector cold biomes
/// If hot, make the useablebiomes vector have hot biomes
void Map::getUseableBiomes(int temperature)
{
    // Declaring Variables
    int amtOfBiomes;

    // Populated vector based on temperature
    if(temperature <= 45)
    {
        // get cold biomes
    }
    else if(temperature > 45 && temperature < 90)
    {
        // Amount of biomes useable
        amtOfBiomes = 9;

        // Arrray of useable biomes location in structure
        int biomeNum[amtOfBiomes] = {0, 1, 2, 3, 4, 6, 7, 8, 9};

        // Adding those biomes to the vector
        for(int i = 0; i < amtOfBiomes; i++)
        {
            useableBiomes.push_back(biome());
            useableBiomes[i] = biomes[biomeNum[i]];
        }
    }
    else if(temperature >= 90)
    {
        // get extreme heat biomes
    }
}

/// Function used to populate the map with major & minor biomes
/// Function starts by generating the biome, then places smaller biomes inside
/// start_x is the x location start, start_y is the y location start
/// r_x is how wide the biome is, r_y is how long the biome is
void Map::populateLand(int start_x, int start_y, int r_x, int r_y, int var, biome currentBiome)
{
    // Declaring Variables
    bool firstRun = true; // Forces a direction if its the first run
    bool isHorzontal = true; // Checks direction biome will run
    int direction_variation; // Chance of changing directions
    int start_variation; // akes the start placement of x vary
    int r_x_variation; // Varies the max width of biome
    int r_y_variation; // Varies the max length
    int count_x = 0; // X counter
    int count_y = 0; // Y counter
    int border_x; // Changes if map gens vertically
    int border_y; // Changes if map gens vertically

    // Generates the biome vertically
    if(false)
    {
        int temp;
        isHorzontal = false;

        // Swapping all Variables
        temp = start_x;
        start_x = start_y;
        start_y = temp;

        temp = r_x;
        r_x = r_y;
        r_y = temp;


        border_x = world_border_y;
        border_y = world_border_x;

    }
    else
    {
        border_x = world_border_x;
        border_y = world_border_y;
    }

    cout << "\nBefore world gen for loop\n";
    for(int y = start_y; y < border_y && count_y < r_y; y++)
    {
        start_variation = rand() % var;

        if(isHorzontal)
        {
            r_x_variation = rand() % var;

            if((rand() % var) == 1 || firstRun)
            {
                direction_variation = (rand() % 3)+1;
            }

            firstRun = false;

            switch(direction_variation)
            {
            case 1:
                start_x = addOrSubtract(start_x, start_variation);
                r_x = addOrSubtract(r_x, r_x_variation);
                break;
            case 2:
                start_x += start_variation;
                r_x += r_x_variation;
                break;
            case 3:
                start_x -= start_variation;
                r_x -= r_x_variation;
                break;
            }
        }
        else
        {
            start_x = addOrSubtract(start_x, start_variation);

            cout << start_x;
            while(start_x < 1)
            {
                start_x += rand() % 3;
            }
        }

        /// fixes bug where start_x ends up negative --- temporary fix
        while(start_x < 1)
        {
            start_x += rand() % 3;
        }

        //cout << "\nMiddle of world gen for loop\n";

        count_x = 0;
        for(int x = start_x; x < border_x && count_x < r_x; x++)
        {
            //cout << "\nMessing with x values\n";
            if(isHorzontal)
            { // troubleshooting for -x start below
                //cout << "X LOCATION: " << x;
                //cout << "\nY LOCATION: " << y << endl;
                if(world[x][y].mapKey == 'X')
                {

                    world[x][y] = currentBiome;
                }
            }
            else
            {
                if(world[y][x].mapKey == 'X')
                {
                   world[y][x] = currentBiome;
                }
            }

            count_x++;
        }
        count_y++;
    }
}

/// Function used to populate the map with rivers
/// Start_X is the x location start, Start_Y is the y location start
/// r_x is the x range limit, y_x is the y range limit
void Map::populateRivers(int start_x, int start_y, int r_x, int r_y, int border_x, int border_y, int rand_1, int rand_2, biome river, bool isHorozontal)
{
    // Declaring Variables
    int count_x = 0;
    int count_y = 0;
    int start_variation;
    int directon_variation;
    int r_x_variation;
    bool firstRun = true;
                  /*  for(int x = start_x; x < world_border_x && count_x < r_x; x++)
                    {
                        count_y = 0;

                        start_variation = rand() % 2;
                        start_y = addOrSubtract(start_y, start_variation);

                        while(start_y < 1)
                        {
                            start_y += rand() % 2;
                        }

                        for(int y = start_y; y < world_border_y && count_y < r_y; y++)
                        {
                            world[x][y] = currentBiome;
                            count_y++;
                        }
                        count_x++;
                    } */

    for(int y = start_y; y < border_y && count_y < r_y; y++)
    {
        // Changing start and r_x variation for river
        start_variation = rand() % rand_1;

        if(isHorozontal)
        {
            start_x = addOrSubtract(start_x, start_variation);

            while(start_x > border_x)
            {
                start_x -= rand() % 3;
            }

            while(start_x < 1)
            {
                start_x += rand() % 3;
            }
        }
        else
        {
            r_x_variation = rand() % rand_1;

            if((rand() % 3) == 1 || firstRun)
            {
                directon_variation = (rand() % 3)+1;
            }

            switch(directon_variation)
            {
            case 1:
                start_x = addOrSubtract(start_x, start_variation);
                r_x = addOrSubtract(r_x, r_x_variation);
                break;
            case 2:
                start_x += start_variation;
                r_x += r_x_variation;
                break;
            case 3:
                start_x -= start_variation;
                r_x -= r_x_variation;
                break;
            }

            // Makes it so X cant start at 0
            while(start_x < 1)
            {
                start_x += rand() % 3;
            }

            // Fixes river if its too big
            while(r_x > 6)
            {
                r_x -= rand() % 3;
            }

            //  Fixes
            while(r_x < 1)
            {
                r_x += rand() % 3;
            }
        }


        count_x = 0;
        for(int x = start_x; x < border_x && count_x < r_x; x++)
        {
            if(isHorozontal)
                world[y][x] = river;
            else
                world[x][y] = river;

            count_x++;
        }
        count_y++;
        firstRun = false;
    }
}

/// Function that returns two numbers added or subtracted
int Map::addOrSubtract(int num1, int num2)
{
    int chance = (rand() % 2)+1;

    switch(chance)
    {
    case 1:
        return num1-num2;
        break;
    case 2:
        return num1+num2;
        break;
    }
    return -1;
}

/// Function to display description of each biome
void Map::dispBiomeDesc()
{
    for(int i = 0; i < amtOfBiomes; i++)
    {
        cout << biomes[i].name << ": " << biomes[i].desc.discription << endl;
    }
}


/// This function is used to change text color in CMD, found online
void Map::SetColor(int ForgC)
{

     WORD wColor;
     //This handle is needed to get the current background attribute

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     //csbi is used for wAttributes word

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          //To mask out all but the background attribute, and to add the color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}
