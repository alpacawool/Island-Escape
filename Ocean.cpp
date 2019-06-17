/***************************** Ocean ********************************
** The Ocean class is a child of the Space class. The special features
** of the ocean are you can go fishing or leave the island (complete game)
*********************************************************************/

#include "Ocean.hpp"

/*
** Parameters: integer of spaceNo the object will have when
** initialized in the constructor.
*/
Ocean::Ocean(int spaceType)
{
	spaceNo = spaceType;

	top = NULL;
	right = NULL;
	left = NULL;
	bottom = NULL;
}
// Returns area name string
std::string Ocean::getType()
{
	return "Ocean";
}
// Returns special action 1 string
std::string Ocean::getActionName()
{
	return "Go Fishing";
}
// Returns special action 2 string
std::string Ocean::getActionName2()
{
	return "Leave island via raft";
}
// Describes the space the user is in
void Ocean::spaceDescript()
{
	std::cout << "You are waist-length in the ocean along the beach.\n";
	std::cout << "It looks like the fish are busy cooking something special.\n";
	std::cout << "Maybe you should ask the lead chef about their special.\n";
}
// Returns a GameItem pointer of Spicy Tuna Roll object
GameItem * Ocean::goFish()
{
	std::cout << "Always lucky! You have caught 1 Spicy Tuna Roll!\n";
	GameItem * tunaRoll = new GameItem("Spicy Tuna Roll", 5, true);
	return tunaRoll;
}

