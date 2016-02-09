#include "unit.h"
#include <cmath>

Agent * targetIterator = nullptr;

Unit::Unit()
{
}

/*
Unit::Unit(string name, Position pos, int team)
{
    if (name == "Terran")
    {
        Agent(name, pos, team, 0, 45);
        sight_ = 9;
        moveSpeed_ = 4;
        range_ = 5;
        attackDamage_ = 6;
        attackSpeed_ = 8;
    }
    else if (name == "Protoss")
    {
        Agent(name, pos, team, 0, 150);
        sight_ = 8;
        moveSpeed_ = 4;
        range_ = 1;
        attackDamage_ = 16;
        attackSpeed_ = 12;
    }
    else if (name == "Zerg")
    {
        Agent(name, pos, team, 0, 35);
        sight_ = 9;
        moveSpeed_ = 3;
        range_ = 1;
        attackDamage_ = 5;
        attackSpeed_ = 7;
    }
}
*/

Marine::Marine(Position pos, int team) : Unit("Marine", pos, team, 0, 45, 9, 4, 5, 6, 8){}

Zealot::Zealot(Position pos, int team) : Unit("Zealot", pos, team, 0, 150, 8, 4, 1, 16,12){}

Ling::Ling(Position pos, int team) : Unit("Ling", pos, team,0, 35, 9, 3, 1, 5, 7){}

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

void Unit::doAction(vector<Building *> &VBuilding, vector<Unit *> &VUnit)
{
    double bestDistance = -1;
    Position posTarget;

    Agent* closestTarget = closestAgent(bestDistance, posTarget, VUnit, VBuilding);

    //cast du pointeur target en vector<Agent> iterator
    //vector<Agent *>::iterator *targetIterator2 = static_cast<vector<Agent *>::iterator *>(targetIterator);

    if(bestDistance <= range_)
    {
        cout << "A l'attaque" << endl;
        //attackUnit(*targetIterator);
        //(**targetIterator2)->takeDamage(attackDamage_);
        closestTarget->takeDamage(attackDamage_);
        this->movingRecovery();

        //cout << targetIterator->getHitPoints() << endl;
    }
    else
    {
        //cout << "En direction de la cible" << endl;
        moveUnit(posTarget);
        //moveUnit(closestA->getPos());
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
Agent* Unit::closestAgent(double& bestDistance, Position &posTarget, vector<Unit *> &VUnit, vector<Building *> &VBuilding)
{
    Agent* closestA = nullptr;

    closestA = (Agent *)closestBuilding(bestDistance, posTarget, VBuilding);
    if(bestDistance > sight_) //If no Building is in sight
    {
        closestA = (Agent *)closestUnit(bestDistance, posTarget, VUnit);
    }
    else
    {
        cout << "Batiment en vue" << endl;
    }
    return closestA;
}

//--------------------------------------------------------Closest Building---------------------------------------
//Return the closest Building in entire map
Building* Unit::closestBuilding(double& bestDistance, Position &posTarget, vector<Building *> &VBuilding)
{
    Building* closestB = nullptr;

    for(auto it : VBuilding)
    {
        if(team_ != it->getTeam()) //If it's not the building of the team
        {
             double newDistance = getDistance(it->getPos());
             if(bestDistance == -1 || newDistance < bestDistance)
             {
                 bestDistance = newDistance;
                 closestB = it;
                 posTarget = it->getPos();
             }
        }
    }
    targetIterator = (Agent *)closestB;
    return closestB;
}

//--------------------------------------------------------Closest Unit---------------------------------------
//Return the closest Unit only if it is in sight
Unit* Unit::closestUnit(double& bestDistance, Position &posTarget, vector<Unit *> &VUnit)
{
    Unit* closestU = nullptr;

    for(auto it : VUnit)
    {
        if(team_ != it->getTeam())
        {
            double newDistance = isInSight(it->getPos());
            if(bestDistance == -1 || (newDistance != -1 && newDistance < bestDistance))
            {
                bestDistance = newDistance;
                closestU = it;
                posTarget = it->getPos();
            }
        }
    }

    if(closestU != nullptr)
        targetIterator = closestU;
    return closestU;
}
