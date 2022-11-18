#pragma once

#include <vector>
#include "Entity.h" 
#include "Terrain.h"
#include "Sally.h"
#include "Wall.h"

using namespace std;

class engine
{

	static const int frameSize = 100;

public:
	engine();
	
	void frameGen();

	void frameStepper();


private:
	vector<Terrain> obstacles;
	vector<Wall> bounds;
	Sally player;

	int frameStep = 0;
	
	char frameImg[frameSize][frameSize];

};

