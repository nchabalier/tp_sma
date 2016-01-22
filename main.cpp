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
