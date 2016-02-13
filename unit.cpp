#include "unit.h"
#include <cmath>

#include "map.h"
#include "iostream"

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

Marine::Marine(Position pos, int team) : Unit("Marine", pos, team, 0, 45, 9, 4, 3, 5, 8){}

Zealot::Zealot(Position pos, int team) : Unit("Zealot", pos, team, 0, 150, 8, 4, 1, 18,12){}

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
    int posToSelec = -1;
    Position newPos[2];

    Map* map = Map::get();

    //Move vertically
    if(getPosX() < pos.getX())
        newPos[0].setX(getPosX()+1);
    else
        newPos[0].setX(getPosX()-1);

    newPos[0].setY(getPosY());

    //Move horizontally
    if(getPosY() < pos.getY())
       newPos[1].setY(getPosY()+1);
    else
       newPos[1].setY(getPosY()-1);

    newPos[1].setX(getPosX());

    if(!map->isOccupied(newPos[0]) || !map->isOccupied(newPos[1]))
    {
        if(!map->isOccupied(newPos[0]) && !map->isOccupied(newPos[1]))
        {
            //random select
            cout << "select alea" << endl;
            posToSelec = alea;
        }
        else
        {
            if (!map->isOccupied(newPos[0])) //Select vertical movement
            {
                posToSelec = 0;
                cout << "select 0" << endl;
            }
            else //Select horizontal movement
            {
                posToSelec = 1;
                cout << "select 1" << endl;
            }
        }
    }
    if(posToSelec != -1 && newPos[posToSelec].getX() >= 0 && newPos[posToSelec].getX() < 20
                        && newPos[posToSelec].getY() >= 0 && newPos[posToSelec].getY() < 20)
    {
        map->move(this->pos_, newPos[posToSelec]);
        pos_.move(newPos[posToSelec].getX(), newPos[posToSelec].getY()); //TODO : faire passer une Position direcetement
    }
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
        Agent* closestTemp = (Agent *)closestUnit(bestDistance, posTarget, VUnit);
        if(closestTemp != nullptr)
            closestA = closestTemp;
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

    return closestU;
}
