#include "engine.h"


//sets starting entities
engine::engine() {
	
	for (int i = 0; i < frameSize; i++)
		for (int j = 0; j < frameSize; j++)
			frameImg[i][j] = ' ';

	player.setPos(frameSize / 2, frameSize - frameSize / 20);

	Wall temp1(0,0);
	Wall temp2(frameSize,0);
	bounds.push_back(temp1);
	bounds.push_back(temp2);

	// need to figure out the terrain stuff still
	// obstacles.push_back()

}

void engine::frameGen() {

}

void engine::frameStepper() {

}