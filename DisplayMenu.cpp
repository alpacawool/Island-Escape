/************************** DisplayMenu *****************************
** The DisplayMenu class is a class focused on displaying
** the menu and moving the user to different portion of the program
** based on user input. The showMenu function takes a string input
** and retrieves the corresponding menu. It then asks for user input
** and validates it. Afterwards, it uses the menuMove function
** to go to varying parts of of the program based on user's choice.
*********************************************************************/

#include "DisplayMenu.hpp"

#include <string>
#include <sstream>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;


// Constructor

DisplayMenu::DisplayMenu()
{
	menuName = " ";
	int userChoice = 0;
	int userFloat = 0.0;
	keepMenu = true;

	foodArray = NULL;
	directArray = NULL;

	foodArraySize = 0;
	directArraySize = 0;

	islandGame = new WorldGrid;
}

// The beginning menu that displays in a loop

void DisplayMenu::presentMenu()
{
	introPrompt();
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "             Island Escape           \n";
	cout << "**************************************\n";
	while (keepMenu == true)
	{
		showMenu("start");
	}
}

DisplayMenu::~DisplayMenu()
{
	if (islandGame != NULL)
	{
		delete islandGame;
		islandGame = NULL;
	}
}

// Displays the desired menu based on the string parameter.

void DisplayMenu::showMenu(string myMenu)
{
	menuName = myMenu;

	if (menuName == "start")
	{
		startMenu();
		menuValid();
		menuMove(userChoice);
	}
	else if (menuName == "back")
	{
		userBack();
		menuValid();
		menuMove(userChoice);
	}
	else if (menuName == "end")
	{
		endMenu();
		menuValid();
		menuMove(userChoice);
	}
	else if (menuName == "walk")
	{
		walkMenu();
		menuValid();
		menuMove(userChoice);
	}
	else if (menuName == "task")
	{
		taskChoice();
		menuValid();
		menuMove(userChoice);
	}
	else if (menuName == "exit")
	{
		exitConfirm();
		menuValid();
		menuMove(userChoice);
	}
	else if (menuName == "bag")
	{
		bagMenu();
		menuValid();
		menuMove(userChoice);
	}
	else
	{
		cout << "Invalid menu parameter";
	}
}

// Receives and validates input for menu choices
void DisplayMenu::menuValid()
{
	cout << "Please select the number of your choice:\n";
	requestInput();

	if (menuName == "start")
	{
		while (userChoice < 1 || userChoice > 2)
		{
			cout << "Choice must be between 1 through 2\n";
			cout << "Please re-enter your choice.\n";
			requestInput();
		}
	}
	else if (menuName == "back")
	{
		while (userChoice != 1)
		{
			cout << "Choice must be 1.\n";
			cout << "Please re-enter your choice.\n";
			requestInput();
		}
	}
	else if (menuName == "end")
	{
		while (userChoice < 1 || userChoice > 2)
		{
			cout << "Choice must be 1 or 2\n";
			cout << "Please re-enter your choice.\n";
			requestInput();
		}
	}
	else if (menuName == "bag")
	{
		while (userChoice < 1 || userChoice > 4)
		{
			cout << "Choice must be a valid number\n";
			cout << "Please re-enter your choice.\n";
			requestInput();
		}
	}
	else if (menuName == "walk")
	{
		islandGame->getValidWalk(directArray, directArraySize);
		limitArrayTest(userChoice, directArray, directArraySize);
	}
	else if (menuName == "task")
	{
		while (userChoice < 1 || userChoice > 5)
		{
			cout << "Choice must be a 1 through 5\n";
			cout << "Please re-enter your choice.\n";
			requestInput();
		}
	}
	else if (menuName == "exit")
	{
		while (userChoice < 1 || userChoice > 2)
		{
			cout << "Choice must be a 1 or 2\n";
			cout << "Please re-enter your choice.\n";
			requestInput();
		}
	}
}

