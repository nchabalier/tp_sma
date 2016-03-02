#pragma once

#include "agent.h"
#include "building.h"

#include <vector>

class Building;

/**
 * @brief The Unit class represents the units that will interact on the battlefield
 */
class Unit : public Agent
{
private:
    int sight_; ///< Sight of Agent
    int moveSpeed_; ///< Recovery time after moving
    int range_; ///< Range of an attack of the Unit
    int attackDamage_; ///< Damage of an attack of the Unit
    int attackSpeed_; ///< Recovery time after attacking

public:
    /**
     * @brief Unit Default constructor of Unit
     */
    Unit();

    /**
     * @brief Unit Constructor of Unit
     * @param name Name of Unit
     * @param pos Position of Unit
     * @param team Team of Unit
     * @param waiting Recovery time before doing another action
     * @param hitPoints Hit points of Unit
     * @param sight Sight of Unit
     * @param moveSpeed Recovery time after moving
     * @param range Range of Unit
     * @param attackDamage Damage of an attack
     * @param attackSpeed Recovery time after attacking
     */
    Unit(string name, Position pos, int team, int waiting, int hitPoints, int sight, int moveSpeed, int range, int attackDamage, int attackSpeed):
        Agent(name, pos, team, waiting, hitPoints), sight_(sight), moveSpeed_(moveSpeed), range_(range), attackDamage_(attackDamage), attackSpeed_(attackSpeed){}

    /**
     * @brief getDistance Get the distance between this unit and the Position in parameter
     * @param pos Position
     * @return the distance
     */
    double getDistance(Position pos) const;

    /**
     * @brief isInSight check if the Unit is in sight
     * @param pos Position of the other Unit
     * @return the distance if the Unit is in sight, else return -1
     */
    double isInSight(Position pos) const;

    /**
     * @brief closestUnit Return the closest Unit
     * @param bestDistance Distance to the closest Unit
     * @param posTarget Position of the closest Unit
     * @param VUnit Vector of all Units
     * @return pointer of Unit if one Unit is in sight, else return nullptr
     */
    Unit* closestUnit(double &bestDistance, Position &posTarget, vector<Unit *> &VUnit);

    /**
     * @brief closestBuilding return the closest Building
     * @param bestDistance Distance to the closest Building
     * @param posTarget Position of the closest Building
     * @param VBuilding Vector of all Buildings
     * @return pointer of Building if one Building is in sight, else return nullptr
     */
    Building* closestBuilding(double& bestDistance, Position &posTarget, vector<Building *> &VBuilding);

    /**
     * @brief closestAgent return the closest Agent (Building or Unit)
     * @param bestDistance Distance of the closest Agent
     * @param posTarget Position of the closest Agent
     * @param VUnit Vector of all Units
     * @param VBuilding Vector of all Buildings
     * @return pointer of Agent, if there is no Agent is sight, return the closest Building
     */
    Agent* closestAgent(double& bestDistance, Position &posTarget, vector<Unit *> &VUnit, vector<Building *> &VBuilding);

    /**
     * @brief doAction Move or attack
     * @param VBuilding Vector of all Buildings
     * @param VUnit Vector of all Units
     */
    void doAction(vector<Building *> &VBuilding, vector<Unit *> &VUnit);

    /**
     * @brief moveUnit Move Unit to the target Position if it's possible
     * @param pos Target Position
     */
    void moveUnit(Position &pos);

    /**
     * @brief attackUnit Attack the target Unit
     * @param unit Target Unit
     */
    void attackUnit(Unit& unit);

    /**
     * @brief attackBuilding Attack the target Building
     * @param building Target Building
     */
    void attackBuilding(Building &building);

    /**
     * @brief movingRecovery Set the new recovery time after moving
     */
    void movingRecovery() {waiting_ = moveSpeed_;}

    /**
     * @brief attackRecovery Set the new recovery time after an attack
     */
    void attackRecovery() {waiting_ = attackSpeed_;}
};

/**
 * @brief The Marine class is the unit of the Terran race
 */
class Marine : public Unit
{
public:
    /**
     * @brief Marine Default constructor of Marine
     */
    Marine() {}

    /**
     * @brief Marine Constructor of Marine
     * @param pos Position of the new Marine
     * @param team Team of the new Marine
     */
    Marine(Position pos, int team);
};

/**
 * @brief The Zealot class is the unit of the Protoss race
 */
class Zealot : public Unit
{
public:
    /**
     * @brief Zealot Default constructor of Zealot
     */
    Zealot() {}

    /**
     * @brief Zealot Constructor of Zealot
     * @param pos Position of the new Zealot
     * @param team Team of the new Zealot
     */
    Zealot(Position pos, int team);
};

/**
 * @brief The Ling class is the unit of the Zerg race
 */
class Ling : public Unit
{
public:
    /**
     * @brief Ling Default constructor of Ling
     */
    Ling() {}

    /**
     * @brief Ling Constructor of Ling
     * @param pos Position of the new Ling
     * @param team Team of the new Ling
     */
    Ling(Position pos, int team);
};
