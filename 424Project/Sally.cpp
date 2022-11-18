#include "Sally.h"

Sally::Sally()
{
	cout << "Sally Lives!" << endl;

	this->setVel(1, 0);
	this->setSprite();
	

}

Sally::~Sally()
{
	cout << "We lost Sally!" << endl;
}



char Sally::spriteData(int,int) {
	return img[][];
}

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