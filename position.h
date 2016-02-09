#ifndef POSITION_H
#define POSITION_H

//#include "building.h"
//#include "unit.h"
#include <vector>
using namespace std;

class Building;
class Unit;

class Position
{
 private:
    int x_;
    int y_;
 public:
    Position() : x_(-1), y_(-1) {}
    Position(int x, int y) : x_(x), y_(y){}

    int getX() const {return x_;}
    int getY() const {return y_;}
    void move(int x, int y) { x_ = x; y_ = y;}
    bool isOccupied(vector<Building *> &VBuilding, vector<Unit *> &VUnit) const;

};

#endif // POSITION_H
