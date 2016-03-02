#include "building.h"
#include <cstdlib>
#include <cmath>
#include "iostream"
#include "map.h"

Building::Building()
{
}

Barracks::Barracks(Position pos, int team) : Building("Barracks", pos, team, 0, 1500)
{

}

void Barracks::produce(vector<Unit *> &VUnit_)
{
    Map* map = Map::get();
    Position newPos = map->findPositionAvailable(pos_);

    if(newPos.getX() != -1) //Si la position est bien disponible
    {
        setWaiting(125);
        Marine * newMarine = new Marine(newPos, team_);

        map->add(newMarine->getName()[0], newPos);
        VUnit_.push_back(newMarine);
    }
}

Gateway::Gateway(Position pos, int team) : Building("Gateway", pos, team, 0, 2000)
{

}

void Gateway::produce(vector<Unit *> &VUnit_)
{

    Map* map = Map::get();
    Position newPos = map->findPositionAvailable(pos_);

    if(newPos.getX() != -1)
    {
        setWaiting(190);
        Zealot * newZealot = new Zealot(newPos, team_);

        Map* map = Map::get();
        map->add(newZealot->getName()[0], newPos);
        VUnit_.push_back(newZealot);
    }
}

Hatchery::Hatchery(Position pos, int team) :  Building("Hatchery", pos, team, 0, 1500)
{

}

void Hatchery::produce(vector<Unit *> &VUnit_)
{

    Map* map = Map::get();

    for(int i = 0; i < 2; i++)
    {
        Position newPos = map->findPositionAvailable(pos_);

        if(newPos.getX() != -1)
        {
            setWaiting(120);
            Ling * newLing1 = new Ling(newPos, team_);
            map->add(newLing1->getName()[0], newPos);
            VUnit_.push_back(newLing1);
        }
     }
}

Building * BuildingFactory::create(char race, Position pos, int team)
{
    Building * bat = nullptr;
    if (race == 'T' || race == 't')
    {
        bat = new Barracks(pos, team);
    }
    if (race == 'P' || race == 'p')
    {
        bat = new Gateway(pos, team);
    }
    if (race == 'Z' || race == 'z')
    {
        bat = new Hatchery(pos, team);
    }
    return bat;
}
