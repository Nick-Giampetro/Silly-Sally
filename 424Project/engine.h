#pragma once

#include <vector>
#include "Entity.h" 
#include "Terrain.h"
#include "Sally.h"
#include "Wall.h"

using namespace std;

class engine
{

	// size of the frame image
	static const int frameSize = 100;

public:
	// where the player, and terrain objects are initiallized at the start of the game.
	engine();
	
	// used to generate a frame when called based on the current 
	void frameGen();

	// used to update the objects to the next frame
	void frameStepper();


private:
	// object containers for the walls, terrain and sally
	vector<Terrain> obstacles;
	vector<Wall> bounds;
	Sally player;

	// counter of the current frame in time
	int frameStep ;
	
	// the array that contains the total frame image
	char frameImg[frameSize][frameSize];

	// changes to false when the player looses
	bool isAlive ;

};

