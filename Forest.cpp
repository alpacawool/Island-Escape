/***************************** Forest ********************************
** The Forest class is a child of the Space class. The special features
** of the forest are that you can chop wood and gather pineapples.
*********************************************************************/
#include "Forest.hpp"

/*
** Parameters: integer of spaceNo the object will have when
** initialized in the constructor.
*/
Forest::Forest(int spaceType)
{
	spaceNo = spaceType;

	top = NULL;
	right = NULL;
	left = NULL;
	bottom = NULL;
}
// Returns area name string
std::string Forest::getType()
{
	return "Forest";
}
// Returns special action 1 string
std::string Forest::getActionName()
{
	return "Chop trees";
}
// Returns special action 2 string
std::string Forest::getActionName2()
{
	return "Gather pineapples";
}
// Describes the space the user is in
void Forest::spaceDescript()
{
	std::cout << "The forest is dense and dark\n";
	std::cout << "You solve this problem quickly by\n";
	std::cout << "Climbing up the tree and swinging Tarzan style.\n";
}
// Returns a GameItem pointer of a new Wood object
GameItem * Forest::chopWood()
{
	std::cout << "Bang! You have obtained 1 Wood.\n";
	GameItem * treeWood = new GameItem("Wood", 0, false);
	return treeWood;
}
// Returns a GameItem pointer of a new Pinapple object
GameItem * Forest::getPine()
{
	std::cout << "You have gathered 1 Pineapple.\n";
	GameItem * pineApple= new GameItem("Pineapple", 8, true);
	return pineApple;
}

