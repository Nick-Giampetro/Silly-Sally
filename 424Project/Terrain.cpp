#include "Terrain.h"
#include <iostream>

Terrain::Terrain() {

	//initial hole spawn at hole number 3 (the middle of the screen) with line type of -
	holeType = getHoleType();
	lineType = getLineType();
	terrainSpeed = 1;
	this->setPos(0, 0);
	this->setVel(1, 0);

	//initalize array of 0 so IDE is happy
	this->setSprite();
	this->defineShape();
}

Terrain::Terrain(int prevType) {

	//current speed, line type, position, and speed
	terrainSpeed = 1;
	lineType = getLineType();
	this->setPos(0, 0);
	this->setVel(1, 0);

	//random number generator to randomly choose a new hole one position to the left or right or directly about the previous hole
	srand(time(0));
	holeType = prevType + (rand() % 3 - 1);
	

	//assures that the new hole is a valid hole number (1-5)
	while (holeType < 1 || holeType > 5) {
		holeType = prevType + (rand() % 3 - 1);
	}
	//outputs the terrain obstacle properly
	this->setSprite();
	this->defineShape();
}

Terrain::~Terrain() {}

//goes through the the imgPos array to see if the terrain is located at the coordinates I,J passed to the function
bool Terrain::isLocatedAt(int I, int J) {

	for (int j = 0; j < frameSize; j++) {
		if (imgPos[j][0] == I && imgPos[j][1] == J)
			return true;
	}

	return false;
}

//creates the imgPos array to define where the terrain is located in the overall game X Y coordinates
void Terrain::defineShape() {

	for (int j = 0; j < frameSize; j++)
	{
		imgPos[j][0] = this->getPosX() ;
		imgPos[j][1] = this->getPosY() + j ;
	}
}

//returns the character of the terrain at a the passed global coordinates I,J
char Terrain::spriteData(int I, int J) {
	
	for (int j = 0; j < frameSize; j++) {
		if (imgPos[j][0] == I && imgPos[j][1] == J)
			return img[j];
	}
}

void Terrain::setSprite() {

	//frame size divided-by five (fsdf) and then multiplied by an integer
	auto fsdf = [](int a) -> int { return (frameSize / 5) * a; };

	int j = 0;

	//sets the line within the frame size
	for (int i = 0; i < frameSize; i++) {

		//sets the hole
		for (; j < (fsdf(1)) && i >= fsdf(getHoleType() - 1); j++, i++) {
			img[i] = ' ';
			
		}
		//accounts for the extra character that would appear after the hole if at hole number 5
		if (getHoleType() != 5 || i < fsdf(4)) {
			img[i] = getLineType();
		}

	}
}

int Terrain::getLineType() {
	return lineType;
}

void Terrain::setLineType(char l) {
	lineType = l;
}

int Terrain::getHoleType() {
	return holeType;
}