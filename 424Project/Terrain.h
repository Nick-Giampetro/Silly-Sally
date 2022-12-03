#pragma once

#include "Entity.h"
#include <time.h>
#include <stdlib.h>
using namespace std;

class Terrain : public Entity
{
public:
	//constructors and deconstructors
	Terrain();
	Terrain(int);
	~Terrain();

	//virtual functions from entity which need to be initialized
	bool isLocatedAt(int, int);		//returns true if the terrain is located at a coordinate
	void defineShape();				//defines the coordinates of each sprite cell location in the terrain
	char spriteData(int, int);		//returns the character of the terrain at a given location
	void setSprite();				//creates the terrain sprite
	
	//gets and sets for terrain
	int getLineType();
	void setLineType(char);
	int getHoleType();

private:
	//initialization of variables in the terrain class
	char lineType = '-';
	int holeType = 3;
	char img[frameSize];
	int imgPos[frameSize][2];
	int terrainSpeed = 1;

};

