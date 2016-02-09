#include "building.h"
#include <cstdlib>
#include <cmath>

Building::Building()
{
}
/*
Building::Building(int i, Position pos, int team)
{
    switch(i)
    {
        case 1 :
        {
            Agent("Barracks", pos, team, 0, 1500);
            break;
        }
        case 2 :
        {
            Agent("Gateway", pos, team, 0, 2000);
            break;
        }
        case 3 :
        {
            Agent("Hatchery", pos, team, 0, 1500);
            break;
        }
    }
}
*/
/*
Unit Building::produce()
{


    //Nombre aléatoire entre 0 et 4
    //Si le nombre est inférieur à 2 on produit l'unité sur l'axe horizontal
    //Sinon sur l'axe vertical
    int alea = rand()%4;
    Position newPos;

    if(alea < 2)
    {
        alea = pow(-1, rand()%2);
        newPos.move(pos_.getX()+alea, pos_.getY());
    }
    else
    {
        alea = pow(-1, rand()%2);
        newPos.move(pos_.getX(), pos_.getY()+alea);
    }

    string newName;
    int waitingTime;

    //TODO : changer les valeurs de vitesse en fonction du type d'unité
    //TODO : afficher une erreur si le batiment n'est pas un de ces 3 la
    if(name_ == "Barracks")
    {
        newName = "Terran";
        waitingTime = 25;
    }
    else if(name_ == "Gateway")
    {
        newName = "Protoss";
        waitingTime = 38;
    }
    else if(name_ == "Hatchery")
    {
        newName = "Zerg";
        waitingTime = 12;
    }
    //Unit(string name, Position pos, int team, int waiting, int hitPoints, int sight, int moveSpeed, int range, int attackDamage, int attackSpeed)
    Unit newUnit(newName, newPos, team_);

    return newUnit;
}
*/

Barracks::Barracks(Position pos, int team) : Building("Barracks", pos, team, 0, 1500)
{

}

void Barracks::produce(vector<Unit *> &VUnit_)
{
    int alea = rand()%4;
    Position newPos;

    if(alea < 2)
    {
        alea = pow(-1, rand()%2);
        newPos.move(pos_.getX()+alea, pos_.getY());
    }
    else
    {
        alea = pow(-1, rand()%2);
        newPos.move(pos_.getX(), pos_.getY()+alea);
    }

    setWaiting(25);
    Marine * newMarine = new Marine(newPos, team_);

    VUnit_.push_back(newMarine);
    cout << "Marine produit" << endl;
}

Gateway::Gateway(Position pos, int team) : Building("Gateway", pos, team, 0, 2000)
{

}

void Gateway::produce(vector<Unit *> &VUnit_)
{
    int alea = rand()%4;
    Position newPos;

    if(alea < 2)
    {
        alea = pow(-1, rand()%2);
        newPos.move(pos_.getX()+alea, pos_.getY());
    }
    else
    {
        alea = pow(-1, rand()%2);
        newPos.move(pos_.getX(), pos_.getY()+alea);
    }

    setWaiting(38);
    Zealot * newZealot = new Zealot(newPos, team_);

    VUnit_.push_back(newZealot);
    cout << "Zealot produit" << endl;
}

Hatchery::Hatchery(Position pos, int team) :  Building("Hatchery", pos, team, 0, 1500)
{

}

void Hatchery::produce(vector<Unit *> &VUnit_)
{
    int alea = rand()%4;
    Position newPos;

    if(alea < 2)
    {
        alea = pow(-1, rand()%2);
        newPos.move(pos_.getX()+alea, pos_.getY());
    }
    else
    {
        alea = pow(-1, rand()%2);
        newPos.move(pos_.getX(), pos_.getY()+alea);
    }

    setWaiting(24);
    Ling * newLing1 = new Ling(newPos, team_);
    Ling * newLing2 = new Ling(newPos, team_);

    VUnit_.push_back(newLing1);
    VUnit_.push_back(newLing2);
    cout << "2 Lings produits" << endl;
}
