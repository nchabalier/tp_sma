#include "unit.h"

#include <cmath>
void * targetIterator = nullptr;

Unit::Unit()
{
}

double Unit::getDistance(Position pos) const
{
    return sqrt(pow(getPosX()-pos.getX(), 2) + pow(getPosY()-pos.getY(), 2));
}

double Unit::isInSight(Position pos) const
{
    double distance = getDistance(pos);
    if(distance < sight_)
        return distance;
    else
        return -1;
}







void Unit::doAction(vector<Building> &VBuilding, vector<Unit> &VUnit)
{
    //Unit* target = nullptr;
    double bestDistance = -1;
    Position posTarget;
    //vector<Agent>::iterator targetIterator;
    //void* targetIterator;
              // pointer to void
    //closestUnit(targetIterator, bestDistance, VUnit, posTarget, VBuilding);
    closestAgent(/*&targetIterator,*/ VUnit, bestDistance, posTarget, VBuilding);

    vector<Agent>::iterator *targetIterator2 = static_cast<vector<Agent>::iterator *>(targetIterator);

    if(bestDistance <= range_)
    {
        //cout << "A l'attaque" << endl;
        //attackUnit(*targetIterator);
        (*targetIterator2)->takeDamage(attackDamage_);
        //cout << targetIterator->getHitPoints() << endl;

    }
    else
    {
        //cout << "En direction de la cible" << endl;
        moveUnit(posTarget);
    }
}

void Unit::moveUnit(Position& pos)
{
    int alea = rand()%2;
    int newPosX = getPosX();
    int newPosY = getPosY();

    //Move vertically
    if(alea == 0 || getPosY() == pos.getY())
    {
        if(getPosX() < pos.getX())
            newPosX++;
        else
            newPosX--;
    }
    else //Move horizontally
    {
        if(getPosY() < pos.getY())
            newPosY++;
        else
            newPosY--;
    }

    pos_.move(newPosX, newPosY);
}

void Unit::attackUnit(Unit &unit)
{
    unit.takeDamage(attackDamage_);
}

void Unit::attackBuilding(Building &building)
{
    building.takeDamage(attackDamage_);
}


//--------------------------------------------------------Closest Target---------------------------------------
void Unit::closestAgent(/*void ** targetIterator,*/ vector<Unit> &VUnit, double& bestDistance, Position &posTarget, vector<Building> &VBuilding)
{
    closestBuilding(/*&targetIterator,*/ bestDistance, posTarget, VBuilding);
    if(bestDistance > sight_) //If no Building is in sight
    {
        closestUnit(/*&targetIterator,*/ bestDistance, VUnit, posTarget);
    }
}

//--------------------------------------------------------Closest Building---------------------------------------
//Return the closest Building in entire map
void Unit::closestBuilding(/*void **targetIterator,*/ double& bestDistance, Position &posTarget, vector<Building> &VBuilding)
{
    vector<Building>::iterator closestUnit = VBuilding.end();

    for(vector<Building>::iterator it = VBuilding.begin(); it != VBuilding.end(); it++)
    {
        if(team_ != it->getTeam()) //If it's not the building of the team
        {
             double newDistance = getDistance(it->getPos());
             if(bestDistance == -1 || newDistance < bestDistance)
             {
                 bestDistance = newDistance;
                 closestUnit = it;
                 posTarget = it->getPos();
             }
        }
    }
    //vector<Agent>::iterator* cu = static_cast<vector<Agent>::iterator*>(&closestUnit);
    targetIterator = &closestUnit;
}

//--------------------------------------------------------Closest Unit---------------------------------------
//Return the closest Unit only if it is in sight
void Unit::closestUnit(/*void ** targetIterator,*/ double& bestDistance, vector<Unit> &VUnit, Position &posTarget)
{
    vector<Unit>::iterator closestUnit = VUnit.end();

    for(vector<Unit>::iterator it = VUnit.begin(); it != VUnit.end(); it++)
    {
        if(team_ != it->getTeam())
        {
            double newDistance = isInSight(it->getPos());
            if(bestDistance == -1 || (newDistance != -1 && newDistance < bestDistance))
            {
                bestDistance = newDistance;
                closestUnit = it;
                posTarget = it->getPos();
            }
        }
    }

    //Debugage
    /*if(closestUnit != VUnit.end())
        cout << closestUnit->pos_.getX() << ", " << closestUnit->pos_.getY() << endl;*/

    if(closestUnit != VUnit.end())
        targetIterator = &closestUnit;
}
