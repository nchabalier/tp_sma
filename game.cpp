#include "game.h"

Game::Game()
{
    Position pos(1,1);
    Building building1("Barracks", pos, 0, 10, 1000);
    Position pos2(HEIGHT-2,WIDTH-2);
    Building building2("Gateway", pos2, 0, 10, 1000);
    Position pos3(1,WIDTH-2);
    Building building3("Hatchery", pos3, 1, 10, 1000);
    Position pos4(HEIGHT-2, 1);
    Building building4("Hatchery", pos4, 1, 10, 1000);

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
        if(VBuilding_[i].isReady())
        {
            /*Building* b = static_cast<Building *>(&(VBuilding_[i]));
            VUnit_.push_back(b->produce());*/
            VUnit_.push_back(VBuilding_[i].produce());
            VBuilding_[i].setWaiting(5); // New Waiting time before next produce
        }
        else
        {
            VBuilding_[i].wait();
        }
    }

    //-----------------------Unit actions------------------------------------------
    vector<Unit>::iterator it = VUnit_.begin();
    while(it < VUnit_.end())
    {
        if(it->isReady())
        {
            it->doAction(VBuilding_, VUnit_);
            it->setWaiting(5);
        }
        else
        {
            it->wait();
        }
        it++;
    }

    //Erase Unit and Building who have hitPoints < 0
    eraseDeadUnit();
    eraseDeadBuilding();

    //Winner
    if(VBuilding_.size() == 1)
    {
       cout << "Team " << VBuilding_[0].getTeam() << " gagne !" << endl;
       setContinue(false);
    }



    return isContinued();
}

void Game::displayDebug() const
{
    cout << endl << "Display of Building" << endl << endl;
    for(auto it : VBuilding_)
    {
        it.display();
    }

    cout << endl << "Display of Unit" << endl << endl;
    for(auto it : VUnit_)
    {
        it.display();
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
        map[it.getPosX()][it.getPosY()] = it.getName()[0];
    }

    //Unit display
    for(auto it : VUnit_)
    {
        map[it.getPosX()][it.getPosY()] = it.getName()[0];
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

}

void Game::eraseDeadBuilding()
{
    vector<Building>::iterator it = VBuilding_.begin();
    bool erased = false;

    while(it != VBuilding_.end() && erased == false)
    {
        if(it->isDead())
        {
            VBuilding_.erase(it);
            erased = true;
        }
        it++;
    }
}

void Game::eraseDeadUnit()
{
    vector<Unit>::iterator it = VUnit_.begin();
    bool erased = false;

    while(it != VUnit_.end() && erased == false)
    {
        if(it->isDead())
        {
            VUnit_.erase(it);
            erased = true;
        }
        it++;
    }
}

bool Game::emptyTeamBuilding(int team) const
{
    for(auto it : VBuilding_)
    {
        if(it.getTeam() == team)
            return false;
    }
    return true;
}

bool Game::emptyTeamUnit(int team) const
{
    for(auto it : VUnit_)
    {
        if(it.getTeam() == team)
            return false;
    }
    return true;
}
