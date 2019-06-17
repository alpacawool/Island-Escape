/***************************** Plains ********************************
** The Plains class is a child of the Space class. The special features
** of the plains are you can hunt chickens or gather feathers.
*********************************************************************/

#ifndef PLAINS_HPP
#define PLAINS_HPP

#include "Space.hpp"

class Plains : public Space
{
public:
	Plains(int spaceType);
	std::string getType();
	std::string getActionName();
	std::string getActionName2();
	void spaceDescript();
	// Plains Specific Functions
	GameItem * huntChickens();
	GameItem * featherChick();
};

#endif