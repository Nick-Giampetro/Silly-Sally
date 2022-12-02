#pragma once

#include <vector>
#include <Windows.h>
#include "Entity.h" 
#include "Terrain.h"
#include "Sally.h"
#include "Wall.h"
#include "frameDefinition.h"

using namespace std;

class engine : public frameDefinition
{

public:
	// where the player, and terrain objects are initiallized at the start of the game.
	engine();


	//constructor ovreide for changing settings
	engine(int, char);
	

	// used to generate a frame when called based on the current 
	void frameGen();

	// used to update the objects to the next frame
	void frameStepper();

	// used to generate initial frame
	void frameOutput();

	// used to refresh what is displayed to the frame
	void frameUpdate();

	//for returning alive status
	bool getLifeStatus();

	//for recording player key inputs
	void playerInput();

	//gets ideal frame per second
	int getFps();


private:
	// object containers for the walls, terrain and sally
	vector<Wall> bounds;
	vector<Terrain> obstacles;
	Sally player;

	// counter of the current frame in time

	int frameStep, fps ;

	// the array that contains the total frame image
	char frameImg[frameSize][frameSize];

	// contains the information of the previous frame;
	char pFrameImg[frameSize][frameSize];

	// changes to false when the player looses
	bool isAlive ;

};

