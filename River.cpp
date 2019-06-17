/***************************** River ********************************
** The River class is a child of the Space class. The special features
** of the river are that you can get a drink from the river and
** do the quest from a Turtle.
*********************************************************************/

#include "River.hpp"
/*
** Parameters: integer of spaceNo the object will have when
** initialized in the constructor.
*/
River::River(int spaceType)
{
	spaceNo = spaceType;

	top = NULL;
	right = NULL;
	left = NULL;
	bottom = NULL;

	questCompleted = false;
	questInProgress = false;
}
// Returns area name string
std::string River::getType()
{
	return "River";
}
// Returns special action 1 string
std::string River::getActionName()
{
	return "Get drink from river";
}
// Returns special action 2 string
std::string River::getActionName2()
{
	if (!questCompleted && !questInProgress)
	{ 
		return "[Quest] Talk to Turtle";
	}
	else if (!questCompleted && questInProgress)
	{
		return "[Quest in Progress] Talk to Turtle";
	}
	else if (questCompleted && !questInProgress)
	{
		return "[Quest Completed] Hear old legend from Turtle";
	}
}
// Describes the space the user is in
void River::spaceDescript()
{
	if (!questCompleted && !questInProgress)
	{
		std::cout << "The river does not look like water.\n";
		std::cout << "It is almost opaque and lightly dotted.\n";
		std::cout << "A turtle is minding his 9-5 schedule.\n";
	}
	else if (!questCompleted && questInProgress)
	{
		std::cout << "The river would have a nice view if it\n";
		std::cout << "were not for an impatient turtle approaching\n";
		std::cout << "you slowly but steadily.\n";
	}
	else if (questCompleted && !questInProgress)
	{
		std::cout << "A satisfied turtle is relaxing near the river.\n";
		std::cout << "He is listening to the song \"So Happy Together\"\n";
		std::cout << "On his Sony Walkman. \n";
	}
}

// Returns a GameItem pointer of Boba Tea object
GameItem * River::getDrink()
{
	std::cout << "You have obtained 1 Honeydew Boba Tea\n";
	GameItem * bobaTea = new GameItem("Honeydew Boba Tea", 3, true);
	return bobaTea;
}
// (Special Action 2) Dialogue of Turtle quest
void River::talkTurtle()
{
	if (!questCompleted && !questInProgress) // Initial meet of Turtle, assigns quest
	{
		std::cout << "Turtle: What do you want?\n";
		std::cout << "Turtle: (Sigh)..I have been expecting you.\n";
		std::cout << "Turtle: I received a sign from the heavens.\n";
		std::cout << "Turtle: You are the chosen one.\n";
		std::cout << "Turtle: What? A Raft? Escaping?\n";
		std::cout << "Turtle: Bring me [5 Chicken Nuggets] and [2 Spicy Tuna Rolls]\n";
		std::cout << "Turtle: I will tell you the old legend then..\n";

		questInProgress = true;
	}
	else if (!questCompleted && questInProgress) // Quest is not complete
	{
		std::cout << "Turtle: Why are you bothering me?\n";
		std::cout << "Turtle: Oh...\n";
		std::cout << "Turtle: Bring me [5 Chicken Nuggets] and [2 Spicy Tuna Rolls]\n";
		std::cout << "Turtle: I will tell you the old legend then..\n";
	}
	else if (questCompleted && !questInProgress) // Quest is complete
	{
		std::cout << "Turtle: The old legend says...\n";
		std::cout << "Turtle: To leave the island, raft you need..\n";
		std::cout << "Turtle: [4 Wood] , do not have greed..\n";
		std::cout << "Turtle: [2 Chicken Feathers], be a star..\n";
		std::cout << "Turtle: [2 Coconut Leaves], you will go far!\n";
	}
}

// Setters and getters
bool River::getQuestInProgress()
{
	return questInProgress;
}

void River::setQuestCompleted(bool userSet)
{
	questCompleted = userSet;
}

void River::setQuestInProgress(bool userSetProg)
{
	questInProgress = userSetProg;
}


