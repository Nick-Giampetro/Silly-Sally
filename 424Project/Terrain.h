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

public:

	Terrain();
	Terrain(int);
	~Terrain();

	void defineShape();

	char spriteData();
	void setSprite();
	int getLineType();
	int getHoleType();

private:
	int lineType = 1;
	int holeType;
	char img[frameSize];


};

