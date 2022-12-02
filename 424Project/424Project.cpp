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

    system("color 3f");

    //output the frame
    g.frameOutput();

    while (g.getLifeStatus())
    {       
        //system("cls");
      
        g.playerInput();

        //step objects
        g.frameStepper();

        Sleep(100);
        
        //u[dates frame image
        g.frameUpdate();

        counter++;
    }

    cout << counter << endl ;
    
}

void test(engine& g) {

    int count = 0;

    system("color 3f");

    //output the frame
    g.frameOutput();

    for (int i = 0; i < 2; i++) {

       // cout << ++count << endl ;

        //system("cls");

        g.playerInput();

        //step objects
        g.frameStepper();

        Sleep(250);

        //u[dates frame image
        g.frameUpdate();

    }

    system("pause");

}