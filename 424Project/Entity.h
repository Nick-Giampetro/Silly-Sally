#pragma once
class Entity
{
public:
	Entity();

	// position functions
	void setPos(int,int);
	int getPosX();
	int getPosY();
	
	// velocity functions
	void setVel(int, int);
	int getVelX();
	int getVelY();

	//
	char getSprite(int,int);



	// virtual functions
	virtual bool isLocatedAt(int, int) = 0;
	virtual void defineShape() = 0;
	virtual char spriteData(int, int) = 0;
	virtual void setSprite() = 0;

private:
	int pX, pY, vX, vY;
};