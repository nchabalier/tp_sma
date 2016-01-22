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
    Building(string name, Position pos, int team, int waiting, int hitPoints): Agent(name, pos, team, waiting, hitPoints) {}
    Unit produce();
    //virtual ~Building();
};

#endif // BUILDING_H
