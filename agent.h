#ifndef AGENT_H
#define AGENT_H

#include "iostream"
#include <string>
#include "position.h"
using namespace std;


class Agent
{
protected:
    static int compteur_;
    int id_;
    string name_;
    Position pos_;
    int team_;
    int waiting_;
    int hitPoints_;

public:
    Agent();
    Agent(string name, Position pos, int team, int waiting, int hitPoints) : name_(name), pos_(pos), team_(team), waiting_(waiting), hitPoints_(hitPoints) {id_=compteur_; compteur_++;}
    //virtual ~Agent();

    string getName() const {return name_;}
    int getPosX() const {return pos_.getX();}
    int getPosY() const {return pos_.getY();}
    Position& getPos() {return pos_;}
    int getId() const {return id_;}
    int getTeam() const {return team_;}
    int getHitPoints() const {return hitPoints_;}
    static int getCompteur() {return compteur_;}
    bool isReady() const {return waiting_ <= 0;}
    void wait() {waiting_--;}
    void setWaiting(int waiting) {waiting_ = waiting;}

    bool isDead() const {return hitPoints_ <= 0;}

    void takeDamage(int damage);
    void display();


};


#endif // AGENT_H
