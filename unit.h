#pragma once

#include "agent.h"
#include "building.h"

#include <vector>

class Building;

class Unit : public Agent
{
private:
    int sight_; // Champ de vision
    int moveSpeed_;
    int range_;
    int attackDamage_;
    int attackSpeed_;

public:
    Unit();
    //virtual ~Unit();

    //Unit(string name, Position pos, int team);

    Unit(string name, Position pos, int team, int waiting, int hitPoints, int sight, int moveSpeed, int range, int attackDamage, int attackSpeed):
        Agent(name, pos, team, waiting, hitPoints), sight_(sight), moveSpeed_(moveSpeed), range_(range), attackDamage_(attackDamage), attackSpeed_(attackSpeed){}

    //Unit(Position pos) : pos_(&pos) {}
    double getDistance(Position pos) const;

    //If one unit is in sight return distance, else return -1
    double isInSight(Position pos) const;

    //return the closest unit, if there is an unit in sight, else return NULL
    Unit* closestUnit(double &bestDistance, Position &posTarget, vector<Unit *> &VUnit);

    Building* closestBuilding(double& bestDistance, Position &posTarget, vector<Building *> &VBuilding);

    Agent* closestAgent(double& bestDistance, Position &posTarget, vector<Unit *> &VUnit, vector<Building *> &VBuilding);

    void doAction(vector<Building *> &VBuilding, vector<Unit *> &VUnit);

    //Move to the target if its possible
    void moveUnit(Position &pos);

    void attackUnit(Unit& unit);

    void attackBuilding(Building &building);

    //Set the new waiting time after a move
    void movingRecovery() {waiting_ = moveSpeed_;}

    //Set the new waiting time after
    void attackRecovery() {waiting_ = attackSpeed_;}
};

class Marine : public Unit
{
public:
    Marine() {}
    Marine(Position pos, int team);
};
class Zealot : public Unit
{
public:
    Zealot() {}
    Zealot(Position pos, int team);
};
class Ling : public Unit
{
public:
    Ling() {}
    Ling(Position pos, int team);
};
