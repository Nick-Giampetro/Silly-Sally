#include "Wall.h"


Wall::Wall() {
	setVel(0, 0);
}

Wall::~Wall() {}

Wall::Wall(int x, int y) {
	this->setPos(x, y);
}


bool Wall::isLocatedAt(int I, int J) {
	for (int j = 0; j < framesize; j++)
	{
		if (imgPos[j][0] == I && imgPos[j][1] == J)
			return true;

	}
	return false;
}

char Wall::spriteData(int I,int J) 
{
	for (int j = 0; j < framesize; j++)
	{
		if (imgPos[j][0] == I && imgPos[j][1] == J)
			return wallSprite[j];

	}

}

void Wall::setSprite()
{
	for (int i = 0; i < framesize; i++)
	{
		wallSprite[i] = '*';
	}
	
}

void Wall::defineShape()
{
	for (int j = 0; j < framesize; j++) 
	{
		imgPos[j][0] = this->getPosX();
		imgPos[j][1] = this->getPosY() + j;
	}
}