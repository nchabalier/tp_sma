#ifndef GAME_H
#define GAME_H

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
    bool isContinued() {return continue_;}
    void setContinue(bool f) {continue_ = f;}
    bool play();
    void displayDebug() const;
    void diplayMap() const;
    void eraseDeadBuilding();
    void eraseDeadUnit();
    bool emptyTeamBuilding(int team) const; //true if empty
    bool emptyTeamUnit(int team) const; //true if empty
    bool isTeamAlive();
};

#endif // GAME_H
