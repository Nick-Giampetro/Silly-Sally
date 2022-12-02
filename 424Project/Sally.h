#pragma once

#include<iostream>
#include"Entity.h"
using namespace std;

class Sally : public Entity
{
	// the dimenstions of the sally sprite
	static const int sallySizeI = 5;
	static const int sallySizeJ = 4;

public:
	Sally();
	~Sally();

	// virtual functions from entity which need to be initialized
	bool isLocatedAt(int,int);		// returns true if sally is located at a coordinate
	void defineShape();				// defines the coordinates of each sprite cell location in sally
	void setSprite();				// creates the sally sprite
	char spriteData(int,int);		// returns the character of sally at a given location 

	

private:

	// sprite is in img and the position of each sprite element is in imgPos
	char img[sallySizeI][sallySizeJ];
	int imgPos[sallySizeI][sallySizeJ][2];

};

