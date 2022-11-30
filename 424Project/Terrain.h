#pragma once

#include <iostream>
#include "Entity.h"
#include "array"
#include "engine.h"
#include <time.h>
#include <stdlib.h>
using namespace std;

class Terrain : public Entity
{

	static const int frameSize = 100;
	static const int lineLength = 5;

public:

	Terrain();
	Terrain(int);
	~Terrain();

	bool isLocatedAt(int, int);
	void defineShape();
	char spriteData(int, int);
	void setSprite();
	
	int getLineType();
	int getHoleType();

private:
	int lineType = 1;
	int holeType;
	char img[lineLength];
	int imgPos[lineLength][2];


};

