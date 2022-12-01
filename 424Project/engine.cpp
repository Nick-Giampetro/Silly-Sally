#include "engine.h"
#include <Windows.h>


//sets starting entities
engine::engine() {

	// initializing variables
	frameStep = 0;
	fps = 10;
	isAlive = true;
	
	for (int i = 0; i < frameSize; i++)
		for (int j = 0; j < frameSize; j++)
			frameImg[i][j] = ' ';

	// initiallizing player
	player.setPos(frameSize - frameSize / 5, frameSize / 2);

	// initializing walls
	Wall temp1(0,0);
	Wall temp2(frameSize-1, 0);
	bounds.push_back(temp1);
	bounds.push_back(temp2);

	// test code
	tBound.setPos(1, 0);

	// initiallizing first obstacle
	Terrain temp;
	obstacles.push_back(temp);
}


void engine::frameGen() {

	// loop which fills in the frame with relevant frame info
	for (int i = 0; i < frameSize; i++)
		for (int j = 0; j < frameSize; j++) {
			// filling in the walls on the outside
			frameImg[i][j] = bounds[0].getSprite(i, j, frameImg[i][j]);
			frameImg[i][j] = bounds[1].getSprite(i, j, frameImg[i][j]);
			//frameImg[i][j] = tBound.getSprite(i, j, frameImg[i][j]);
			// filling in the terrain
			//for (int k = 0; k < obstacles.size() - 1; k++)
				//frameImg[i][j] = obstacles[k].getSprite(i, j);
			
			// filling in the player, if the space is not a space, function ends and isAlive turns false
			//if (frameImg[i][j] == ' ')
				frameImg[i][j] = player.getSprite(i, j, frameImg[i][j]);
			//else {
			//	isAlive = false;
			//	return;
			//}
		}

}

void engine::frameStepper() {
	
	frameStep++;
	double frameTime = static_cast<double>(frameStep) / fps;
	int terrainTime = 2;

	double tStep = 1.0 / fps;


	player.setPos(player.getPosX() + player.getVelX() * tStep, player.getPosY() + player.getVelY() * tStep);

	for (int k = 0; k < obstacles.size(); k++)
		(obstacles[k]).setPos((obstacles[k]).getPosX() + (obstacles[k]).getVelX() * tStep, (obstacles[k]).getPosY() + (obstacles[k]).getVelY() * tStep);
	
	if ((obstacles[0]).getPosY() > frameSize)
		obstacles.erase(obstacles.begin());


	if ((frameStep % terrainTime*fps) == 0) {
		Terrain temp(obstacles[obstacles.size()].getHoleType());
		obstacles.push_back(temp);
	}


}

void engine::frameOutput() {

	for (int i = 0; i < frameSize; i++) {
		for (int j = 0; j < frameSize; j++) {
			cout << frameImg[i][j];
		}
		cout << endl;
	}
}

bool engine::getLifeStatus() {
	return isAlive;
}

void engine::playerInput() {

    if (GetAsyncKeyState(VK_LEFT))
    {
		if (player.getPosX() != 0 && player.getPosX() != frameSize)
        {
			player.setPos(player.getPosX() - 1, player.getPosY());
        }
    }
    else if (GetAsyncKeyState(VK_RIGHT))
    {
		if (player.getPosX() != 0 && player.getPosX() != frameSize)
        {
            
			player.setPos(player.getPosX() + 1, player.getPosY());
        }
    }
}