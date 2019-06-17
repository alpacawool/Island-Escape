/****************************** Hut *********************************
** The Hut class is a child of the Space class. The special features
** of the hut are you can sleep or read a book.
*********************************************************************/
#include "Hut.hpp"

/*
** Parameters: integer of spaceNo the object will have when
** initialized in the constructor.
*/
Hut::Hut(int spaceType)
{
	spaceNo = spaceType;

	top = NULL;
	right = NULL;
	left = NULL;
	bottom = NULL;
}
// Returns area name string
std::string Hut::getType()
{
	return "Hut";
}
// Returns special action 1 string
std::string Hut::getActionName()
{
	return "Sleep in hut (Recovers 8 HP)";
}
// Returns special action 2 string
std::string Hut::getActionName2()
{
	return "Read [How to Escape Deserted Islands]";
}
// Describes the space the user is in
void Hut::spaceDescript()
{
	std::cout << "This hut has not been used in awhile.\n";
	std::cout << "You can tell. There are a lack of tourists\n";
	std::cout << "and no souvenir shop around the corner.\n";
}
// Returns: integer of recovery value player recovers while sleeping
int Hut::goSleep()
{
	std::cout << "You take a nap.\n";
	std::cout << "You have recovered 8 HP\n";
	return 8;
}
// Prints a page from the book
void Hut::readBook()
{
	std::cout << "There are missing pages but you manage to find a legible one.\n";
	std::cout << "Page 47.\n";
	std::cout << "= Taming the alligator =\n";
	std::cout << "  For most practical reasons, following an alligator is not\n";
	std::cout << "recommended but in the middle of nowhere you have to react.\n";
	std::cout << "Alligators are aggressive but they often have useful ideas that\n";
	std::cout << "you could use to navigate your way out of tricky situations.\n";
}
