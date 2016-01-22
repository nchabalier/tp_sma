#ifndef MAP_H
#define MAP_H

#include "agent.h"

class Agent;

class Coordinate
{
	protected:
	int x_;
	int y_;
	Agent * occupier_;
	
	public:
	Coordinate();
	Coordinate(int x, int y);
	
	int 	getX() {return x_;}
	int 	getY() {return y_;}
	Agent * getOccupier() {return occupier_;}
	
    void 	setOccupier(Agent * newAgent) {occupier_ = newAgent;}
	
    ~Coordinate();
};
	
#endif
