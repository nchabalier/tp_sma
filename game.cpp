#include "game.h"
#include "map.h"
#include "iostream"
#include <algorithm>

Game::Game()
{
    Map* map = Map::get();

    Position pos(1,1);

    //Building building1(1, pos, 0);
    Barracks * building1 = new Barracks(pos, 0);
    Position pos2(HEIGHT-2,WIDTH-2);
    map->add(building1->getName()[0], pos);

    //Building building2(2, pos2, 0);
    Gateway * building2 = new Gateway(pos2, 1);
    map->add(building2->getName()[0], pos2);

    Position pos3(1,WIDTH-2);
    //Building building3(3, pos3, 1);
    Hatchery * building3 = new Hatchery(pos3, 0);
    map->add(building3->getName()[0], pos3);

    Position pos4(HEIGHT-2, 1);
    //Building building4(3, pos4, 1);
    Hatchery * building4 = new Hatchery(pos4, 1);
    map->add(building4->getName()[0], pos4);

    /*
    Position posTest(0,1);
    map->add('T', posTest);
    posTest.move(1,0);
    map->add('T', posTest);
    posTest.move(2,1);
    map->add('T', posTest);
    posTest.move(1,2);
    map->add('T', posTest);
    */

    VBuilding_.push_back(building1);
    VBuilding_.push_back(building2);
    VBuilding_.push_back(building3);
    VBuilding_.push_back(building4);
    continue_ = true;
}

Game::Game(BuildingFactory fac, int teams, int perTeam, char races[16])
{
    Map* map = Map::get();
    Position pos;
    Building * bat = nullptr;
    for(int i = 0; i < perTeam; i++)
    {
        pos.move(1,1+(2*i));
        bat = fac.create(races[i*teams], pos, 0);
        VBuilding_.push_back(bat);
        map->add(bat->getName()[0], pos);

        pos.move(HEIGHT-1, WIDTH-1-(2*i));
        bat = fac.create(races[i*teams+1], pos, 1);
        VBuilding_.push_back(bat);
        map->add(bat->getName()[0], pos);

        if (teams > 2)
        {
            pos.move(1+(2*i), WIDTH-1);
            bat = fac.create(races[i*teams+2], pos, 2);
            VBuilding_.push_back(bat);
            map->add(bat->getName()[0], pos);
        }
        if(teams > 3)
        {
            pos.move(HEIGHT-1-(2*i), 1);
            bat = fac.create(races[i*teams+3], pos, 3);
            VBuilding_.push_back(bat);
            map->add(bat->getName()[0], pos);
        }
    }
}

bool Game::play()
{
    //Ransomize vector of Building and vector of Unit for equality
     std::random_shuffle ( VBuilding_.begin(), VBuilding_.end());
     std::random_shuffle ( VUnit_.begin(), VUnit_.end());

    //----------------------Production of Unit------------------------------------
    for(unsigned int i =0; i<VBuilding_.size(); i++)
    {
        if(VBuilding_[i]->isReady())
        {
            VBuilding_[i]->produce(VUnit_);
        }
        else
        {
            VBuilding_[i]->wait();
        }
    }

    //-----------------------Unit actions------------------------------------------
    vector<Unit *>::iterator it = VUnit_.begin();
    while(it < VUnit_.end())
    {
        if((*it)->isReady())
        {
            (*it)->doAction(VBuilding_, VUnit_);
        }
        else
        {
            (*it)->wait();
        }
        it++;
    }

    for(unsigned int i =0; i<VBuilding_.size(); i++)
    {
        cout <<  VBuilding_[i]->getName() << " : " << VBuilding_[i]->getHitPoints() << endl;
    }

    //Erase Unit and Building who have hitPoints < 0
    eraseDeadUnit();
    eraseDeadBuilding();

    //Winner
    if(!isTeamAlive())
    {
       cout << "Team " << VBuilding_[0]->getTeam() << " gagne !" << endl;
       setContinue(false);
    }
    return isContinued();
}


void Game::diplayMap() const
{
//    cout << endl << "Map display" << endl << endl;
//    char map[HEIGHT][WIDTH] = {0};

//    //Initialization
//    for(int i = 0; i<HEIGHT; i++)
//    {
//        for(int j = 0; j<WIDTH; j++)
//        {
//            map[i][j] = ' ';
//        }
//    }


//    //Building display
//    for(auto it : VBuilding_)
//    {
//        map[it->getPosX()][it->getPosY()] = it->getName()[0];
//    }

//    //Unit display
//    for(auto it : VUnit_)
//    {
//        map[it->getPosX()][it->getPosY()] = it->getName()[0];
//    }

//    //Map display
//    for(int i = 0; i<HEIGHT; i++)
//    {
//        cout << '|';
//        for(int j = 0; j<WIDTH; j++)
//        {
//            cout << map[i][j];
//        }
//        cout << '|' << endl;
//    }
    Map* test_map = Map::get();
    test_map->display();

}

void Game::eraseDeadBuilding()
{
    vector<Building *>::iterator it = VBuilding_.begin();
    Map* map = Map::get();

    while(it != VBuilding_.end())
    {
        if((*it)->isDead())
        {
            map->erase((*it)->getPos());
            it = VBuilding_.erase(it);
        }
        else
            it++;
    }
}

void Game::eraseDeadUnit()
{
    vector<Unit *>::iterator it = VUnit_.begin();
    Map* map = Map::get();

    while(it != VUnit_.end())
    {
        if((*it)->isDead())
        {
            map->erase((*it)->getPos());
            it = VUnit_.erase(it);
        }
        else
            it++;
    }
}

bool Game::emptyTeamBuilding(int team) const
{
    for(auto it : VBuilding_)
    {
        if(it->getTeam() == team)
            return false;
    }
    return true;
}

bool Game::emptyTeamUnit(int team) const
{
    for(auto it : VUnit_)
    {
        if(it->getTeam() == team)
            return false;
    }
    return true;
}

bool Game::isTeamAlive()
{
    vector<Building *>::iterator it = VBuilding_.begin();
    int team = (*it)->getTeam();
    it++;
    while(it != VBuilding_.end() && (*it)->getTeam()==team)
        it++;

    if(it == VBuilding_.end())
        return false;
    else
        return true;
}
