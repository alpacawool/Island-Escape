/***************************** Plains ********************************
** The Plains class is a child of the Space class. The special features
** of the plains are you can hunt chickens or gather feathers.
*********************************************************************/
#include "Plains.hpp"

/*
** Parameters: integer of spaceNo the object will have when
** initialized in the constructor.
*/
Plains::Plains(int spaceType)
{
	spaceNo = spaceType;

	top = NULL;
	right = NULL;
	left = NULL;
	bottom = NULL;
}
// Returns area name string
std::string Plains::getType()
{
	return "Plains";
}
// Returns special action 1 string
std::string Plains::getActionName()
{
	return "Hunt for Chickens";
}
// Returns special action 2 string
std::string Plains::getActionName2()
{
	return "Gather chicken feathers";
}
// Describes the space the user is in
void Plains::spaceDescript()
{
	std::cout << "The plains are ahead of the beach with a river\n";
	std::cout << "flowing to the right. There appears to be a family of\n";
	std::cout << "Organic, free-range, gluten-free chickens.\n";
}
// Returns a GameItem pointer of Chicken Nugget object
GameItem * Plains::huntChickens()
{
	std::cout << "You hunted a chicken. You have gained 1 Chicken Nugget.\n";
	GameItem * chickenNugget = new GameItem("Chicken Nugget", 5, true);
	return chickenNugget;
}
// Returns a GameItem pointer of chicken feather object
GameItem * Plains::featherChick()
{
	std::cout << "You have gathered 1 Chicken Feather.\n";
	GameItem * chickenFeather = new GameItem("Chicken Feather", 0, false);
	return chickenFeather;
}

