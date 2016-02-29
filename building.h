#pragma once

#include "agent.h"
#include "unit.h"
#include <vector>

class Unit;

/**
 * @brief The Building class is the class who created Unit
 */
class Building : public Agent
{
public:
    /**
     * @brief Building Constructor by Default of Building
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
     * @param VUnit_
     */
    virtual void produce(vector<Unit *> &VUnit_)=0;

    /**
     * @brief ~Building Virtual destructor of Building
     */
    virtual ~Building() {}
};

/**
 * @brief The Barracks class is the building of race Marine
 */
class Barracks : public Building
{
public:
    /**
     * @brief Barracks Constructor by default of a Barracks Building
     */
    Barracks() {}

    /**
     * @brief Barracks Constructor of a Barracks Building
     * @param pos Position of the Barracks
     * @param team Team of the Barracks
     */
    Barracks(Position pos, int team);

    virtual void produce(vector<Unit *> &VUnit_);
};

/**
 * @brief The Gateway class is the building of race Zealot
 */
class Gateway : public Building
{
public:
    /**
     * @brief Gateway Constructor by default of a Gateway Building
     */
    Gateway() {}

    /**
     * @brief Gateway Constructor of a Gateway Building
     * @param pos Position of the Gateway
     * @param team Team of the Gateway
     */
    Gateway(Position pos, int team);
    virtual void produce(vector<Unit *> &VUnit_);
};

/**
 * @brief The Hatchery class is the building of race Ling
 */
class Hatchery : public Building
{
public:
    /**
     * @brief Hatchery Constructor by default of a Hatchery Building
     */
    Hatchery() {}

    /**
     * @brief Hatchery Constructor of a Hatchery Building
     * @param pos Position of the Buidling
     * @param team Team of the Building
     */
    Hatchery(Position pos, int team);
    virtual void produce(vector<Unit *> &VUnit_);
};

/**
 * @brief The BuildingFactory class create 3 differents type of Building (Barracks, Hatchery, Gateway)
 */
class BuildingFactory
{
public:
    /**
     * @brief create Creation of a specified Building
     * @param race First character of the building's race
     * @param pos Position of the Building
     * @param team Team of the Building
     * @return a pointeur of Building
     */
    Building * create(char race, Position pos, int team);
};

