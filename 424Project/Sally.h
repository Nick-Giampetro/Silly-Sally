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

	// virtual functions
	bool isLocatedAt(int,int);
	void defineShape();
	void setSprite();
	char spriteData(int,int);

private:

	// sprite is in img and the position of each sprite element is in imgPos
	char img[sallySizeI][sallySizeJ];
	int imgPos[sallySizeI][sallySizeJ][2];

	
};

