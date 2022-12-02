#include "engine.h"


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
	Wall temp1(0,0, '*');
	Wall temp2(0 , frameSize - 1,'*');
	bounds.push_back(temp1);
	bounds.push_back(temp2);


	// initiallizing first obstacle
	Terrain temp;
	obstacles.push_back(temp);
}

engine::engine(int s, char w) {
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
	Wall temp1(0, 0, w);
	Wall temp2(0, frameSize - 1, w);
	bounds.push_back(temp1);
	bounds.push_back(temp2);


	// initiallizing first obstacle
	Terrain temp;
	obstacles.push_back(temp);

	//set sally speed
	player.setVel(0, s);

}


void engine::frameGen() {

	// clears array for next frame
	for (int i = 0; i < frameSize; i++)
		for (int j = 0; j < frameSize; j++)
			frameImg[i][j] = ' ';
	
	// loop which fills in the frame with relevant frame info
	for (int i = 0; i < frameSize; i++)
		for (int j = 0; j < frameSize; j++) {
			// filling in the walls on the outside
			frameImg[i][j] = bounds[0].getSprite(i, j, frameImg[i][j]);
			frameImg[i][j] = bounds[1].getSprite(i, j, frameImg[i][j]);
			// filling in the terrain
			for (int k = 0; k < obstacles.size(); k++) 
				frameImg[i][j] = obstacles[k].getSprite(i, j, frameImg[i][j]);
			
			// filling in the player, if the space is not a space, function ends and isAlive turns false
			if (frameImg[i][j] != ' ' && player.isLocatedAt(i,j))
				isAlive = false;
			else
				frameImg[i][j] = player.getSprite(i, j, frameImg[i][j]);
		}

}

void engine::frameStepper() {
	
	frameStep++;
	double frameTime = static_cast<double>(frameStep) / fps;
	int terrainTime = 2;

	double tStep = 1.0 / fps;


	player.setPos(player.getPosX() + player.getVelX() , player.getPosY() + player.getVelY() );

	for (int k = 0; k < obstacles.size(); k++)
		(obstacles[k]).setPos((obstacles[k]).getPosX() + obstacles[k].getVelX() , (obstacles[k]).getPosY() + obstacles[k].getVelY());
	
	if ((obstacles[0]).getPosY() > frameSize)
		obstacles.erase(obstacles.begin());


	if (frameStep % (terrainTime * fps) == 0) {
		Terrain temp(obstacles[obstacles.size()-1].getHoleType());
		obstacles.push_back(temp);
	}


}

void engine::frameOutput() {

	// generates the current inital frame
	this->frameGen();

	// outputs the inital frame to console
	for (int i = 0; i < frameSize; i++) {
		for (int j = 0; j < frameSize; j++) {
			cout << frameImg[i][j];
		}
		cout << "\n";
	}

	// sets current frame data to previous frame data
	for (int i = 0; i < frameSize; i++) 
		for (int j = 0; j < frameSize; j++) 
			pFrameImg[i][j] = frameImg[i][j];

}

void engine::frameUpdate() {

	// generates the next frame
	this->frameGen();

	// compares prevous frame to current frame to only print changes
	for (int i = 0; i < frameSize; i++) 
		for (int j = 0; j < frameSize; j++) 
			// confirms that there is a change in frames
			if(pFrameImg[i][j] != frameImg[i][j]){
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);		// --------------------------------------------------------------------------------
				COORD pos = { j, i };									// These lines of code move the cursor to the part of the console that needs edited
				SetConsoleCursorPosition(hConsole, pos);				// --------------------------------------------------------------------------------
				cout << frameImg[i][j];
			}
			
	// updates previous frame
	for (int i = 0; i < frameSize; i++)
		for (int j = 0; j < frameSize; j++)
			pFrameImg[i][j] = frameImg[i][j];

}

// returns isAlive
bool engine::getLifeStatus() {
	return isAlive;
}

// checks for space bar input
void engine::playerInput() {

    if (GetAsyncKeyState(VK_SPACE))
    {
		player.setVel(player.getVelX() * -1, player.getVelY() * -1);	// changes velocity of sally when space bar is pressed
    }
}

// returns the fps value
int engine::getFps() {
	return fps;
}