#include<iostream>
#include "DecisionNode.h"
#include "Player.h"

#ifndef GAME_MANAGEMENT_SYSTEM_H
#define GAME_MANAGEMENT_SYSTEM_H

class GameManagementSystem {
    private:
        //properties
        Player* player;
        DecisionNode* head;
        //helper methods
        Player* createPlayer(std::string name);
        DecisionNode* createDecisionTree();
    public:
        void initGame(bool isNewGame);
        void startGame();
};

#endif
