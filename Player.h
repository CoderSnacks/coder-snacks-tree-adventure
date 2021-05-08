#include <iostream>
#include "DecisionNode.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player{
    private:
        std::string name;
        int health;
        double currency;
        DecisionNode* currentDecision;
    public:
        //constructor
        Player(std::string name);
        Player(std::string name, int health, int currency);

        std::string getName();
        int getHealth();
        double getCurrency();
        DecisionNode* getCurrentDecisionNode();
        //make a decision and determine health/currency afterwords
        void makeDecision(DecisionNode* decision);
        //updateHealth & Currency
        void updateHealth();
        void updateCurrency();
        void updateCurrentDecisionNode(DecisionNode* decision);
};

#endif