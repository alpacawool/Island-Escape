/***************************** Forest ********************************
** The Forest class is a child of the Space class. The special features
** of the forest are that you can chop wood and gather pineapples.
*********************************************************************/

#ifndef FOREST_HPP
#define FOREST_HPP

#include "Space.hpp"

class Forest : public Space
{
public:
	Forest(int spaceType);
	std::string getType();
	std::string getActionName();
	std::string getActionName2();
	void spaceDescript();
	// Forest Specific Functions
	GameItem* chopWood();
	GameItem* getPine();
};

#endif

