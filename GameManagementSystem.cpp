#include "GameManagementSystem.h"
#include <fstream>
#include <sstream>

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
    DecisionNode* decision1 = new DecisionNode("You walked into a tree!", "Turn Into Park?", 40, 0.0);
	DecisionNode* decision2 = new DecisionNode("You barely Missed the car. But Now about to be 5 minutes late", "Keep Going Forward", -20, 15);
    DecisionNode* decision3 = new DecisionNode("Storyline 5", "Talk to passersby", 10, 25);
	DecisionNode* decision4 = new DecisionNode("Storyline 5-1", "Pedal Faster", 50, 5);
    DecisionNode* decision5 = new DecisionNode("Storyline 5-2", "Stop and Look at phone", 140, 13);
	DecisionNode* decision6 = new DecisionNode("Storyline 5-3", "Jump off of bike", 20, 15);

    decision0->setForwardPath(decision2);
    decision0->setLeftPath(decision1);
    decision1->setLeftPath(decision4);
    decision1->setRightPath(decision6);
    decision2->setLeftPath(decision3);
    decision2->setRightPath(decision5);

    return decision0;
}

void GameManagementSystem::startGame(){
    bool quit = false;
	std::string user_decision;

	while(!quit){
        printf("Left) %s", this->player->getCurrentDecisionNode()->getLeftPathPtr()->getPrompt().c_str());
        printf("Right) %s", this->player->getCurrentDecisionNode()->getRightPathPtr()->getPrompt().c_str());
		std::cin >> user_decision;
		if(user_decision == "Left"){
            this->player->updateCurrentDecisionNode(this->player->getCurrentDecisionNode()->getLeftPathPtr());
			printf(this->player->getCurrentDecisionNode()->getStoryLine().c_str());
		}else if(user_decision == "Right"){
			this->player->updateCurrentDecisionNode(this->player->getCurrentDecisionNode()->getRightPathPtr());
			printf(this->player->getCurrentDecisionNode()->getStoryLine().c_str());
		}else{
			printf("That's not a choice!");
		}
	
	}
}