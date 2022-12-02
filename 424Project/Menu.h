#pragma once
#include"engine.h"
#include <iostream>

class Menu
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
	int speedSetting;
	char wallSprite;

	


};

