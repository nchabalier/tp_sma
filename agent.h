#pragma once

#include <string>

#include "position.h"


/**
 * @brief The Agent class is an abstract class use by Unit and Building.
 */
class Agent
{
protected:
    static int compteur_; ///< Number of instance created.
    int id_;              ///< Id of Agent
    string name_;         ///< Name of Agent
    Position pos_;        ///< Position of Agent
    int team_;            ///< Team of Agent (0, 1, 2 or 3)
    int waiting_;         ///< Time before Agent can do an action (move, attack or product)
    int hitPoints_;       ///< Hit points of Agent

public:
    /**
     * @brief Agent Constructor by default of Agent
     */
    Agent();

    /**
     * @brief Agent Constructor of the Agent
     * @param name Name of Agent
     * @param pos Position of Agent
     * @param team Team of Agent
     * @param waiting Initial time before Agent can do an action
     * @param hitPoints Hit points of Agent.
     */
    Agent(string name, Position pos, int team, int waiting, int hitPoints) : name_(name), pos_(pos), team_(team), waiting_(waiting), hitPoints_(hitPoints) {id_=compteur_; compteur_++;}

    //Getter
    /**
     * @brief getName Return name of Agent
     * @return name of Agent
     */
    string getName() const {return name_;}

    /**
     * @brief getPosX Return the position X of Agent
     * @return position X of Agent
     */
    int getPosX() const {return pos_.getX();}

    /**
     * @brief getPosY Return the position Y of Agent
     * @return position Y of Agent
     */
    int getPosY() const {return pos_.getY();}

    /**
     * @brief getPos Return the position of Agent
     * @return position of Agent
     */
    Position& getPos() {return pos_;}

    /**
     * @brief getId Return ID of Agent
     * @return ID of Agent
     */
    int getId() const {return id_;}

    /**
     * @brief getTeam Return team of Agent
     * @return team of Agent
     */
    int getTeam() const {return team_;}

    /**
     * @brief getHitPoints Return hit points of Agent
     * @return hit points of Agent
     */
    int getHitPoints() const {return hitPoints_;}

    /**
     * @brief getCompteur Return number of instance of Agent
     * @return of instance of Agent
     */
    static int getCompteur() {return compteur_;}


    /**
     * @brief isReady Return true if the waiting time is over
     * @return true if Agent is ready to do action
     */
    bool isReady() const {return waiting_ <= 0;}

    /**
     * @brief wait Decrement waiting after a round
     */
    void wait() {waiting_--;}

    /**
     * @brief setWaiting Set the new waiting time before do an action
     * @param waiting New waiting time
     */
    void setWaiting(int waiting) {waiting_ = waiting;}

    /**
     * @brief isDead Test if the Agent is alive
     * @return true if life of Agent is under 0
     */
    bool isDead() const {return hitPoints_ <= 0;}

    /**
     * @brief takeDamage Inflict some damage to the Agent
     * @param damage inflicted
     */
    void takeDamage(int damage);


};
