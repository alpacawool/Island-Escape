#ifndef RIVER_HPP
#define RIVER_HPP
/***************************** River ********************************
** The River class is a child of the Space class. The special features
** of the river are that you can get a drink from the river and
** do the quest from a Turtle.
*********************************************************************/
#include "Space.hpp"

class River : public Space
{
private:
	bool questCompleted;
	bool questInProgress;
public:
	River(int spaceType);
	std::string getType();
	std::string getActionName();
	std::string getActionName2();
	void spaceDescript();
	// River Specific Functions
	GameItem* getDrink();
	void talkTurtle();
	bool getQuestInProgress();
	void setQuestCompleted(bool userSet);
	void setQuestInProgress(bool userSetProg);
};

#endif
