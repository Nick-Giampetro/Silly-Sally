#include "Menu.h"

Menu::Menu()
{
	choice = 0;
	quit = false;
	speedSetting = 1;
	wallSprite = '*';
	winScore = 36191;
}

Menu::~Menu()
{
}

void Menu::startup()
{
	system("color 3f");

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { frameSize / 4,frameSize / 4 };
	SetConsoleCursorPosition(hConsole, pos);
	

	cout << "Wellcome to Silly Sally!" << endl;
	Sleep(2000);
	system("cls");
	mainMenu();
}

void Menu::mainMenu()
{
	while(!quit)
	{
		system("cls");
		do {
			

			cout << "(maximise window for best game experience.)" << endl;
			cout << "Silly Sally game menu:" << endl;
			cout << "1. Play" << endl << "2. Game Options" << endl << "3. Graphics Options" << endl << "4. Quit" << endl;

			// waits for player input
			cin >> choice;
			if (choice != 1 && choice != 2 && choice != 3 && choice != 4)
			{
				system("cls");
				cout << "Plese select a valid option" << endl;
			}

		} while (choice != 1 && choice != 2 && choice != 3 && choice != 4);

		switch (choice) {
		case 1:
			system("cls");
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
		system("cls");
		cout << "1. Easy" << endl << "2. Medium" << endl << "3. Hard" << endl << "4. Silly" << endl << "Or enter at your own risk..." << endl;
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

	cout << "Graphics Options:" << endl << "1. Color" << endl<<"2. Wall Sprite"<<endl<<"3. Back"<<endl;

	cin >> choice;
	switch (choice) 
	{
	case 1:
		system("cls");

		cout << "Please select a background color scheme:" <<endl<< "1. White" <<endl<< "2. Black" <<endl<< "3. Red"
			 <<endl<< "4. Pink" <<endl<< "5. Yellow" <<endl<< "6. Green" <<endl<< "7. Sky" <<endl<< "8. Lavender" <<endl;
		cin >> choice;

		while (choice < 1 || choice > 8) {
			cout << "Please enter a valid number" << endl;
			cin >> choice;
		}

		enum color {white = 1, black, red, pink, yellow, green, sky, purple};
		switch (choice) {
			case white: system("color f0");
				break;
			case black: system("color 0f");
				break;
			case red: system("color 4f");
				break;
			case pink: system("color c0");
				break;
			case yellow: system("color 60");
				break;
			case green: system("color 2f");
				break;
			case sky: system("color 9f");
				break;
			case purple: system("color 5f");
				break;
		}
		this->graphicsMenu();
		break;

	case 2:
		system("cls");
		char c;

		cout << "Please choose any character to represent your wall: ";
		cin >> c;

		while (c == ' ') {
			cout << "Please enter a valid character: ";
			cin >> c;
		}
		wallSprite = c;
		this->graphicsMenu();
		break;
	case 3:
		this->mainMenu();
		break;
	}
}

void Menu::run()
{
	engine game(speedSetting,wallSprite);

	int score = 0;
	

	//output the frame
	game.frameOutput();

	while (game.getLifeStatus() && score < winScore)
	{
		//system("cls");

		game.playerInput();

		//step objects
		game.frameStepper();

		Sleep(1000/game.getFps());

		//updates frame image
		game.frameUpdate();

		score++;
	}
	
	//end game screen
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { frameSize / 3,frameSize / 2 };
	SetConsoleCursorPosition(hConsole, pos);
	
	cout << "Your score was: " << score << endl;

	pos = { frameSize / 4,frameSize / 2 + 1 };
	SetConsoleCursorPosition(hConsole, pos);

	if (score == winScore)
	{
		pos = { frameSize / 5,frameSize / 2 - 1 };
		SetConsoleCursorPosition(hConsole, pos);
		cout << "Congrats, you reached Sally's actual flight altitude in feet." << endl;
	}
	

	
		
	
	pos = { frameSize / 4,frameSize / 2 + 1 };
	SetConsoleCursorPosition(hConsole, pos);
	Sleep(2000);
	system("pause");
}
