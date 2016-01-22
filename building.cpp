#include "building.h"
#include <cstdlib>
#include <cmath>

Building::Building()
{
}

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
        newName = "Marine";
        waitingTime = 3;
    }
    else if(name_ == "Gateway")
    {
        newName = "Zealot";
        waitingTime = 4;
    }
    else if(name_ == "Hatchery")
    {
        newName = "Ergling";
        waitingTime = 3;
    }
    //Unit(string name, Position pos, int team, int waiting, int hitPoints, int sight, int moveSpeed, int range, int attackDamage, int attackSpeed)
    Unit newUnit(newName, newPos, team_, waitingTime, 100, 3, 2, 2, 20, 60);

    return newUnit;
}
