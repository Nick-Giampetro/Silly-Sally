#include "Entity.h"


void Entity::setPos(int I, int J) {
	x = I;
	y = J;
}

int Entity::getPosX() {
	return x;
}

int Entity::getPosY() {
	return y;
}