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

        void makeDecision(DecisionNode* decision);
        void updateHealth();
        void updateCurrency();
        void updateCurrentDecisionNode(DecisionNode* decision);
        void print();
};

#endif