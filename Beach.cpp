/***************************** Beach ********************************
** The Beach class is a child of the Space class. The special features
** of the beach are that you can build a raft or gather coconut leaves.
*********************************************************************/

#include "Beach.hpp"

/*
** Parameters: integer of spaceNo the object will have when
** initialized in the constructor.
*/
Beach::Beach(int spaceType)
{
	spaceNo = spaceType;

	top = NULL;
	right = NULL;
	left = NULL;
	bottom = NULL;

	knowledgeRaft = false;
	raftBuilt = false;
	haveRaft = false;
}
// Returns area name string
std::string Beach::getType()
{
	return "Beach";
}
// Returns special action 1 string
std::string Beach::getActionName()
{
	return "Attempt to build raft";
}
// Returns special action 2 string
std::string Beach::getActionName2()
{
	return "Gather coconut leaves";
}
// Describes the space the user is in
void Beach::spaceDescript()
{
	if (!knowledgeRaft && !raftBuilt) // No knowledge of raft building
	{
		std::cout << "The beach is dusted with sand and debris.\n";
		std::cout << "The ocean runs west with a dense forest to the east.\n";
		std::cout << "Up ahead, there is a clearing.\n";
	}
	else if (knowledgeRaft && !raftBuilt) // Have knowledge, raft is not built
	{
		std::cout << "After a second look, this island has more to offer.\n";
		std::cout << "There is world class cuisine and warm locals.\n";
		std::cout << "Despite reptiles being cold-blooded.\n";
	}
	else if (knowledgeRaft && raftBuilt) // Built a raft already
	{
		std::cout << "The waves against the beach calm down.\n";
		std::cout << "The trees that were swaying become still.\n";
		std::cout << "You want to take a photo but you do not have a selfie stick.\n";
	}
}
/*
** buildRaft statements are based on what
** phase the player is in the game. They initially do not
** know how to build a raft because they have to complete
** a quest prior. After completing, they gain this knowledge
** and then the statements are modified.
*/
void Beach::buildRaft()
{
	if (!knowledgeRaft && !raftBuilt) // No knowledge of raft building
	{
		std::cout << "You are not sure how to build a raft.\n";
		std::cout << "Maybe you should talk to an expert.\n";
		std::cout << "Is there even anyone on this island?\n";
	}
	else if (knowledgeRaft && !raftBuilt) // Have knowledge, raft is not built
	{
		std::cout << "This would be a good place to build a raft.\n";
		std::cout << "You heard from an old legend that it requires:\n";
		std::cout << "[4 Wood], [2 Chicken Feathers], & [2 Coconut Leaves].\n";
	}
	else if (knowledgeRaft && raftBuilt) // Built a raft already
	{
		if (haveRaft)
		{ 
			std::cout << "You have already built your raft. What a nice day to set sail.\n";
		}
		else // This is a fail safe situation if the user somehow chooses to discard their raft.
		{
			std::cout << "You have lost your raft. How did that happen??\n";
			std::cout << "After an hour of searching, you found it underneath a snail.\n";
			// New raft is given
		}
	}
}

// Returns a GameItem pointer of a new Coconut Leaf object
GameItem * Beach::gatherLeaves()
{
	std::cout << "You have gathered 1 Coconut Leaf.\n";
	GameItem * cocoLeaf = new GameItem("Coconut Leaf", 0, false);
	return cocoLeaf;
}

// Returns a GameItem pointer of a new Raft object
GameItem * Beach::giveRaft()
{
	std::cout << "1 Raft has been added to your inventory.\n";
	GameItem * sailRaft = new GameItem("Raft", 0, false);
	return sailRaft;
}

// Setters and Getters
void Beach::setknowledgeRaft(bool userSet)
{
	knowledgeRaft = userSet;
}

void Beach::setRaftBuilt(bool userSet)
{
	raftBuilt = userSet;
}

void Beach::setHaveRaft(bool userSet)
{
	haveRaft = userSet;
}

bool Beach::getKnowledgeRaft()
{
	return knowledgeRaft;
}

bool Beach::getRaftBuilt()
{
	return raftBuilt;
}
