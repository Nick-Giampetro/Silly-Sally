#include "Entity.h"

// postition functions
void Entity::setPos(int I, int J) {
	pX = I;
	pY = J;
}
int Entity::getPosX() {
	return pX;
}
int Entity::getPosY() {
	return pY;
}

//velocity functions
void Entity::setVel(int I, int J) {
	vX = I;
	vY = J;
}
int Entity::getVelX() {
	return vX;
}
int Entity::getVelY() {
	return vY;
}