/*
The stringVerify function takes a string and returns a referenced string.
This function checks if a string has anything that is not a numerical character. If it finds one, it converts the entire
string to "a", which is an invalid input. This will result in rejection of input in another function and prompt user for additional input.
Based on https://stackoverflow.com/questions/6605282/how-can-i-check-if-a-string-has-special-characters-in-c-effectively
*/

std::string DisplayMenu::stringVerify(string & stringToCheck)
{
	if (stringToCheck.find_first_not_of("1234567890") != string::npos)
	{
		stringToCheck = "a";
	}

	return stringToCheck;
}

/*
The stringConvert function takes a string input and returns its int counterpart.
Since the game and die deal with integer arithmetic, this is a necessary function.
Based on https://www.geeksforgeeks.org/converting-strings-numbers-cc/
*/

int DisplayMenu::stringConvert(std::string & stringToConvert)
{
	std::stringstream convertString(stringToConvert);
	convertString >> userChoice;
	return userChoice;
}

/*
The requestInput is a combined function design to reduce code repetition. It first requests
the user for input using getline. Then it checks the string for invalid characters. Then
it converts the string to an integer and returns the integer.
*/
int DisplayMenu::requestInput()
{
	getline(cin, userString);
	stringVerify(userString);
	while (userString == "a")
	{
		cout << "This input is not a correctly entered number.\n";
		cout << "Please re-enter your choice.\n";
		requestInput();
	}
	stringConvert(userString);
	return userChoice;
}

/*
The limitTest function takes 3 integers and allows defineable upper and lower limits
for inputs. If the integer tested is outside these limits, it prompts the user for
additional input.
*/
void DisplayMenu::limitTest(int testerInt, int lowerLimit, int upperLimit)
{
	while (testerInt < lowerLimit || testerInt > upperLimit)
	{
		cout << "Please enter a number between " << lowerLimit << " and " << upperLimit << ":" << endl;
		requestInput();
		testerInt = userChoice;
	}
}

/*
The limitArrayTest has 3 parameters: 2 integers and a pointer integer. It 
takes an array and determines these are the valid choices. It checks the testerInt and
see if these match any of the numbers of the array. If not, it tells the user which
numbers they can enter.
*/
void DisplayMenu::limitArrayTest(int testerInt, int * chosenNumbers, int arraySize)
{
	int userMatch = false;

	while (!userMatch)
	{
		for (int i = 0; i < arraySize; i++)
		{
			if (chosenNumbers[i] == testerInt)
			{
				userMatch = true;
			}
		}
		if (userMatch == false)
		{
			cout << "Please enter any of the following numbers:\n";
			cout << " ~ ";
			for (int i = 0; i < arraySize; i++)
			{
				cout << chosenNumbers[i] << " ~ ";
			}
			cout << "\nPlease re-enter your choice:\n";
			requestInput();
			testerInt = userChoice;
		}
	}

	// Removes the dynamic array
	delete[] chosenNumbers;
	chosenNumbers = NULL;
}

