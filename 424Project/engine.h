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
	void setEntites(Wall,Terrain,Sally);
	

	void frameStepper();

private:
	vector<Terrain> Terrain;
	Sally player;

	int frameStep,frameSize = 100;
};

