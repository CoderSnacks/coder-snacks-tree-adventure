
using namespace std;
#include <string>

#ifndef DECISION_NODE_H
#define DECISION_NODE_H

class DecisionNode {
    private:
        string storyline;
        string prompt;
        int healthRequired;
        double currencyRequired;
        DecisionNode* leftPathPtr;
        DecisionNode* rightPathPtr;
        DecisionNode* forwardPathPtr;
    public:
        //construstor
        DecisionNode(string storyline, string prompt, int healthRequired, double currencyRequired);

        //get info
        string getStoryLine();
        string getPrompt();
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


};

#endif