// Moves and activates menu choices. Takes an integer parameter and returns an integer.
int DisplayMenu::menuMove(int userNum)
{
	if (menuName == "start")
	{
		if (userChoice == 1)  // Start
		{
			gameRules();
			cout << "(Press 1 to continue)\n";
			requestInput();
			limitTest(userChoice, 1, 1);
			while (keepMenu)
			{ 
				while (islandGame->getPlayerHealth() > 0 && !islandGame->getCompleteGame()
					&& keepMenu)
				{
					islandGame->printLocation();
					showMenu("task");
				}

				if (keepMenu)
				{ 
					if (islandGame->getPlayerHealth() <= 0)
					{
						cout << "You have died.\n";
					}
					else if (islandGame->getCompleteGame())
					{
						cout << "You have completed the game!\n";
						endPrompt();
					}
					cout << "Would you like to play again?\n";
					endMenu();
					requestInput();
					limitTest(userChoice, 1, 2);
					if (userChoice == 1)
					{
						delete islandGame;
						islandGame = NULL;
					
						islandGame = new WorldGrid;
					}
					else
					{
						keepMenu = false;
					}
				}
			}
		}
		else if (userChoice == 2) // Exit
		{
			keepMenu = false;
			return 0;
		}
	}
	else if (menuName == "back")
	{
		if (userChoice == 1)
		{
			return 0;

		}
	}
	else if (menuName == "end")
	{
		if (userChoice == 1)
		{
			return 0;
		}
		else if (userChoice == 2)
		{
			keepMenu = false;
			return 0;
		}
	}
	else if (menuName == "walk")
	{
		if (userChoice == 1)
		{
		islandGame->walkGrid(1);
		}
		else if (userChoice == 2)
		{
		islandGame->walkGrid(2);
		}
		else if (userChoice == 3)
		{
		islandGame->walkGrid(3);
		}
		else if (userChoice == 4)
		{
		islandGame->walkGrid(4);
		}
	}
	else if (menuName == "task")
	{
		if (userChoice == 1) // Special Action 1
		{
			islandGame->specialAction();
			showMenu("back");
		}
		else if (userChoice == 2) // Special Action 2
		{
			islandGame->specialAction2();
			if(islandGame->getCurrentSpace()->getSpaceNo() != 2)
			{ 
				showMenu("back");
			}
		}
		else if (userChoice == 3) // Walk
		{
			showMenu("walk");
		}
		else if (userChoice == 4) // Backpack
		{
			keepBag = true;
			
			while (keepBag)
			{
				showMenu("bag");
			}
		}
		else if (userChoice == 5) // Exit
		{
			showMenu("exit");
		}
	}
	else if (menuName == "bag")
	{
		if (userChoice == 1)
		{
			islandGame->viewAllItems();
		}
		else if (userChoice == 2)
		{
			if (islandGame->isThereFood())
			{ 

				cout << "What would you like to eat or drink?\n";
				islandGame->viewFood();
				islandGame->getFoodArray(foodArray, foodArraySize);
				requestInput();
				limitArrayTest(userChoice, foodArray, foodArraySize);
				islandGame->eatSomething(userChoice);
			}
			else
			{
				cout << "You have no food to eat.\n";
			}
		}
		else if (userChoice == 3)
		{
			if (!islandGame->areThereItems())
			{
				cout << "Pick an item to throw away:\n";
			islandGame->viewAllItems();
				requestInput();
				limitTest(userChoice, 1, islandGame->getBackPackSize());
			islandGame->removeItem(userChoice);
			}
			else
			{
				cout << "You have no items, so you cannot throw anything away\n";
			}
		}
		else if (userChoice == 4)
		{
			keepBag = false;
		}
	}
	else if (menuName == "exit")
	{
		if (userChoice == 1)
		{
			keepMenu = false;
		}
	}
	else
	{
		return 0;
	}
	return 0;
}



/*********************************************************
** Final Project Menu Displays
**********************************************************/

// The menu the user sees in the beginning 

void DisplayMenu::startMenu()
{
	cout << "1. Play\n";
	cout << "2. Exit\n";
}

// Prompt text for user to go back 

void DisplayMenu::userBack()
{
	cout << "----------------------" << endl;
	cout << "1. Back\n";
}

// Menu shown at the end (optional)

void DisplayMenu::endMenu()
{
	cout << "1. Play again\n";
	cout << "2. Exit\n";
}

