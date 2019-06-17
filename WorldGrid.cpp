/************************** WorldGrid *****************************
** The WorldGrid class represents the world the player is in and
** also handles gameplay interactions as it moves across each
** space.
*********************************************************************/

#include "WorldGrid.hpp"

using std::cout;

// Constructor
WorldGrid::WorldGrid()
{
	// Initialize spaces
	beachSpace = new Beach(1);
	oceanSpace = new Ocean(2);
	plainSpace = new Plains(3);
	forSpace = new Forest(4);
	riverSpace = new River(5);
	hutSpace = new Hut(6);

	// Update references
	beachSpace->setTop(plainSpace);
	beachSpace->setRight(forSpace);
	beachSpace->setLeft(oceanSpace);
	beachSpace->setBottom(hutSpace);

	oceanSpace->setRight(beachSpace);

	plainSpace->setRight(riverSpace);
	plainSpace->setBottom(beachSpace);

	forSpace->setTop(riverSpace);
	forSpace->setLeft(beachSpace);

	riverSpace->setLeft(plainSpace);
	riverSpace->setBottom(forSpace);

	hutSpace->setTop(beachSpace);

	// Initialize Player
	islandExplorer = new GamePlayer(100,100);

	// Start at beach
	currentSpace = beachSpace;

	completeGame = false;
}

/*
** The print location function prints the map, the location, the player health
** and the backpack inventory count.
*/
void WorldGrid::printLocation()
{
	printMap();
	cout << "------------------\n";
	cout << "Location: " << currentSpace->getType() << "\n";
	cout << "Health: " << islandExplorer->getHealthPt() << " / " << islandExplorer->getMaxPt() << " \n";
	cout << "Backpack: " << playerBackpack.getPackSize() << " / " << playerBackpack.getInventoryLimit() << "\n";

	cout << "------------------\n";
	currentSpace->spaceDescript();
	cout << "------------------\n";
}

/*
** The print map function is a switch that prints the map differently based on
** the space number ID. An exclamation point represents where the player
** is currently at.
*/
void WorldGrid::printMap()
{
	switch (currentSpace->getSpaceNo())
	{
	case 1:
		cout << "      **************\n"
			<< "      *  P  *   R  *\n"
			<< "********************\n"
			<< "*  O  *  !  *   F  *\n"
			<< "********************\n"
			<< "      *  H  *\n"
			<< "      *******\n";
		break;
	case 2:
		cout << "      **************\n"
			<< "      *  P  *   R  *\n"
			<< "********************\n"
			<< "*  !  *  B  *   F  *\n"
			<< "********************\n"
			<< "      *  H  *\n"
			<< "      *******\n";
		break;
	case 3:
		cout << "      **************\n"
			<< "      *  !  *   R  *\n"
			<< "********************\n"
			<< "*  O  *  B  *   F  *\n"
			<< "********************\n"
			<< "      *  H  *\n"
			<< "      *******\n";
		break;
	case 4:
		cout << "      **************\n"
			<< "      *  P  *   R  *\n"
			<< "********************\n"
			<< "*  O  *  B  *   !  *\n"
			<< "********************\n"
			<< "      *  H  *\n"
			<< "      *******\n";
		break;
	case 5:
		cout << "      **************\n"
			<< "      *  P  *   !  *\n"
			<< "********************\n"
			<< "*  O  *  B  *   F  *\n"
			<< "********************\n"
			<< "      *  H  *\n"
			<< "      *******\n";
		break;
	case 6:
		cout << "      **************\n"
			<< "      *  P  *   R  *\n"
			<< "********************\n"
			<< "*  O  *  B  *   F  *\n"
			<< "********************\n"
			<< "      *  !  *\n"
			<< "      *******\n";
		break;
	}
	cout << "( ! ) You are here\n";
}

