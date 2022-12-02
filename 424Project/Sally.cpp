#include "Sally.h"

// constructor
Sally::Sally()
{
	cout << "Sally Lives!" << endl;

	this->setVel(0, 1);
	this->setSprite();
	this->defineShape();
	
}

// deconstructor
Sally::~Sally()
{
	cout << "We lost Sally!" << endl;
}

// goes through the the imgPos array to see if sally is located at the coordinates I,J passed to the function
bool Sally::isLocatedAt(int I, int J) {
	
	for (int i = 0; i < sallySizeI; i++)
		for (int j = 0; j < sallySizeJ; j++) {
			if (imgPos[i][j][0] == I && imgPos[i][j][1] == J)
				return true;
		}

	return false;
}

// creates the imgPos array to define where sally is located in the overall game X Y coordinates
void Sally::defineShape() {
	for (int i = 0; i < sallySizeI; i++)
		for (int j = 0; j < sallySizeJ; j++) {
			imgPos[i][j][0] = this->getPosX() + i;
			imgPos[i][j][1] = this->getPosY() + j;
		}
}

// returns the sprite of sally at a the passed global coordinates I,J
char Sally::spriteData(int I,int J) {
	for (int i = 0; i < sallySizeI; i++)
		for (int j = 0; j < sallySizeJ; j++) {
			if (imgPos[i][j][0] == I && imgPos[i][j][1] == J)
				return img[i][j];
		}
}

// initiallizes the img array to be the sally sprite
void Sally::setSprite() {
	for (int i = 0; i < sallySizeI; i++)
		for (int j = 0; j < sallySizeJ; j++)
			img[i][j] = ' ';

	img[0][1] = '/'; img[0][2] = '\\';
	img[1][1] = '|'; img[1][2] = '|';
	img[2][1] = '|'; img[2][2] = '|';
	img[3][0] = '<'; img[3][1] = '|'; img[3][2] = '|'; img[3][3] = '>';
	img[4][1] = '^'; img[4][2] = '^';
}

