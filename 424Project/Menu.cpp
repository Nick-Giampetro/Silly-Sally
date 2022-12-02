#include "Menu.h"

Menu::Menu()
{
	choice = 0;
	quit = false;
}

Menu::~Menu()
{
}

void Menu::startup(engine &g)
{
	cout << "Wellcome to Silly Sally!" << endl;
	Sleep(2000);
	system("cls");
	mainMenu(g);
}

void Menu::mainMenu(engine &g)
{
	while(!quit)
	{
		while (choice != 1 && choice != 2 && choice != 3 && choice != 4) {

			cout << "Silly Sally game menu:" << endl;
			cout << "1.Play" << endl << "2. Game Options" << endl << "3. Graphics Options" << endl << "4. Quit" << endl;


			cin >> choice;
			if (choice != 1 && choice != 2 && choice != 3 && choice != 4)
			{
				cout << "Plese select a valid option" << endl;
				system("cls");
			}
		}
		switch (choice) {
		case 1:
			//call run function
			system("cls");
			choice = 0;
			break;
		case 2:
			gameOptions(g);
			system("cls");
			choice = 0;
			break;
		case 3:
			graphicsMenu(g);
			system("cls");
			choice = 0;
		case 4://just finish the program
			quit = true;
			break;

		}
	}

}

void Menu::gameOptions(engine &g)
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

void Menu::graphicsMenu(engine &g)
{
	system("cls");
	cout << "Graphics Options:" << endl << "1. color" << endl<<"2. wall sprite"<<endl<<"3. obsticle sprite"<<endl;
	cin >> choice;
	switch (choice) 
	{

	}
}

void Menu::run(engine&)
{
}
