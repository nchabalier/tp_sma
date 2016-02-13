#pragma once

#include "position.h"

class Map
{
private:
    static Map* singleton;
    Map(); // constructeur privé

    //Empecher la copie
    Map(const Map&);
    void operator=(const Map&);

    char map_[20][20];

public:
    static Map *get()
    {
        if(!singleton)
            singleton = new Map;
        return singleton;
    }

    void display() const;
    void add(char letter, int x, int y);
    void add(char letter, Position pos);
    void move(Position posPrec, Position posSuiv);
    bool isOccupied(Position pos) const;
    void erase(Position pos);

    /**
     * @brief findPositionAvailable
     * @param posCur
     * @return A random Position around the posCur, if it's not possible return position (-1, -1)
     */
    Position findPositionAvailable(Position posCur) const;

};