/*
** Parameter: integer of direction player is going in
** Sets the current space to the new direction the player is going in
** In addition, reduces the player's health by 10 for player movement
*/
void WorldGrid::walkGrid(int playerDirect)
{
	if (currentSpace->getSpacePtr(playerDirect))
	{
		islandExplorer->setHealthPt(islandExplorer->getHealthPt() - 10);
		currentSpace = currentSpace->getSpacePtr(playerDirect);
	}
	else
	{
		cout << "There is nothing in that direction. You stay in the same spot.\n";
	}
}

/*
** Parameters: referenced integer pointer and referenced integer of array size
** This function forms a new array of index numbers that are valid directions
** the user can go in based on where they are on the world grid (in other words,
** the pointers that are not NULL). This is used in input validation.
*/
void WorldGrid::getValidWalk(int *& refArray, int & sizeOfArray)
{
	int validSpace = 0;
	int arrayIndex = 0;

	for (int i = 1; i < 5; i++)
	{
		if (currentSpace->getSpacePtr(i))
		{
			validSpace++;
		}
	}

	sizeOfArray = validSpace;

	refArray = new int[sizeOfArray];

	for (int i = 1; i < 5; i++)
	{ 
		if (currentSpace->getSpacePtr(i))
		{
			refArray[arrayIndex] = i;
			arrayIndex++;
		}
	}
}

/*
** viewAllItems calls backpack printPack function
*/
void WorldGrid::viewAllItems()
{
	playerBackpack.printPack();
}

/*
** viewFood calls backpack printFood function
*/
void WorldGrid::viewFood()
{
	playerBackpack.printFood();
}

/*
** Parameters: integer of index of item to be removed from bag
** Calls backpack's removeGameItem function
*/
void WorldGrid::removeItem(int userRemove)
{
	playerBackpack.removeGameItem(userRemove);
}

/*
** Parameters: integer of index of item to be eaten
** Calls backpack's eatFood function and also applies
** the player object
*/
void WorldGrid::eatSomething(int userFood)
{
	playerBackpack.eatFood(userFood, islandExplorer);
}

