#pragma once

#include <vector>
#include "Entity.h" 
#include "Terrain.h"
#include "Sally.h"
#include "Wall.h"

using namespace std;

class engine
{
public:
	engine();
	


	void frameStepper();

private:
	vector<Terrain> obstacles;
	vector<Wall> bounds;
	Sally player;

	int frameStep,frameSize = 100;
};

