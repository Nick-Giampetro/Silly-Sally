#include "engine.h"


//sets starting entities
engine::engine() {
	player.setPos(frameSize / 2, frameSize - frameSize / 20);
	
	Wall temp1(0,0);
	Wall temp2(frameSize,0);
	bounds.push_back(temp1);
	bounds.push_back(temp2);
}

void engine::frameStepper() {

}