#include <iostream>
#include "building.h"
#include "unit.h"
#include "map.h"
#include "game.h"
#include <ctime>
#include <windows.h> //For Sleep()

using namespace std;

int main()
{
    srand(time(NULL));

    /*Position pos(10,10);
    Agent newAgent ("Marine", pos, 0, 10, 100);
    newAgent.takeDamage(20);
    newAgent.display();

    Building newBuilding("Batiment", pos, 0, 10, 1000);
    newBuilding.display();

    cout << "-----------------" << endl;*/

    Game game;
    game.play();
    while(game.play())/*game.isFinish_ == false*/
    {
        //game.play();
        //game.displayDebug();
        game.diplayMap();
        Sleep(10);
    }

    return 0;
}
