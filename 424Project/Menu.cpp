#include "Menu.h"

Menu::Menu()
{
	choice = 0;
	quit = false;
}

Menu::~Menu()
{
}

void Menu::startup()
{
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
			choice = 0;
			break;
		case 3:
			graphicsMenu();
			system("cls");
			choice = 0;
		case 4://just finish the program
			quit = true;
			break;

		}
	}

}

void Menu::gameOptions()
{
	system("cls");
	cout << "Game Options:" << endl << "1. Difficulty" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
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

	}
}

void Menu::run()
{

}
