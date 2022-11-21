#include "Wall.h"


Wall::Wall() {
	setVel(0, 0);
}

Wall::Wall(int x, int y) {
	this->setPos(x, y);
}

char Wall::spriteData()
{

	return wallSprite;
}

void Wall::setSprite()
{
	wallSprite = '*';
}

void Wall::defineShape()
{
	//I feel like the wall just needs to be single char that we loop into the terrain generation
}
