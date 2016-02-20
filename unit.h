#pragma once

#include "agent.h"
#include "building.h"

#include <vector>

class Building;

/**
 * @brief The Unit class Class of Unit
 */
class Unit : public Agent
{
private:
    int sight_; ///< Sight of Agent
    int moveSpeed_; ///< Recovery time before move
    int range_; ///< Range of an attack of the Unit
    int attackDamage_; ///< Damage of an attack of the Unit
    int attackSpeed_; ///< Recovery time before attack

public:
    /**
     * @brief Unit Constructor by default of Unit
     */
    Unit();

    /**
     * @brief Unit Constructor of Unit
     * @param name Name of Unit
     * @param pos Position of Unit
     * @param team Team of Unit
     * @param waiting Recovery time before an other action
     * @param hitPoints Hit points of Unit
     * @param sight Sight of Unit
     * @param moveSpeed Recovery time before a move
     * @param range Range of Unit
     * @param attackDamage Damage of an attack
     * @param attackSpeed Recovery time before attack
     */
    Unit(string name, Position pos, int team, int waiting, int hitPoints, int sight, int moveSpeed, int range, int attackDamage, int attackSpeed):
        Agent(name, pos, team, waiting, hitPoints), sight_(sight), moveSpeed_(moveSpeed), range_(range), attackDamage_(attackDamage), attackSpeed_(attackSpeed){}

    /**
     * @brief getDistance Get the distance between this unit and the Position in parameter
     * @param pos Position
     * @return the distance
     */
    double getDistance(Position pos) const;

    //If one unit is in sight return distance, else return -1
    /**
     * @brief isInSight check if the Unit is in sight
     * @param pos Position of the other Unit
     * @return the distance if the Unit is in sight, else return -1
     */
    double isInSight(Position pos) const;

    //return the closest unit, if there is an unit in sight, else return NULL
    /**
     * @brief closestUnit Return the closest Unit
     * @param bestDistance Distance of the closest Unit
     * @param posTarget Position of the closest Unit
     * @param VUnit Vector of all Unit
     * @return pointeur of Unit if one Unit is in sight, else return nullptr
     */
    Unit* closestUnit(double &bestDistance, Position &posTarget, vector<Unit *> &VUnit);

    /**
     * @brief closestBuilding return the closest Building
     * @param bestDistance Distance of the closest Building
     * @param posTarget Position of the closest Building
     * @param VBuilding Vector of all Building
     * @return pointeur of Building if one Building is in sight, else return nullptr
     */
    Building* closestBuilding(double& bestDistance, Position &posTarget, vector<Building *> &VBuilding);

    /**
     * @brief closestAgent return the closes Agent (Building or Unit)
     * @param bestDistance Distance of the closest Agent
     * @param posTarget Position of the closest Agent
     * @param VUnit Vector of all Unit
     * @param VBuilding Vector of all Building
     * @return pointeur of Agent, if there is no Agent is sight, return the closest Building
     */
    Agent* closestAgent(double& bestDistance, Position &posTarget, vector<Unit *> &VUnit, vector<Building *> &VBuilding);

    /**
     * @brief doAction Do action move or action attack
     * @param VBuilding Vector of all Building
     * @param VUnit Vector of all Unit
     */
    void doAction(vector<Building *> &VBuilding, vector<Unit *> &VUnit);

    //Move to the target if its possible
    /**
     * @brief moveUnit Move Unit to the target if it's possible
     * @param pos Position of the target
     */
    void moveUnit(Position &pos);

    /**
     * @brief attackUnit Attack the target Unit
     * @param unit Target Unit
     */
    void attackUnit(Unit& unit);

    /**
     * @brief attackBuilding Attacj the target Building
     * @param building Target Building
     */
    void attackBuilding(Building &building);

    //Set the new waiting time after a move
    /**
     * @brief movingRecovery Set the new recovery time after a move
     */
    void movingRecovery() {waiting_ = moveSpeed_;}

    //Set the new waiting time after an attack
    /**
     * @brief attackRecovery Set the new recovery time after an attack
     */
    void attackRecovery() {waiting_ = attackSpeed_;}
};

/**
 * @brief The Marine class Class of Unit "Marine"
 */
class Marine : public Unit
{
public:
    /**
     * @brief Marine Constructor by default of Marine
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
 * @brief The Zealot class Class of Unit "Zealot"
 */
class Zealot : public Unit
{
public:
    /**
     * @brief Zealot Constructor by default of Zealot
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
 * @brief The Ling class Class of Unit "Ling"
 */
class Ling : public Unit
{
public:
    /**
     * @brief Ling Constructor by default of Ling
     */
    Ling() {}

    /**
     * @brief Ling Constructor of Ling
     * @param pos Position of the new Ling
     * @param team Team of the new Ling
     */
    Ling(Position pos, int team);
};
