#include "Menu.h"

Menu::Menu()
{
	choice = 0;
	quit = false;
	speedSetting = 1;
	wallSprite = '*';
}

Menu::~Menu()
{
}

void Menu::startup()
{
	system("color 3f");

	cout << "Wellcome to Silly Sally!" << endl;
	Sleep(2000);
	system("cls");
	mainMenu();
}

void Menu::mainMenu()
{
	while(!quit)
	{
		do {

			cout << "Silly Sally game menu:" << endl;
			cout << "1.Play" << endl << "2. Game Options" << endl << "3. Graphics Options" << endl << "4. Quit" << endl;

			// waits for player input
			cin >> choice;
			if (choice != 1 && choice != 2 && choice != 3 && choice != 4)
			{
				cout << "Plese select a valid option" << endl;
				system("cls");
			}

		} while (choice != 1 && choice != 2 && choice != 3 && choice != 4);

		switch (choice) {
		case 1:
			run();
			system("cls");
			break;
		case 2:
			gameOptions();
			system("cls");
			
			break;
		case 3:
			graphicsMenu();
			system("cls");
			
		case 4://just finish the program
			quit = true;
			break;

		}
	}

}

void Menu::gameOptions()
{
	system("cls");
	cout << "Game Options:" << endl << "1. Difficulty" << endl << "2. Back" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		cin >> speedSetting;
		this->gameOptions();
		break;
	case 2:
		this->mainMenu();
		break;



	}

	
}

void Menu::graphicsMenu()
{
	system("cls");
	cout << "Graphics Options:" << endl << "1. color" << endl<<"2. wall sprite"<<endl<<"3. obsticle sprite"<<endl;
	cin >> choice;
	switch (choice) 
	{
	case 1:
		system("cls");
	}
}

void Menu::run()
{
	engine game(speedSetting,wallSprite);

	int counter = 0;
	//system("pause");

	

	//output the frame
	game.frameOutput();

	while (game.getLifeStatus())
	{
		//system("cls");

		game.playerInput();

		//step objects
		game.frameStepper();

		Sleep(100);

		//u[dates frame image
		game.frameUpdate();

		counter++;
	}

	cout << counter << endl;
}