// Returns a bool value indicating whether there is food
bool WorldGrid::isThereFood()
{
	if (playerBackpack.countManyFood() == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

/*
** Parameters: integer of item index in backpack
** Returns: bool value indicating whether item is food (true) or not (false)
*/
bool WorldGrid::isItemFood(int itemIndex)
{
	return playerBackpack.foodCheck(itemIndex);
}

// Returns bool indicating whether the backpack is empty
bool WorldGrid::areThereItems()
{
	if (playerBackpack.isPackEmpty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Returns current inventory size count. (not limit)
int WorldGrid::getBackPackSize()
{
	return playerBackpack.getPackSize();
}

/*
** Parameters: referenced pointer to integer and referenced integer
** that are passed through the backpack generateFoodArray function
** which is used in input validation
*/
void WorldGrid::getFoodArray(int *& refArray, int & sizeOfArray)
{
	playerBackpack.generateFoodArray(refArray, sizeOfArray);
}

/*
** In the game, there are two special actions for each space. This
** function calls the different actions that happen within each space.
*/
void WorldGrid::specialAction()
{
	switch (currentSpace->getSpaceNo())
	{
	case 1: // Build a raft
		if (beachSpace->getKnowledgeRaft())
		{
			if (!beachSpace->getRaftBuilt())
			{
				if (playerBackpack.countReqItem("Wood", 4) &&
					playerBackpack.countReqItem("Chicken Feather", 2) &&
					playerBackpack.countReqItem("Coconut Leaf", 2))
				{
					playerBackpack.removeByName("Wood", 4);
					playerBackpack.removeByName("Chicken Feather", 2);
					playerBackpack.removeByName("Coconut Leaf", 2);
					playerBackpack.addToPack(beachSpace->giveRaft());
					beachSpace->setRaftBuilt(true);
					beachSpace->setHaveRaft(true);
				}
				else
				{
					beachSpace->buildRaft();
				}
			}
			else 
			{
				if (playerBackpack.countReqItem("Raft", 1))
				{
					beachSpace->setHaveRaft(true);
					beachSpace->buildRaft();
				}
				else
				{
					beachSpace->setHaveRaft(false);
					beachSpace->buildRaft();
					playerBackpack.addToPack(beachSpace->giveRaft());
				}
			}
	
		}
		else
		{
			beachSpace->buildRaft();
		}
		break;
	case 2: playerBackpack.addToPack(oceanSpace->goFish()); // Fishing
		break;
	case 3: playerBackpack.addToPack(plainSpace->huntChickens()); // Hunting
		break;
	case 4: playerBackpack.addToPack(forSpace->chopWood()); // Chop Wood
		break;
	case 5: playerBackpack.addToPack(riverSpace->getDrink()); // Grab drink
		break;
	case 6: // Sleep
		islandExplorer->setHealthPt(islandExplorer->getHealthPt() + hutSpace->goSleep());
		if (islandExplorer->getHealthPt() > islandExplorer->getMaxPt())
		{
			islandExplorer->setHealthPt(islandExplorer->getMaxPt());
		}
		break;
	}
}

/*
** In the game, there are two special actions for each space. This
** function calls the different actions that happen within each space.
*/
void WorldGrid::specialAction2()
{
	switch (currentSpace->getSpaceNo())
	{
	case 1: playerBackpack.addToPack(beachSpace->gatherLeaves()); // Gather leaves
		break;
	case 2: 
		if (playerBackpack.countReqItem("Raft", 1)) // Complete game (Escape)
		{
			cout << "You have successfully escaped! You sail far, far, away.\n";
			completeGame = true;
		}
		else
		{
			cout << "=======================================\n";
			cout << " You need a raft to escape the island.\n";
			cout << "=======================================\n";
		}
		break;
	case 3: playerBackpack.addToPack(plainSpace->featherChick()); // Gather chicken feathers
		break;
	case 4: playerBackpack.addToPack(forSpace->getPine()); // Gather pineapples
		break;
	case 5: 
		if (riverSpace->getQuestInProgress()) // Turtle quest
		{
			// Count items 
			if (playerBackpack.countReqItem("Chicken Nugget", 5) &&
				playerBackpack.countReqItem("Spicy Tuna Roll", 2))
			{
				cout << "You have completed the quest! The items were given to Turtle.\n";
				riverSpace->setQuestInProgress(false);
				riverSpace->setQuestCompleted(true);
				beachSpace->setknowledgeRaft(true);
			}
			// Remove items, if they fit query
			if (!riverSpace->getQuestInProgress())
			{
				playerBackpack.removeByName("Chicken Nugget", 5);
				playerBackpack.removeByName("Spicy Tuna Roll", 2);
			}
			// Talk to turtle again
			riverSpace->talkTurtle();
		}
		else
		{
			riverSpace->talkTurtle();
		}
		break;
	case 6: hutSpace->readBook(); // Read book
		break;
	}

}

// Settters and Getters
Space * WorldGrid::getCurrentSpace()
{
	return currentSpace;
}

void WorldGrid::setCurrentSpace(Space * spaceName)
{
	currentSpace = spaceName;
}

bool WorldGrid::getCompleteGame()
{
	return completeGame;
}

int WorldGrid::getPlayerHealth()
{
	return islandExplorer->getHealthPt();
}

// Destructor that removes items declared by new
WorldGrid::~WorldGrid()
{
	delete beachSpace;
	delete oceanSpace;
	delete plainSpace;
	delete forSpace;
	delete riverSpace;
	delete hutSpace;
	delete islandExplorer;

	beachSpace = NULL;
	oceanSpace = NULL;
	plainSpace = NULL;
	forSpace = NULL;
	riverSpace = NULL;
	hutSpace = NULL;
	islandExplorer = NULL;
	currentSpace = NULL;
}
