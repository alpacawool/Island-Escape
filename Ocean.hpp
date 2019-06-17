/***************************** Ocean ********************************
** The Ocean class is a child of the Space class. The special features
** of the ocean are you can go fishing or leave the island (complete game)
*********************************************************************/

#ifndef OCEAN_HPP
#define OCEAN_HPP

#include "Space.hpp"

class Ocean : public Space
{
public:
	Ocean(int spaceType);
	std::string getType();
	std::string getActionName();
	std::string getActionName2();
	void spaceDescript();
	// Ocean Specific Functions
	GameItem * goFish();
};

#endif

