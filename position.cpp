#include "position.h"
#include "building.h"
#include "unit.h"

bool Position::isOccupied(vector<Building *> &VBuilding, vector<Unit *> &VUnit) const
{
    bool isOccu = false;

    //Case is occupied by Building
    vector<Building *>::iterator itB = VBuilding.begin();
    while(isOccu == false && itB != VBuilding.end())
    {
        if((*itB)->getPosX() == x_ && (*itB)->getPosX() == y_ )
            isOccu = true;
        else
            itB++;
    }

    //Case is occupied by Unit
    vector<Unit *>::iterator itU = VUnit.begin();
    while(isOccu == false && itU != VUnit.end())
    {
        if((*itU)->getPosX() == x_ && (*itU)->getPosX() == y_ )
            isOccu = true;
        else
            itU++;
    }

    return isOccu;
}

