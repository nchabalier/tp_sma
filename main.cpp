#include <iostream>
#include "building.h"
#include "unit.h"
#include "map.h"
#include "game.h"
#include <ctime>
#include <unistd.h>
//#include <windows.h> //For Sleep()
#include "gen.h"

using namespace std;

int Gen::seed_ = 5489; //Default seed in Mersenne Twister

int main()
{

    int seed = 0;
    int i=0;
    int teams = 2;
    int perTeam = 1;
    char races[16];
    char race;

    cout << "How many teams? (2, 3 or 4)" << endl;
    cin >> teams;
    while (teams < 2 || teams > 4)
    {
        cout << "Must be between 2 and 4, please enter a valid number" << endl;
        cin >> teams;
    }
    cout << "How many players per team? (between 1 and 4)" << endl;
    cin >> perTeam;
    while (perTeam < 1 || perTeam > 4)
    {
        cout << "Must be between 1 and 4, please enter a valid number" << endl;
        cin >> perTeam;
    }


    for(int p = 0; p < perTeam; p++)
    {
        for(int t = 0; t < teams; t++)
        {

            cout << "Player " << p << " of team " << t << "? (T, P or Z)" << endl;
            cin >> race;
            while (race != 't' && race != 'T' && race != 'p' && race != 'P' && race !='Z' && race !='z')
            {
                cout << "Invalid race, please enter a valid value (T/t, P/p, Z/z)" << endl;
                cin >> race;
            }
            races[p*teams + t] = race;
        }
    }

    cout << "Enter a seed (0 will randomize a seed)" << endl;
    cin >> seed;
    while (seed < 0 || seed > 32767)
    {
        cout << "Please enter a value between 0 and 32767" << endl;
        cin >> seed;
    }
    if (seed != 0)
    {
	    Gen::setSeed(seed);
    }
    else 
    {
	    Gen::setSeed((int)time(NULL));
    }

    BuildingFactory fac;
    Game game(fac, teams, perTeam, races);
    game.play();
    while(game.play())
    {
        game.diplayMap();
        usleep(10000);
        i++;
    }
    cout << "This game has lasted " << i << " turns" << endl;

    return 0;
}
