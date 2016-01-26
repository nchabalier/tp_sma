#ifndef BUILDING_H
#define BUILDING_H

#include "agent.h"
#include "unit.h"

class Unit;

class Building : public Agent
{
public:
    Building();
    //virtual ~Building();
    Building(int i, Position pos, int team);
    Building(string name, Position pos, int team, int waiting, int hitPoints): Agent(name, pos, team, waiting, hitPoints) {}
    Unit produce();
};

#endif // BUILDING_H
