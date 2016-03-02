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

    cout << "How many teams? (2, 3 or 4)" << endl;
    cin >> teams;
    teams = 2;
    cout << "How many players per team? (between 1 and 4)" << endl;
    cin >> perTeam;
    perTeam = 1;


    for(int p = 0; p < perTeam; p++)
    {
        for(int t = 0; t < teams; t++)
        {

            cout << "Player " << p << " of team " << t << "? (T, P or Z)" << endl;
            cin >> races[p*teams + t];
        }
    }

    cout << "Enter a seed (0 will randomize a seed)" << endl;
    cin >> seed;
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
        usleep(5000);
        cout << i << endl;
        i++;
    }

    return 0;
}
