#include "unit.h"
#include <cmath>

void * targetIterator = nullptr;

Unit::Unit()
{
}

Unit::Unit(string name, Position pos, int team) : Agent(name, pos, team, 0, 45)
{
    if (name == "Terran")
    {
        //Agent(name, pos, team, 0, 45);
        sight_ = 9;
        moveSpeed_ = 4;
        range_ = 5;
        attackDamage_ = 6;
        attackSpeed_ = 8;
    }
    else if (name == "Protoss")
    {
        //Agent(name, pos, team, 0, 150);
        sight_ = 8;
        moveSpeed_ = 4;
        range_ = 1;
        attackDamage_ = 16;
        attackSpeed_ = 12;
    }
    else if (name == "Zerg")
    {
        //Agent(name, pos, team, 0, 35);
        sight_ = 9;
        moveSpeed_ = 3;
        range_ = 1;
        attackDamage_ = 5;
        attackSpeed_ = 7;
    }
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
    double bestDistance = -1;
    Position posTarget;

    closestAgent(bestDistance, posTarget, VUnit, VBuilding);

    //cast du pointeur target en vector<Agent> iterator
    vector<Agent>::iterator *targetIterator2 = static_cast<vector<Agent>::iterator *>(targetIterator);

    if(bestDistance <= range_)
    {
        //cout << "A l'attaque" << endl;
        //attackUnit(*targetIterator);
        (*targetIterator2)->takeDamage(attackDamage_);
        this->movingRecovery();

        //cout << targetIterator->getHitPoints() << endl;
    }
    else
    {
        //cout << "En direction de la cible" << endl;
        moveUnit(posTarget);
        this->attackRecovery();
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
void Unit::closestAgent(double& bestDistance, Position &posTarget, vector<Unit> &VUnit, vector<Building> &VBuilding)
{
    closestBuilding(bestDistance, posTarget, VBuilding);
    if(bestDistance > sight_) //If no Building is in sight
    {
        closestUnit(bestDistance, posTarget, VUnit);
    }
}

//--------------------------------------------------------Closest Building---------------------------------------
//Return the closest Building in entire map
void Unit::closestBuilding(double& bestDistance, Position &posTarget, vector<Building> &VBuilding)
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
    targetIterator = &closestUnit;
}

//--------------------------------------------------------Closest Unit---------------------------------------
//Return the closest Unit only if it is in sight
void Unit::closestUnit(double& bestDistance, Position &posTarget, vector<Unit> &VUnit)
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

    if(closestUnit != VUnit.end())
        targetIterator = &closestUnit;
}
