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
    //LOAD FROM FILE
    DecisionNode* decision0 = new DecisionNode("You're on a bike, going down a sidewalk. There's a park and an oncoming car!", "Start Game", -1,-1);
    //Left of 0
    DecisionNode* decision1 = new DecisionNode("You walked into a tree!", "Turn Into Park?", 40, 0.0);
    //Right of 0
	DecisionNode* decision2 = new DecisionNode("You barely Missed the car. But Now about to be 5 minutes late", "Keep Going Forward", -20, 15);

    //Left of 1
    DecisionNode* decision3 = new DecisionNode("Storyline 5", "Talk to passersby", 10, 25);
    //Right of 1
    DecisionNode* decision5 = new DecisionNode("Storyline 5-2", "Stop and Look at phone", 140, 13);

    //left of 2
	DecisionNode* decision4 = new DecisionNode("You've made it to zoom university.", "Pedal Faster", 50, 5);
    //Right of 2
	DecisionNode* decision6 = new DecisionNode("Storyline 5-3", "Jump off of bike", 20, 15);

    decision0->setForwardPath(decision2);
    decision0->setLeftPath(decision1);
    decision1->setLeftPath(decision4);
    decision1->setRightPath(decision6);
    decision2->setLeftPath(decision3);
    decision2->setRightPath(decision5);

    return decision0;
}

void GameManagementSystem::printDecisionPrompts(){
     DecisionNode* currentNode = this->player->getCurrentDecisionNode();
     if(currentNode->getLeftPathPtr() != NULL){
         printf("L) %s ", currentNode->getLeftPathPtr()->getPrompt().c_str());
     }
     if(currentNode->getForwardPathPtr() != NULL){
         printf("F) %s ", currentNode->getForwardPathPtr()->getPrompt().c_str());
     } 
     if(currentNode->getRightPathPtr() != NULL){
         printf("R) %s ", currentNode->getRightPathPtr()->getPrompt().c_str());
     }   
}

DecisionNode* GameManagementSystem::takePath(char user_decision, DecisionNode* currentNode){
    DecisionNode* nextDecision;
    switch(tolower(user_decision)){
            case 'l':
                nextDecision = currentNode->getLeftPathPtr();
                break;
            case 'f':
                nextDecision = currentNode->getLeftPathPtr();
                break;
		    case 'r':
                nextDecision = currentNode->getRightPathPtr();
                break;
		    case 'q':
                nextDecision = NULL;
                break;
		    default:
			    printf("That's not a choice!\n");
                break;
        }
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