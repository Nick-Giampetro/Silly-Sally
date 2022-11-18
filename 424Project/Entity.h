#pragma once
class Entity
{
public:
	Entity();

	void setPos(int,int);
	int getPosX();
	int getPosY();
	
	void setVel(int, int);
	int getVelX();
	int getVelY();

	// need to think about how this is going to work
	// void defineShape();

private:
	int pX, pY, vX, vY;
};

