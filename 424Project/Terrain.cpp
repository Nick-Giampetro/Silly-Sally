#include "Terrain.h"
#include "engine.h"

Terrain::Terrain() {

	//itial hole spawn at hole number 3 (the middle of the screen) with line type 1
	holeType = 3;
	lineType = 1;
	//initalize array of 0 so IDE is happy
	for (int j = 0; j < lineLength; j++)
	{
		imgPos[j][0] = 0;
		imgPos[j][1] = 0;
		img[j] = 0;
	}

	setPos(frameSize / 2, 0);
}

Terrain::Terrain(int prevHole) {

	//random number generator to randomly choose a new hole one position to the left or right or directly about the previous hole
	srand(time(0));
	holeType = prevHole + (rand() % 3 - 1);

	//assures that the new hole is a valid hole number (1-5)
	while (holeType < 1 || holeType > 5) {
		holeType = prevHole + (rand() % 3 - 1);
	}
	for (int j = 0; j < lineLength; j++)
	{
		imgPos[j][0] = 0;
		imgPos[j][1] = 0;
		img[j] = 0;
	}

}

Terrain::~Terrain() {
	;
}

bool Terrain::isLocatedAt(int I, int J) {

	
		for (int j = 0; j < lineLength; j++) {
			if (imgPos[j][0] == I && imgPos[j][1] == J)
				return true;
		}

	return false;
}

void Terrain::defineShape() {

		for (int j = 0; j < lineLength; j++) {
			imgPos[j][0] = this->getPosX() + j;
			imgPos[j][1] = this->getPosY();
		}
}

char Terrain::spriteData(int I, int J) {

	//defines the type of line that will print once the game is played for so long, starts at case 1
	

	for (int j = 0; j < lineLength; j++) {
		if (imgPos[j][0] == I && imgPos[j][1] == J)
			return img[j];
	}
}

void Terrain::setSprite() {

	int j = 0;
	//frame size divided-by five (fsdf) and then multiplied by an integer
	auto fsdf = [](int a) -> int { return (frameSize / 5) * a; };

	char temp;

	switch (lineType)
	{
	case 1: temp = '-';
		break;
	case 2: temp = '~';
		break;
	case 3: temp = '=';
		break;
	case 4: temp = '#';
		break;
	case 5:  temp = '*';
		break;
	}

	//sets the line within the frame size
	for (int i = 0; i < frameSize; i++) {

		//sets the hole
		for (; j < (fsdf(1)) && i >= fsdf(getHoleType() - 1); j++, i++) {
			img[i] = ' ';
			i++;
		}
		//accounts for the extra character that would appear after the hole if at hole number 5
		if (getHoleType() != 5 || i < fsdf(4)) {
			img[i] = temp;
		}

	}
}

int Terrain::getLineType() {
	return lineType;
}

int Terrain::getHoleType() {
	return holeType;
}