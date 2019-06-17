/***************************** Space ********************************
** The Space class represents areas within the island in the
** game. It is an abstract class with virtual functions where the top,
** right, left, and bottom pointers can be changed. This can be
** visualized as a physical grid.
*********************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <stdlib.h>  // NULL
#include <string>
#include <iostream>

#include "GamePlayer.hpp"
#include "GameItem.hpp"

class Space
{
protected:
	Space * top;
	Space * right;
	Space * left;
	Space * bottom;

	int spaceNo;
public:
	// Constructor
	Space();

	virtual void spaceDescript();
	// Setters
	void setTop(Space * topType);
	void setRight(Space * rightType);
	void setLeft(Space * leftType);
	void setBottom(Space * bottomType);
	// Getters
	virtual std::string getType() = 0;
	Space* getSpacePtr(int directionNo);
	virtual std::string getActionName() = 0;
	virtual std::string getActionName2() = 0;
	int getSpaceNo();
};

#endif
