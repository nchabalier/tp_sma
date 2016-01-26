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
    void closestUnit(/*void **targetIterator,*/ double &bestDistance, vector<Unit> &VUnit, Position &posTarget);

    void closestBuilding(/*void **targetIterator,*/ double& bestDistance, Position &posTarget, vector<Building> &VBuilding);

    void closestAgent(/*void **targetIterator,*/ vector<Unit> &VUnit, double& bestDistance, Position &posTarget, vector<Building> &VBuilding);

    ///TODO : passe un objet Building et renvoie false si le building est détruit
    void doAction(vector<Building> &VBuilding, vector<Unit> &VUnit);

    //Move to the target
    void moveUnit(Position &pos);

    void attackUnit(Unit& unit);

    void attackBuilding(Building &building);
};

#endif // UNIT_H
