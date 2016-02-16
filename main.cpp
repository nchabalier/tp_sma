#include <iostream>
#include "building.h"
#include "unit.h"
#include "map.h"
#include "game.h"
#include <ctime>
#include <windows.h> //For Sleep()
#include "gen.h"

using namespace std;

int Gen::seed_ = 1234;

int main()
{
    int i=0;
    int teams = 4;
    int perTeam = 3;
    char races[16];

    //Initialisation du générateur de nombre aléatoire


    cout << "How many teams? (2, 3 or 4)" << endl;
    //cin >> teams;
    cout << "How many players per team? (between 1 and 4)" << endl;
    //cin >> perTeam;


    for(int p = 0; p < perTeam; p++)
    {
        for(int t = 0; t < teams; t++)
        {

            cout << "Player " << p << " of team" << t << "? (T, P or Z)" << endl;
            //cin >> races[p*teams + t];

            races[p*teams+t] = 'T';
        }
    }


    BuildingFactory fac;
    Game game(fac, teams, perTeam, races);
    game.play();
    while(game.play())
    {
        game.diplayMap();
        Sleep(5);
        cout << i << endl;
        i++;
    }

    return 0;
}
