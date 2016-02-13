#pragma once

#include "agent.h"
#include "unit.h"
#include <vector>

class Unit;

class Building : public Agent
{
public:
    Building();
    //virtual ~Building();
    //Building(int i, Position pos, int team);
    Building(string name, Position pos, int team, int waiting, int hitPoints): Agent(name, pos, team, waiting, hitPoints) {}
    virtual void produce(vector<Unit *> &VUnit_)=0;
};


class Barracks : public Building
{
public:
    Barracks() {}
    Barracks(Position pos, int team);
    virtual void produce(vector<Unit *> &VUnit_);
};

class Gateway : public Building
{
public:
    Gateway() {}
    Gateway(Position pos, int team);
    virtual void produce(vector<Unit *> &VUnit_);
};

class Hatchery : public Building
{
public:
    Hatchery() {}
    Hatchery(Position pos, int team);
    virtual void produce(vector<Unit *> &VUnit_);
};

class BuildingFactory
{
    public :
    Building * create(char race, Position pos, int team);
};

