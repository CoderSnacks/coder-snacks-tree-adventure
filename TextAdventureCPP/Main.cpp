#include <iostream>
#include "GameManagementSystem.h"

int main()
{
	GameManagementSystem* GMS = new GameManagementSystem();
	GMS->initGame(true);
	GMS->startGame();
	return 0;
}


