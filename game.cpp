#include "game.h"
#include "map.h"

Game::Game()
{
    Map* map = Map::get();

    Position pos(1,1);
    //Building building1(1, pos, 0);
    Barracks * building1 = new Barracks(pos, 0);
    Position pos2(HEIGHT-2,WIDTH-2);
    map->add(building1->getName()[0], pos);

    //Building building2(2, pos2, 0);
    Gateway * building2 = new Gateway(pos2, 0);
    map->add(building2->getName()[0], pos2);

    Position pos3(1,WIDTH-2);
    //Building building3(3, pos3, 1);
    Hatchery * building3 = new Hatchery(pos3, 1);
    map->add(building3->getName()[0], pos3);

    Position pos4(HEIGHT-2, 1);
    //Building building4(3, pos4, 1);
    Hatchery * building4 = new Hatchery(pos4, 1);
    map->add(building4->getName()[0], pos4);

    VBuilding_.push_back(building1);
    VBuilding_.push_back(building2);
    VBuilding_.push_back(building3);
    VBuilding_.push_back(building4);
    continue_ = true;
}

bool Game::play()
{
    //----------------------Production of Unit------------------------------------
    for(unsigned int i =0; i<VBuilding_.size(); i++)
    {
        if(VBuilding_[i]->isReady())
        {
            /*Building* b = static_cast<Building *>(&(VBuilding_[i]));
            VUnit_.push_back(b->produce());*/
            VBuilding_[i]->produce(VUnit_);
            //VBuilding_[i].setWaiting(5); // New Waiting time before next produce
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
            //(*it)->setWaiting(5);
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

void Game::displayDebug() const
{
    cout << endl << "Display of Building" << endl << endl;
    for(auto it : VBuilding_)
    {
        it->display();
    }

    cout << endl << "Display of Unit" << endl << endl;
    for(auto it : VUnit_)
    {
        it->display();
    }
}

void Game::diplayMap() const
{
    cout << endl << "Map display" << endl << endl;
    char map[HEIGHT][WIDTH] = {0};

    //Initialization
    for(int i = 0; i<HEIGHT; i++)
    {
        for(int j = 0; j<WIDTH; j++)
        {
            map[i][j] = ' ';
        }
    }


    //Building display
    for(auto it : VBuilding_)
    {
        map[it->getPosX()][it->getPosY()] = it->getName()[0];
    }

    //Unit display
    for(auto it : VUnit_)
    {
        map[it->getPosX()][it->getPosY()] = it->getName()[0];
    }

    //Map display
    for(int i = 0; i<HEIGHT; i++)
    {
        cout << '|';
        for(int j = 0; j<WIDTH; j++)
        {
            cout << map[i][j];
        }
        cout << '|' << endl;
    }
//    Map* test_map = Map::get();
//    test_map->display();

}

void Game::eraseDeadBuilding()
{
    vector<Building *>::iterator it = VBuilding_.begin();
    bool erased = false;

    while(it != VBuilding_.end() && erased == false)
    {
        if((*it)->isDead())
        {
            VBuilding_.erase(it);
            erased = true;
        }
        it++;
    }
}

void Game::eraseDeadUnit()
{
    vector<Unit *>::iterator it = VUnit_.begin();
    bool erased = false;

    while(it != VUnit_.end() && erased == false)
    {
        if((*it)->isDead())
        {
            VUnit_.erase(it);
            //erased = true;
        }
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
