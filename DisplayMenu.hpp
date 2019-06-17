/************************** DisplayMenu *****************************
** The DisplayMenu class is a class focused on displaying
** the menu and moving the user to different portion of the program
** based on user input. The showMenu function takes a string input
** and retrieves the corresponding menu. It then asks for user input
** and validates it. Afterwards, it uses the menuMove function
** to go to varying parts of of the program based on user's choice.
*********************************************************************/

#ifndef DISPLAYMENU_HPP
#define DISPLAYMENU_HPP

#include "WorldGrid.hpp"

#include <string>
#include <fstream>
#include <iomanip> 

class DisplayMenu
{
private:
	std::string menuName;
	std::string userString; // String user input
	int userChoice; // Integer user input
	float userFloat; // Float user input
	bool keepMenu; // Determines whether to keep or exit out of menu

	// Island Escape Specific
	WorldGrid * islandGame;
	bool keepBag;
	bool isFood;

	int * foodArray;
	int foodArraySize;
	int * directArray;
	int directArraySize;

	// Validation functions
	void menuValid();
	int menuMove(int userNum);
	void showMenu(std::string myMenu);
	// Integer Validation
	std::string stringVerify(std::string & stringToCheck);
	int stringConvert(std::string & stringToConvert);
	int requestInput();
	void limitTest(int testerInt, int lowerLimit, int upperLimit); // Integer limit test
	void limitArrayTest(int testerInt, int * chosenNumbers, int arraySize);


	// Base Menus
	void startMenu();
	void userBack();
	void endMenu();

	// Island Escape Specific
	void introPrompt();
	void gameRules();
	void taskChoice();
	void walkMenu();
	void exitConfirm();
	void bagMenu();
	void endPrompt();

public:
	DisplayMenu();
	void presentMenu();
	~DisplayMenu();
};

#endif
