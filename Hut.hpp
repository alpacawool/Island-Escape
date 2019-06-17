/****************************** Hut *********************************
** The Hut class is a child of the Space class. The special features
** of the hut are you can sleep or read a book.
*********************************************************************/

#ifndef HUT_HPP
#define HUT_HPP

#include "Space.hpp"

class Hut : public Space
{
public:
	Hut(int spaceType);
	std::string getType();
	std::string getActionName();
	std::string getActionName2();
	void spaceDescript();
	// Hut Specific Functions
	int goSleep();
	void readBook();
};

#endif

