#pragma once
#include"engine.h"
#include"frameDefinition.h"
#include <iostream>

class Menu : public frameDefinition
{
public:
	Menu();
	~Menu();

	void startup();
	void mainMenu();
	void gameOptions();
	void graphicsMenu();
	void run();

private:
	int choice;
	bool quit;
	unsigned int speedSetting;
	char wallSprite;
	int winScore;
	


};

