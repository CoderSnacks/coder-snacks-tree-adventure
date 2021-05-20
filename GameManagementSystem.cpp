#include "GameManagementSystem.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

void GameManagementSystem::initGame(bool isNewGame){
    this->head = createDecisionTree();

    //create player
    if(isNewGame){
        //prompt for player name
        std::string name = "Jhon";
        this->player = createPlayer(name);
        this->player->updateCurrentDecisionNode(this->head);
    }else{
        //load in player name, health, and currency, current decision
        this->player = NULL;
    }
    //create full decision tree
}

Player* GameManagementSystem::createPlayer(std::string name){
    Player* player = new Player(name);
    return player;
}

DecisionNode* GameManagementSystem::createDecisionTree(){
    //if current node is a leaf
       //create node object and return it
    //else:
      //for each childId->create children nodes
      //create current node, with children as parameters
    return NULL;
}

void GameManagementSystem::printDecisionPrompts(){
     DecisionNode* currentNode = this->player->getCurrentDecisionNode();
    
}

DecisionNode* GameManagementSystem::takePath(char user_decision, DecisionNode* currentNode){
    DecisionNode* nextDecision;
    
    return nextDecision;
}

void GameManagementSystem::startGame(){
    DecisionNode* nextDecision;
	char user_decision;
	while(user_decision != 'Q'){
        DecisionNode* currentNode = this->player->getCurrentDecisionNode();
        printf("%s\n", this->player->getCurrentDecisionNode()->getStoryLine().c_str());
        this->printDecisionPrompts();
		std::cin >> user_decision;
        nextDecision = takePath(user_decision, currentNode);

        this->player->makeDecision(nextDecision);
        this->player->print();
	}
}