#pragma once

#include <vector>
#include "agent.h"
#include "unit.h"
#include "building.h"

#define HEIGHT 20
#define WIDTH 20

/**
 * @brief The Game class is the principal class of the program
 */
class Game
{
private:
    /**
     * @brief VBuilding_ is a vector of all building created
     */
    vector<Building *> VBuilding_;

    /**
     * @brief VUnit_ is a vector of all unit created
     */
    vector<Unit *> VUnit_;

    /**
     * @brief continue_ is true if the game isn't finished
     */
    bool continue_;
public:
    /**
     * @brief Game Constructor by default of the class Game
     */
    Game();

    /**
     * @brief Game Constructor of the class Game
     * @param fac Factory of Building
     * @param teams Number of teams
     * @param perTeam Number of Building per team
     * @param races Name of races
     */
    Game(BuildingFactory fac, int teams, int perTeam, char races[16]);

    /**
     * @brief isContinued return a boolean
     * @return return true if game continue and false if game is finished
     */
    bool isContinued() {return continue_;}

    /**
     * @brief setContinue Set the new value of continue_
     * @param f the new boolean
     */
    void setContinue(bool f) {continue_ = f;}

    /**
     * @brief play
     * @return
     */
    bool play();

    /**
     * @brief diplayMap Display the entire map
     */
    void diplayMap() const;

    /**
     * @brief eraseDeadBuilding Erase all buildings which have hitPoints under 0
     */
    void eraseDeadBuilding();

    /**
     * @brief eraseDeadUnit Erase all units which have hitPoints under 0
     */
    void eraseDeadUnit();

    /**
     * @brief emptyTeamBuilding Verify if there is no Building of the team
     * @param team to verify
     * @return boolean true if there is no Building of this team
     */
    bool emptyTeamBuilding(int team) const; //true if empty

    /**
     * @brief emptyTeamUnit Verify is ther is no Unit of the team
     * @param team to verify
     * @return boolean true if ther is no Unit of this team
     */
    bool emptyTeamUnit(int team) const; //true if empty

    /**
     * @brief isTeamAlive Check if there is more than one team alive
     * @return false is there is only one team alive
     */
    bool isTeamAlive();

    void clean();
};

