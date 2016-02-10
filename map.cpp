#include "map.h"
#include <math.h>
#include <iostream>

using namespace std;

Map *Map::singleton = nullptr;

Map::Map()
{
    cout << "Construction Map" << endl;
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            map_[i][j] = ' ';
        }
    }
}

void Map::display() const
{
    for(int i = 0; i<20; i++)
    {
        cout << '|';
        for(int j = 0; j<20; j++)
        {
            cout << map_[i][j];
        }
        cout << '|' << endl;
    }
}

void Map::add(char letter, int x, int y)
{
    map_[x][y] = letter;
}

void Map::add(char letter, Position pos)
{
    map_[pos.getX()][pos.getY()] = letter;
}

void Map::move(Position posPrec, Position posSuiv)
{
    map_[posSuiv.getX()][posSuiv.getY()] = map_[posPrec.getX()][posPrec.getY()];
    map_[posPrec.getX()][posPrec.getY()] = ' ';
}

bool Map::isOccupied(Position pos) const
{
    if(map_[pos.getX()][pos.getY()] == ' ')
        return false;
    else
        return true;
}

void Map::erase(Position pos)
{
    map_[pos.getX()][pos.getY()] = ' ';
}

Position Map::findPositionAvailable(Position posCur) const
{
    bool producted = false;
    int alea = rand()%4;
    Position newPos(-1,-1);
    Map* map = Map::get();

    if(alea < 2)
    {
        alea = pow(-1, rand()%2);
        newPos.move(posCur.getX()+alea, posCur.getY());
        producted = !map->isOccupied(newPos);
        if(!producted)
        {
            newPos.move(posCur.getX()-alea, posCur.getY());
            producted = !map->isOccupied(newPos);
        }
    }

    if(!producted)
    {
        alea = pow(-1, rand()%2);
        newPos.move(posCur.getX(), posCur.getY()+alea);
        producted = !map->isOccupied(newPos);
        if(!producted)
        {
            newPos.move(posCur.getX(), posCur.getY()-alea);
            producted = !map->isOccupied(newPos);
        }
    }
    if(!producted)
        newPos.move(-1,-1);

    return newPos;
}
