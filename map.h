#pragma once

#include "position.h"

/**
 * @brief The Map class holds the map
 */
class Map
{
private:
    /**
     * @brief singleton There is at most only one instanciated Map at all times
     */
    static Map* singleton;

    /**
     * @brief Map private constructor
     */
    Map();

    /**
     * @brief Map Definied here to forbid copy of the map
     */
    Map(const Map&);
    /**
     * @brief operator = Definied here to forbid copy of the map
     */
    void operator=(const Map&);

    /**
     * @brief map_ Contain every first character of the Units and Buildings to display
     */
    char map_[20][20];

public:
    /**
     * @brief get if the map doesn't exist yet, this method creates a Map else return predifined Map
     * @return the only one Map
     */
    static Map *get()
    {
        if(!singleton)
            singleton = new Map;
        return singleton;
    }

    /**
     * @brief display the entire map
     */
    void display() const;

    /**
     * @brief add a new character in the map (creation of new Building or Unit)
     * @param letter First letter of the object to add
     * @param x X Position of object to add
     * @param y Y Position of object to add
     */
    void add(char letter, int x, int y);

    /**
     * @brief add a new character in the map (creation of new Building or Unit)
     * @param letter First letter of the object to add
     * @param pos Position of object to add
     */
    void add(char letter, Position pos);

    /**
     * @brief move Change the position of an existing Unit
     * @param posPrec previous Position
     * @param posSuiv new Position
     */
    void move(Position posPrec, Position posSuiv);

    /**
     * @brief isOccupied Check if the Position is occupied
     * @param pos Position to check
     * @return true if Position is occupied, false if not
     */
    bool isOccupied(Position pos) const;

    /**
     * @brief erase an Existing object
     * @param pos Position of the object to erase
     */
    void erase(Position pos);

    /**
     * @brief findPositionAvailable
     * @param posCur
     * @return A random empty Position around the posCur, if it's not possible return position (-1, -1)
     */
    Position findPositionAvailable(Position posCur) const;

};
