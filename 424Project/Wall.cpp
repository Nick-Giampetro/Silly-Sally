#include "Wall.h"


Wall::Wall() {
	setVel(0, 0);
	
	//initalize array of 0 so IDE is happy
	for (int j = 0; j < framesize; j++)
	{
		imgPos[j][0] = 0;
		imgPos[j][1] = 0;
		wallSprite[j] = 0;
	}
	
}

Wall::~Wall() {}

Wall::Wall(int x, int y) {
	this->setPos(x, y);

	//still making IDE happy
	for (int j = 0; j < framesize; j++)
	{
		imgPos[j][0] = 0;
		imgPos[j][1] = 0;
		wallSprite[j] = 0;
	}
}


bool Wall::isLocatedAt(int I, int J) {

	//returns the location of walls in the frame
	for (int j = 0; j < framesize; j++)
	{
		if (imgPos[j][0] == I && imgPos[j][1] == J)
			return true;

	}
	return false;
}

char Wall::spriteData(int I,int J) 
{
	//This sends the wall sprite back
	for (int j = 0; j < framesize; j++)
	{
		if (imgPos[j][0] == I && imgPos[j][1] == J)
			return wallSprite[j];

	}

}

void Wall::setSprite()
{
	//This allows for the program to change the wall sprite while running (maybe a graphic setting?)
	for (int i = 0; i < framesize; i++)
	{
		wallSprite[i] = '*';
	}
	
}

void Wall::defineShape()
{
	//creates the wall sprite in the frame so that location data can be extracted for master frame
	for (int j = 0; j < framesize; j++) 
	{
		imgPos[j][0] = this->getPosX();
		imgPos[j][1] = this->getPosY() + j;
	}
}