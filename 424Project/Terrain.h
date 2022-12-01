#pragma once

#include "Entity.h"
#include <time.h>
#include <stdlib.h>
using namespace std;

class Terrain : public Entity
{

	static const int frameSize = 50;
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
	int lineType;
	int holeType;
	char img[frameSize];
	int imgPos[frameSize][2];


};

