// 424Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 

#include"engine.h"
#include <iostream>

static const int frameSize = 100;

using namespace std;

void run(engine&);

int main()
{
    
    engine game;

    run(game);
   

    

}

void run(engine &g) {


    int counter = 0;

    while (g.getLifeStatus() || counter > 100)
    {       
        system("cls");

        //make the frame
        g.frameGen();

        //output the frame
        g.frameOutput();
       
        //takes playerinput
        g.playerInput();
       
        //make next frame
        g.frameStepper();

        counter++;
    }
    
}

