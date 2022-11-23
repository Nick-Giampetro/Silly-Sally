#include "engine.h"


//sets starting entities
engine::engine() {

	player.setPos(frameSize / 2, frameSize - frameSize / 20);

	Wall temp1(0,0);
	Wall temp2(frameSize,0);
	bounds.push_back(temp1);
	bounds.push_back(temp2);

	Terrain temp;
	obstacles.push_back(temp);


	// need to figure out the terrain stuff still
	// obstacles.push_back()

}


void engine::frameGen() {
	for (int i = 0; i < frameSize; i++)
		for (int j = 0; j < frameSize; j++) {
			frameImg[i][j] = bounds[0].getSprite(i, j);
			frameImg[i][j] = bounds[1].getSprite(i, j);
			for (int k = 0; k < obstacles.size(); k++)
				frameImg[i][j] = obstacles[k].getSprite(i, j);
			if (frameImg[i][j] == ' ')
				frameImg[i][j] = player.getSprite(i, j);
			else {
				isAlive = false;
				return;
			}
		}

}

void engine::frameStepper() {
	frameStep++;
}