#include "DecisionNode.h"
#include<list>

DecisionNode::DecisionNode(std::string storyline, std::string prompt, int healthRequired, double currencyRequired){
    this->storyline = "";
    this->prompt = prompt;
    this->healthRequired = NULL;
    this->currencyRequired = NULL;
    
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

std::list<DecisionNode*> DecisionNode::getPathPtrs(){
    return this->childNodesList;
}

void DecisionNode::addPathPtr(DecisionNode* pathPtr){
    this->childNodesList.push_back(pathPtr);
}