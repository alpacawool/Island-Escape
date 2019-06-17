#include "Space.hpp"
/***************************** Space ********************************
** The Space class represents areas within the island in the
** game. It is an abstract class with virtual functions where the top,
** right, left, and bottom pointers can be changed. This can be
** visualized as a physical grid.
*********************************************************************/

// Constructor initializes pointers to NULL
Space::Space()
{
	spaceNo = 0;

	top = NULL;
	right = NULL;
	left = NULL;
	bottom = NULL;
}

// Describes the space the user is in
void Space::spaceDescript()
{
	std::cout << "This is a default space:\n";
}


// Setters and getters
void Space::setTop(Space * topType)
{
	top = topType;
}

void Space::setRight(Space * rightType)
{
	right = rightType;
}

void Space::setLeft(Space * leftType)
{
	left = leftType;
}

void Space::setBottom(Space * bottomType)
{
	bottom = bottomType;
}

std::string Space::getType()
{
	return "Default Space";
}

/*
** Parameters: int of direction number
** 1. = Top
** 2. = Right
** 3. = Left
** 4.  = Bottom
** Returns: space pointer of space that is in 
** that direction.
*/
Space * Space::getSpacePtr(int directionNo)
{
	switch(directionNo)
	{ 
		case 1:
			return top;
			break;
		case 2:
			return right;
			break;
		case 3:
			return left;
			break;
		case 4:
			return bottom;
			break;
		default:
			return NULL;
			break;
	}
}


int Space::getSpaceNo()
{
	return spaceNo;
}
