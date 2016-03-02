#pragma once

#include "agent.h"
#include "unit.h"
#include <vector>

class Unit;

/**
 * @brief The Building class is the class who creates Units
 */
class Building : public Agent
{
public:
    /**
     * @brief Building Default constructor of Building
     */
    Building();

    /**
     * @brief Building Constructor of Building
     * @param name Name of the Building
     * @param pos Position of the Building
     * @param team Team of the Building
     * @param waiting Initial time before Building can do an action (create Unit)
     * @param hitPoints Hit Points of the Building
     */
    Building(string name, Position pos, int team, int waiting, int hitPoints): Agent(name, pos, team, waiting, hitPoints) {}

    /**
     * @brief produce Virtual method redefined in the factory
     * @param VUnit_ Unit vector in which the new Unit should be pushed
     */
    virtual void produce(vector<Unit *> &VUnit_)=0;

    /**
     * @brief ~Building Virtual destructor of Building
     */
    virtual ~Building() {}
};

/**
 * @brief The Barracks class is the building of the Terran race
 */
class Barracks : public Building
{
public:
    /**
     * @brief Barracks Default constructor of a Barracks building
     */
    Barracks() {}

    /**
     * @brief Barracks Constructor of a Barracks building
     * @param pos Position of the Barracks
     * @param team Team of the Barracks
     */
    Barracks(Position pos, int team);

    virtual void produce(vector<Unit *> &VUnit_);
};

/**
 * @brief The Gateway class is the building of the Protoss race
 */
class Gateway : public Building
{
public:
    /**
     * @brief Gateway Default constructor of a Gateway building
     */
    Gateway() {}

    /**
     * @brief Gateway Constructor of a Gateway building
     * @param pos Position of the Gateway
     * @param team Team of the Gateway
     */
    Gateway(Position pos, int team);
    virtual void produce(vector<Unit *> &VUnit_);
};

/**
 * @brief The Hatchery class is the building of the Zerg race
 */
class Hatchery : public Building
{
public:
    /**
     * @brief Hatchery Default constructor of a Hatchery building
     */
    Hatchery() {}

    /**
     * @brief Hatchery Constructor of a Hatchery building
     * @param pos Position of the Buidling
     * @param team Team of the Building
     */
    Hatchery(Position pos, int team);
    virtual void produce(vector<Unit *> &VUnit_);
};

/**
 * @brief The BuildingFactory class can create 3 differents types of Building (Barracks, Hatchery, Gateway)
 */
class BuildingFactory
{
public:
    /**
     * @brief create Creation of a specified Building
     * @param race First character of the building's race
     * @param pos Position of the Building
     * @param team Team of the Building
     * @return a pointer of Building
     */
    Building * create(char race, Position pos, int team);
};

