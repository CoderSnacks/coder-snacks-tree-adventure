#include <iostream>
#include <fstream>
#include <sstream>
#include "decision_node.h"

using namespace std;

int main()
{
	printf("You're on a bike, going down a sidewalk. There's a park and an oncoming car!\n");
	DecisionNode* decision1 = new DecisionNode("You walked into a tree!", "Turn Into Park?", 40, 0.0);
	DecisionNode* decision2 = new DecisionNode("You barely Missed the car. But Now about to be 5 minutes late", "Keep Going Forward", 20, 15);

	printf("Choose One:\n");
	printf("Left) %s ", decision1->getPrompt().c_str());
	printf("Forward) %s\n", decision2->getPrompt().c_str());

	string user_decision;
	std::cin >> user_decision;
	if(user_decision == "Left"){
		printf(decision1->getStoryLine().c_str());
	}else if(user_decision == "Forward"){
		printf(decision2->getStoryLine().c_str());
	}else{
		printf("That's not a choice!");
	}
	
	return 0;
}


