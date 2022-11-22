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
	virtual bool isLocatedAt(int, int) = 0;
	virtual void defineShape() = 0;
	virtual char spriteData(int, int) = 0;
	virtual void setSprite() = 0;

private:
	int pX, pY, vX, vY;
};