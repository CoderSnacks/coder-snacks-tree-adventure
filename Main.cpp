#include <iostream>
#include "GameManagementSystem.h"
#include "pugixml.hpp"

int main()
{
	// GameManagementSystem* GMS = new GameManagementSystem();
	// GMS->initGame(true);
	// GMS->startGame();
	
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("./ExampleAdventure/ExampleAdventure.xml");
	std::cout << "Load result: " << result.description() << ", mesh name: " << doc.child("node").attribute("filename").value() << std::endl;
	return 0;
}


