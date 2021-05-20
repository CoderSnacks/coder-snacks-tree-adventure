#pragma once 

#include<iostream>
#include<list>

class DecisionNode {
    private:
        int id;
        int healthRequired;
        double currencyRequired;

        std::string storyline;
        std::string prompt;
        std::list<DecisionNode*> childNodesList;
    public:
        //construstor
        DecisionNode(std::string storyline, std::string prompt, int healthRequired, double currencyRequired);

        //get info
        std::string getStoryLine();
        std::string getPrompt();
        int getHealthRequired();
        double getCurrencyRequired();
        
        //get next paths
        std::list<DecisionNode*> getPathPtrs();
        
        //set next paths
        void addPathPtr(DecisionNode* pathPtr);

        //print decision node
        std::string toString();
};
