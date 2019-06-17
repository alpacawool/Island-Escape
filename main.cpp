/*********************************************************************
** Program name: Final Project - ISLAND ESCAPE
** Date: June 5, 2019
** Description: This final project has an island theme. Each space
** represents a different part of the island. The goal of the game
** is to leave(escape) the deserted island. The player has to complete
** a quest and build an item that will them escape the island.
*********************************************************************/

#include "DisplayMenu.hpp"

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	DisplayMenu gameMenu;
	gameMenu.presentMenu(); // show Menu loop

	return 0;
}
