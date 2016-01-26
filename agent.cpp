#include "agent.h"

int Agent::compteur_ = 0;

Agent::Agent()
{
}

void Agent::takeDamage(int damage)
{
    hitPoints_-=damage;
}

void Agent::display()
{
    cout << "Id : " << id_ << endl;
    cout << "Name : " << name_ << endl;
    cout << "Pos : " << pos_.getX() << " " << pos_.getY() << endl;
    cout << "Team : " << team_ << endl;
    cout << "Waiting : " << waiting_ << endl;
    cout << "HitPoints : " << hitPoints_ << endl;
}

