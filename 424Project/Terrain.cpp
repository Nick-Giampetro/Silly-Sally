#include "Terrain.h"
#include "engine.h"

Terrain::Terrain() {

	//itial hole spawn at hole number 3 (the middle of the screen) with line type 1
	holeType = 3;
	lineType = 1;
}

Terrain::Terrain(int prevHole) {

	//random number generator to randomly choose a new hole one position to the left or right or directly about the previous hole
	srand(time(0));
	holeType = prevHole + (rand() % 3 - 1);

	//assures that the new hole is a valid hole number (1-5)
	while (holeType < 1 || holeType > 5) {
		holeType = prevHole + (rand() % 3 - 1);
	}

}

Terrain::~Terrain() {
	;
}

void Terrain::defineShape() {

}

char Terrain::spriteData() {

	//defines the type of line that will print once the game is played for so long, starts at case 1
	switch (getLineType())
	{
	case 1: return '-';
		break;
	case 2: return '~';
		break;
	case 3: return '=';
		break;
	case 4: return '#';
		break;
	case 5: return '*';
		break;
	}

	return 0;
}

void Terrain::setSprite() {

	int j = 0;
	//frame size divided-by five (fsdf) and then multiplied by an integer
	auto fsdf = [](int a) -> int { return (frameSize / 5) * a; };

	//sets the line within the frame size
	for (int i = 0; i < frameSize; i++) {

		//sets the hole
		for (; j < (fsdf(1)) && i >= fsdf(getHoleType() - 1); j++, i++) {
			img[i] = ' ';
			cout << img[i];
			i++;
		}
		//accounts for the extra character that would appear after the hole if at hole number 5
		if (getHoleType() != 5 || i < fsdf(4)) {
			img[i] = spriteData();
			cout << img[i];
		}

	}
}

int Terrain::getLineType() {
	return lineType;
}

int Terrain::getHoleType() {
	return holeType;
}