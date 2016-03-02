#pragma once

#include <vector>

using namespace std;


/**
 * @brief The Position class allows the coordinated manipulation
 */
class Position
{
 private:
    int x_;  ///< X coordinate (latitude)
    int y_;  ///< Y coordinate (longitude)

 public:
    /**
     * @brief Position Constructor of Position.
     * Note : (-1,-1) by default
     */
    Position() : x_(-1), y_(-1) {}

    /**
     * @brief Position Constructor of Position.
     * @param x X coordinate
     * @param y Y coordinate
     */
    Position(int x, int y) : x_(x), y_(y){}

    /**
     * @brief getX Return the X coordinate
     * @return
     */
    int getX() const {return x_;}

    /**
     * @brief getY Return the Y coordinate
     * @return
     */
    int getY() const {return y_;}

    /**
     * @brief setX Set the X coordinate
     * @param x X coordinate
     */
    void setX(int x) { x_ = x;}

    /**
     * @brief setY Set the Y coordinate
     * @param y Y coordinate
     */
    void setY(int y) { y_ = y;}

    /**
     * @brief move Set the current position to the position : (x, y)
     * @param x X coordinate
     * @param y Y coordinate
     */
    void move(int x, int y) { x_ = x; y_ = y;}
};
