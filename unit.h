#ifndef UNIT_H
#define UNIT_H

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
    Unit(string name, Position pos, int team);
    //Unit(Position pos) : pos_(&pos) {}
    double getDistance(Position pos) const;

    //If one unit is in sight return distance, else return -1
    double isInSight(Position pos) const;

    //return the closest unit, if there is an unit in sight, else return NULL
    void closestUnit(double &bestDistance, Position &posTarget, vector<Unit> &VUnit);

    void closestBuilding(double& bestDistance, Position &posTarget, vector<Building> &VBuilding);

    void closestAgent(double& bestDistance, Position &posTarget, vector<Unit> &VUnit, vector<Building> &VBuilding);

    void doAction(vector<Building> &VBuilding, vector<Unit> &VUnit);

    //Move to the target
    void moveUnit(Position &pos);

    void attackUnit(Unit& unit);

    void attackBuilding(Building &building);

    //Set the new waiting time after a move
    void movingRecovery() {waiting_ = moveSpeed_;}

    //Set the new waiting time after
    void attackRecovery() {waiting_ = attackSpeed_;}
};

#endif // UNIT_H
