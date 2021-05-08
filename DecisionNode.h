#include<iostream>

#ifndef DECISION_NODE_H
#define DECISION_NODE_H

class DecisionNode {
    private:
        std::string storyline;
        std::string prompt;
        int healthRequired;
        double currencyRequired;
        DecisionNode* leftPathPtr;
        DecisionNode* rightPathPtr;
        DecisionNode* forwardPathPtr;
    public:
        //construstor
        DecisionNode(std::string storyline, std::string prompt, int healthRequired, double currencyRequired);

        //get info
        std::string getStoryLine();
        std::string getPrompt();
        int getHealthRequired();
        double getCurrencyRequired();
        
        //get next paths
        DecisionNode* getLeftPathPtr();
        DecisionNode* getRightPathPtr();
        DecisionNode* getForwardPathPtr();

        //set next paths
        void setLeftPath(DecisionNode* path);
        void setRightPath(DecisionNode* path);
        void setForwardPath(DecisionNode* path);

        //print decision node
        std::string toString();
};

#endif