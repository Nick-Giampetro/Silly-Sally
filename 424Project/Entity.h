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

	// function that engine will call to see if there is a sprite at that location and return it
	char getSprite(int,int);



	// virtual functions need to be filled in with child specific information
	virtual bool isLocatedAt(int, int) = 0;		// tests if the entity object is occupying a location
	virtual void defineShape() = 0;				// defines the location of each cell of the sprite
	virtual char spriteData(int, int) = 0;		// returns the sprite at a location
	virtual void setSprite() = 0;				// defines the sprite array

private:
	// position and velocity variables
	int pX, pY, vX, vY;
};