/*
** Intro that plays in the beginning
** Text / wording of invite based on Fyre Festival invite 
** https://www.designboom.com/design/how-design-catapulted-fyre-festival-interview-with-oren-aks-02-08-2019/
*/
void DisplayMenu::introPrompt()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << " YOU ARE                \n";
	cout << " INVITED                \n";
	cout << "\n";
	cout << " ESCAPE WHAT YOU KNOW..\n";
	cout << " DISCOVER THE UNKNOWN..\n";
	cout << "\n";
	cout << " FIRE FESTIVAL\n";
	cout << " GREAT EXUMA BAHAMAS\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "\n";
	cout << "\"Sounds great, let's go!\"\n";
	cout << "(Press 1 to continue)\n";
	requestInput();
	limitTest(userChoice, 1, 1);
	cout << "==================================\n";
	cout << "FINAL BOARDING CALL FOR FLIGHT 171\n";
	cout << "==================================\n";
	cout << "The skies are bright.\n";
	cout << "Not a cloud in sight.\n";
	cout << "(Press 1 to continue)\n";
	requestInput();
	limitTest(userChoice, 1, 1);
	cout << "---------------------\n";
	cout << "The sun is glaring.\n";
	cout << "Your head kind of hurts.\n";
	cout << "\"Where am I?\"\n";
	cout << "\"Where is everybody?\"\n";
	cout << "\"This is not Fire Festival. :(\"\n";
	cout << "(Press 1 to continue)\n";
	requestInput();
	limitTest(userChoice, 1, 1);
}

// Prints rules of the game
void DisplayMenu::gameRules()
{
	cout << "------ RULES ------\n";
	cout << "GOAL: Escape the Island\n";
	cout << "HEALTH: Declines by 10 each space you move\n";
	cout << "RECOVERY: Can recover health by using items\n";
	cout << "------- x -------\n";
}

// Shows possible task choices for each space
void DisplayMenu::taskChoice()
{
	cout << "What would you like to do?\n";
	cout << "1. " << islandGame->getCurrentSpace()->getActionName() << "\n";
	cout << "2. " << islandGame->getCurrentSpace()->getActionName2() << "\n";
	cout << "3. Walk to a different area\n";
	cout << "4. Look inside backpack\n";
	cout << "5. Exit\n";
}

// Walk Menu

void DisplayMenu::walkMenu()
{
	if (islandGame->getCurrentSpace()->getSpacePtr(1))
	{
		cout << "1. Up [" << islandGame->getCurrentSpace()->getSpacePtr(1)->getType() << "]\n";
	}
	if (islandGame->getCurrentSpace()->getSpacePtr(2))
	{
		cout << "2. Right [" << islandGame->getCurrentSpace()->getSpacePtr(2)->getType() << "]\n";
	}
	if (islandGame->getCurrentSpace()->getSpacePtr(3))
	{
		cout << "3. Left [" << islandGame->getCurrentSpace()->getSpacePtr(3)->getType() << "]\n";
	}
	if (islandGame->getCurrentSpace()->getSpacePtr(4))
	{
		cout << "4. Down [" << islandGame->getCurrentSpace()->getSpacePtr(4)->getType() << "]\n";
	}

}

// Asks if the player wants to actually exit (prevents accidental quit)
void DisplayMenu::exitConfirm()
{
	cout << "Are you sure you would like to exit?\n";
	cout << "1. Yes\n";
	cout << "2. No\n";
}

// Backpack menu
void DisplayMenu::bagMenu()
{
	cout << "1. View all items\n";
	cout << "2. Eat something\n";
	cout << "3. Throw away item\n";
	cout << "4. Back\n";
}
// Shown if won and completed game
void DisplayMenu::endPrompt()
{
	cout << "-----------------\n";
	cout << "6 MONTHS LATER\n";
	cout << "DENVER, COLORADO\n\n";
	cout << "You have received a letter!\n";
	cout << "\n";
	cout << "~~~~~~~~~~~~~~~~~~~\n";
	cout << "It's Turtle.\n";
	cout << "I want to thank you again\n";
	cout << "for your hard efforts\n";
	cout << "Wishing you happy holidays\n";
	cout << "&& a Happy New Year <3\n";
	cout << "~~~~~~~~~~~~~~~~~~~\n";
	cout << "\n";
	cout << "You turn to show the letter to your red parakeet,\n";
	cout << "But the letter turns into a credit card offer.\n";
	cout << "\n";
	cout << "THE END.\n";
}




