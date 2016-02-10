#ifndef POSITION_H
#define POSITION_H

#include <vector>

using namespace std;

//class Building;
//class Unit;

/**
 * @brief The Position class allows the coordinated manipulation.
 */
class Position
{
 private:
    int x_;  ///< Coordinate X.
    int y_;  ///< Coordinate Y.

 public:
    /**
     * @brief Position Constructor of Position.
     * Note : (-1,-1) by default
     */
    Position() : x_(-1), y_(-1) {}

    /**
     * @brief Position Constructor of Position.
     * @param x Coordinate X.
     * @param y Coordinate Y.
     */
    Position(int x, int y) : x_(x), y_(y){}

    /**
     * @brief getX Return the coordinate X.
     * @return
     */
    int getX() const {return x_;}

    /**
     * @brief getY Return the coordinate Y.
     * @return
     */
    int getY() const {return y_;}

    /**
     * @brief setX Set the coordinate X.
     * @param x Coordinate X.
     */
    void setX(int x) { x_ = x;}

    /**
     * @brief setY Set the coordinate Y.
     * @param y Coordinate Y.
     */
    void setY(int y) { y_ = y;}

    /**
     * @brief move Set the current position to the position : (x, y)
     * @param x Coordinate X.
     * @param y Coordinate Y.
     */
    void move(int x, int y) { x_ = x; y_ = y;}
};

#endif // POSITION_H
