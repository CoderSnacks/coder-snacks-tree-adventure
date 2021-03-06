#include "Player.h"
#include "DecisionNode.h"

Player::Player(std::string name){
    this->name = name;
    this->health = 0;
    this->currency = 0;
    this->currentDecision = NULL;
}

Player::Player(std::string name, int health, int currency){
    this->name = name;
    this->health = health;
    this->currency = currency;
    this->currentDecision = NULL;
}

std::string Player::getName(){
    return this->name;
}

double Player::getCurrency(){
    return this->currency;
}

int Player::getHealth(){
    return this->health;
}

DecisionNode* Player::getCurrentDecisionNode(){
    return this->currentDecision;
}

void Player::updateCurrentDecisionNode(DecisionNode* decision){
    this->currentDecision = decision;
}
void Player::makeDecision(DecisionNode* decision){
    this->currentDecision = decision;
    int healthDifference = decision->getHealthRequired() - this->health;
    double currencyDifference = decision->getCurrencyRequired() - this->currency;
    this->health += healthDifference;
    this->currency += currencyDifference;
}

void Player::print(){
    printf("Current Decision: %s\n Health: %d\n Currency: %f\n", this->currentDecision->getStoryLine().c_str(), this->health, this->currency);
}