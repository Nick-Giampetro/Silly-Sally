#include "Menu.h"

Menu::Menu()
{
	//initializing the important features of the game
	choice = 0;
	quit = false;
	speedSetting = 1;
	wallSprite = '*';
	winScore = 36191; //the height that Sally flew to at Spaceport
}

Menu::~Menu()
{
}

void Menu::startup()
{
	//initializing the system color to sky blue
	system("color 3f");

	//placing the title in the center of the playing screen
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { frameSize / 4,frameSize / 4 };
	SetConsoleCursorPosition(hConsole, pos);
	
	//opening the game
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
			cout << "1. Play" << endl << "2. Game Options" << endl << "3. Graphics Options" << endl << "4. Tutorial" << endl << "5. Quit" << endl;

			// waits for player input, will loop and clear previous statements if input is not valid
			cin >> choice;
			if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice !=5)
			{
				system("cls");
				cout << "Plese select a valid option" << endl << endl;
			}

		} while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5);

		switch (choice) {
		case 1: //runs the game
			system("cls");
			run();
			system("cls");
			break;
		case 2: //enters the Game Options menu screen
			gameOptions();
			system("cls");
			
			break;
		case 3: //enters the Game Graphics menu screen
			graphicsMenu();
			system("cls");
			
		case 4: 
			system("cls");
			cout << "The objective of the game is to pass through the gaps with the rocket and to get as high as you can." << endl 
				<< "You win when the altitude surpasses 36191 ft and you travel at ~7 ft/s so...good luck. Use the spacebar to" << endl
				<< "change direction. You lose if you hit the wall or the obstacle. Difficulty settings just increase the speed" << endl
				<< "that sally moves at. The game breaks if you go above 4 because sally can noclip through the wall but we left" << endl
				<< "that option in for fun. Enjoy and try not to rage quit so hard, your computer breaks." << endl;
			Sleep(3000);
			system("pause");
			this->mainMenu();
		case 5: //just finish the program
			quit = true;
			break;

		}
	}

}

void Menu::gameOptions()
{
	system("cls");
	do {
		// waits for player input, will loop and clear previous statements if input is not valid
		cout << "Game Options:" << endl << "1. Difficulty" << endl << "2. Back" << endl;
		cin >> choice;

		if (choice != 1 && choice != 2)
		{
			system("cls");
			cout << "Plese select a valid option" << endl << endl;
		}

	} while (choice != 1 && choice != 2);
	
	

	switch (choice)
	{
	case 1: //player chooses the speed at which they want to play the game
		system("cls");

		cout << "1. Easy" << endl << "2. Medium" << endl << "3. Hard" << endl << "4. Silly" << endl << "Or enter at your own risk..." << endl;
		cin >> speedSetting;

		this->gameOptions();
		break;

	case 2: //takes the player back to the Main Menu
		this->mainMenu();
		break;
	}
}

void Menu::graphicsMenu()
{
	system("cls");

	do {
		// waits for player input, will loop and clear previous statements if input is not valid
		cout << "Graphics Options:" << endl << "1. Color" << endl << "2. Wall Sprite" << endl << "3. Back" << endl;
		cin >> choice;

		if (choice != 1 && choice != 2 && choice != 3)
		{
			system("cls");
			cout << "Plese select a valid option" << endl << endl;
		}

	} while (choice != 1 && choice != 2 && choice != 3);

	switch (choice) 
	{
	case 1: //player chooeses the color scheme to play with
		system("cls");

		do {
			// waits for player input, will loop and clear previous statements if input is not valid
			cout << "Please select a background color scheme:" << endl << "1. White" << endl << "2. Black" << endl << "3. Red"
				<< endl << "4. Pink" << endl << "5. Yellow" << endl << "6. Green" << endl << "7. Aqua" << endl << "8. Lavender" << endl;
			cin >> choice;

			if (choice < 1 || choice > 8)
			{
				system("cls");
				cout << "Plese select a valid option" << endl << endl;
			}

		} while (choice < 1 || choice > 8);

		//setting the appropriate color code to the chosen color
		enum color {white = 1, black, red, pink, yellow, green, aqua, purple};
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
			case aqua: system("color 3f");
				break;
			case purple: system("color 5f");
				break;
		}
		this->graphicsMenu();
		break;

	case 2: //player chooses any character to have displayed as their wall bounds
		system("cls");
		char c;

		cout << "Please choose any character to represent your wall: ";
		cin >> c;

		wallSprite = c;
		this->graphicsMenu();
		break;

	case 3: //takes the player back to the Main Menu
		this->mainMenu();
		break;
	}
}

void Menu::run()
{
	//starts the game with a score of zero and the default settings, unless altered by the player
	engine game(speedSetting,wallSprite);

	int score = 0;
	

	//output the frame
	game.frameOutput();

	while (game.getLifeStatus() && score < winScore)
	{
		game.playerInput();

		//step objects
		game.frameStepper();

		Sleep(1000/game.getFps());

		//updates frame image
		game.frameUpdate();

		//score counter
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
