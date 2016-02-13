#pragma once

#include <vector>
#include "agent.h"
#include "unit.h"
#include "building.h"

#define HEIGHT 20
#define WIDTH 20

class Game
{
private:
    vector<Building *> VBuilding_;
    vector<Unit *> VUnit_;
    bool continue_;
public:
    Game();
    Game(BuildingFactory fac, int teams, int perTeam, char races[16]);
    bool isContinued() {return continue_;}
    void setContinue(bool f) {continue_ = f;}
    bool play();
    void diplayMap() const;
    void eraseDeadBuilding();
    void eraseDeadUnit();
    bool emptyTeamBuilding(int team) const; //true if empty
    bool emptyTeamUnit(int team) const; //true if empty
    bool isTeamAlive();
};

