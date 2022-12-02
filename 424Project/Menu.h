#pragma once
#include<iostream>
#include"engine.h"
#include"Terrain.h"
#include"Wall.h"
#include"Terrain.h"
#include"Sally.h"

class Menu
{
public:
	Menu();
	~Menu();

	void startup(engine&);
	void mainMenu(engine&);
	void gameOptions(engine&);
	void graphicsMenu(engine&);

private:
	int choice;
	bool quit;
	


};

