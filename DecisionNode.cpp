#include "DecisionNode.h"

DecisionNode::DecisionNode(std::string storyline, std::string prompt, int healthRequired, double currencyRequired){
    this->storyline = storyline;
    this->prompt = prompt;
    this->healthRequired = healthRequired;
    this->currencyRequired = currencyRequired;

    this->leftPathPtr = NULL;
    this->rightPathPtr = NULL;
    this->forwardPathPtr = NULL;
}

std::string DecisionNode::getStoryLine(){
    return this->storyline;
}
std::string DecisionNode::getPrompt(){
    return this->prompt;
}
int DecisionNode::getHealthRequired(){
    return this->healthRequired;
}
double DecisionNode::getCurrencyRequired(){
    return this->currencyRequired;
}

void DecisionNode::setLeftPath(DecisionNode* path){
    this->leftPathPtr = path;
}
void DecisionNode::setRightPath(DecisionNode* path){
    this->rightPathPtr = path;
}
void DecisionNode::setForwardPath(DecisionNode* path){
    this->forwardPathPtr = path;
}

DecisionNode* DecisionNode::getLeftPathPtr(){
    return this->leftPathPtr;
}
DecisionNode* DecisionNode::getRightPathPtr(){
    return this->rightPathPtr;
}
DecisionNode* DecisionNode::getForwardPathPtr(){
    return this->forwardPathPtr;
}
// Create tostd::string for decision node()
