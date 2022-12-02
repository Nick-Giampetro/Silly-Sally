// 424Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 

#include"engine.h"
#include <iostream>

static const int frameSize = 100;

using namespace std;

void run(engine&);

void test(engine& g);

int main()
{
    
    engine game;

    //test(game);

    run(game);
   
}

void run(engine &g) {


    int counter = 0;
    //system("pause");

    while (g.getLifeStatus())
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

        Sleep(250);

        counter++;
    }

    cout << counter << endl ;

    system("pause");
    
}

void test(engine& g) {

    int count = 0;

    for (int i = 0; i < 50; i++) {

        cout << ++count << endl ;

        //make the frame
        g.frameGen();

        //output the frame
        g.frameOutput();

        //takes playerinput
        // g.playerInput();

        //make next frame
        g.frameStepper();

        cout << endl; 

    }

    system("pause");

}