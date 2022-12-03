#include "Entity.h"

// constructor
Entity::Entity() {
	pX = 0;
	pY = 0;
	vX = 0;
	vY = 0;
}


// postition position values
void Entity::setPos(int I, int J) {
	pX = I;
	pY = J;

	this->defineShape();
}
// gets object's y velocity
int Entity::getPosX() {
	return pX;
}
// gets object's y velocity
int Entity::getPosY() {
	return pY;
}

// sets velocity values
void Entity::setVel(int I, int J) {
	vX = I;
	vY = J;
}
// gets object's x velocity
int Entity::getVelX() {
	return vX;
}
// gets object's y velocity
int Entity::getVelY() {
	return vY;
}

// returns a character from an entity object at a specific location
char Entity::getSprite(int I, int J, char cImg) {
	if (this->isLocatedAt(I, J))
		return this->spriteData(I, J);
	
	return cImg;
}