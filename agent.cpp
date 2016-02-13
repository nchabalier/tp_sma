#include "agent.h"

int Agent::compteur_ = 0;

Agent::Agent()
{
}

void Agent::takeDamage(int damage)
{
    hitPoints_-=damage;
}

