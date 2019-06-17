/************************** Backpack *****************************
** The Backpack class represents the player inventory in the game
** Island Escape. The backpack class uses the STL container vector
** and has functions to add and remove items from the backpack.
*********************************************************************/

#include "Backpack.hpp"

using std::cout;

// Constructor that initializes the inventory limit
Backpack::Backpack()
{
	inventoryLimit = 10;
}

/*
** Parameter: GameItem pointer
** Takes a GameItem pointer and adds the item to the islandBackpack vector.
** If the inventory is full, the item is deleted.
*/
void Backpack::addToPack(GameItem * itemToAdd)
{
	if (islandBackpack.size() < inventoryLimit)
	{ 
		islandBackpack.push_back(itemToAdd);
	}
	else
	{
		cout << "Your backpack is full so you were forced to discard " << itemToAdd->getItemName() << " :(.\n";
		cout << itemToAdd->getItemName() << ", you will be forever missed, my dear friend.\n";
		// Removing from memory
		delete itemToAdd;
		itemToAdd = NULL;
	}
}

/*
** Parameter: integer of index of item to be removed from backpack vector
** This allows an item to removed from a specific index point. This is
** based on a stackoverflow post: 
** https://stackoverflow.com/questions/875103/how-do-i-erase-an-element-from-stdvector-by-index
*/
void Backpack::removeFromPack(int itemIndex)
{
	delete islandBackpack[itemIndex];
	islandBackpack[itemIndex] = NULL;
	islandBackpack.erase(islandBackpack.begin() + itemIndex);
	islandBackpack.shrink_to_fit();
}

/*
**  Parameter: integer of index of item to be removed from backpack vector
**  Applies the removeFromPack function and then prints a statement of what item was removed.
*/
void Backpack::removeGameItem(int itemChoice)
{
	cout << "Threw away " << islandBackpack[itemChoice - 1]->getItemName() << ".\n";
	removeFromPack(itemChoice - 1);
}

/*
** Returns: integer of how much food is in the backpack
*/
int Backpack::countManyFood()
{
	int foodCount = 0;
	// Iterates through backpack for edible items
	if (!islandBackpack.empty())
	{
		for (int i = 0; i < islandBackpack.size(); i++)
		{
			if (islandBackpack[i]->getIsEdible())
			{
				foodCount++;
			}
		}
	}
	else
	{
		foodCount = 0;
	}

	return foodCount;
}

/*
** Parameters: referenced integer pointer and referenced integer of array size
** This function forms a new array of index numbers in the backpack that are
** identified as food. This is used in input validation when the user is
** picking food to eat from the backpack.
*/
void Backpack::generateFoodArray(int *& arrayEdited, int & arraySize)
{
	int arrayIndex = 0;
	arraySize = countManyFood();
	arrayEdited = new int[arraySize];

	for (int i = 0; i < islandBackpack.size(); i++)
	{
		if (islandBackpack[i]->getIsEdible())
		{
			arrayEdited[arrayIndex] = (i + 1);
			arrayIndex++;
		}
	}
}

/*
** Parameters: integer of item index number and pointer to GamePlayer
** Removes item that is chosen to be eaten and then changes the player health
** based on the recovery value the item provides.
*/
void Backpack::eatFood(int itemChoice, GamePlayer * myPlayer)
{
	if (islandBackpack[itemChoice - 1]->getIsEdible())
	{
		cout << "You have consumed " << islandBackpack[itemChoice - 1]->getItemName()
			<< ".\nYou have recovered " << islandBackpack[itemChoice - 1]->getHealthRecoverPt()
			<< " HP.\n";
		myPlayer->setHealthPt(myPlayer->getHealthPt() + islandBackpack[itemChoice - 1]->getHealthRecoverPt());
		
		// Prevent health overflow from max hit point
		if (myPlayer->getHealthPt() > myPlayer->getMaxPt())
		{
			myPlayer->setHealthPt(myPlayer->getMaxPt());
		}

		removeFromPack(itemChoice - 1);
	}
	else
	{
		cout << "You are unable to eat " << islandBackpack[itemChoice - 1]->getItemName() << ".\n";
	}
}

/*
** Parameters: integer of item index number 
** Returns true if the item in that index is edible, otherwise false.
*/
bool Backpack::foodCheck(int itemIndex)
{
	if (islandBackpack[itemIndex]->getIsEdible())
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
** printPack() prints all items contained in the backpack. If the item is a food,
** it also prints the recovery value.
*/
void Backpack::printPack()
{
	cout << "-----\n";
	if (!islandBackpack.empty())
	{
		for (int i = 0; i < islandBackpack.size(); i++)
		{
			cout << i + 1 << ". " << islandBackpack[i]->getItemName();
			if (islandBackpack[i]->getIsEdible())
			{
				cout << " (Recovers " << islandBackpack[i]->getHealthRecoverPt() << " HP)";
			}
			cout << "\n";
		}
	}
	else
	{
		cout << "Your backpack is currently empty.\n";
	}
	cout << "-----\n";
}

/*
** printFood() prints all food items contained in the backpack.
*/
void Backpack::printFood()
{
	cout << "-----\n";
	if (!islandBackpack.empty())
	{

		for (int i = 0; i < islandBackpack.size(); i++)
		{
			if (islandBackpack[i]->getIsEdible())
			{ 
				cout << i + 1 << ". " << islandBackpack[i]->getItemName();
				cout << " (Recovers " << islandBackpack[i]->getHealthRecoverPt() << " HP)";
				cout << "\n";
			}
		}
	}
	else
	{
		cout << "Your backpack is currently empty.\n";
	}
	cout << "-----\n";
}

/*
** Parameters: string of item name, and integer of item quantity
** Returns: bool value indicating whether there are the defined item quantity
** of that item name.
** This is used in the quest in the game to determine if the user
** has the required items.
*/
bool Backpack::countReqItem(std::string itemName, int itemQty)
{
	int currentCount = 0;

	for (int i = 0; i < islandBackpack.size(); i++)
	{
		if (islandBackpack[i]->getItemName() == itemName)
		{
			currentCount++;
		}
	}

	/* Note: the current count can be
	** greater or equal to item quantity to return true.
	*/
	if (currentCount >= itemQty)
	{
		return true;
	}
	else
	{
		return false;
	}
}
/*
** Parameters: string of item name and integer of item quantity
** removeByName takes the items and removes them from
** the player's inventory
*/
void Backpack::removeByName(std::string itemName, int itemQty)
{
	int itemsRemoved = 0;

	while (itemsRemoved < itemQty)
	{
		for (int i = 0; i < islandBackpack.size(); i++)
		{
			if (itemsRemoved < itemQty)
			{ 
				if (islandBackpack[i]->getItemName() == itemName)
				{
					delete islandBackpack[i];
					islandBackpack[i] = NULL;
					islandBackpack.erase(islandBackpack.begin() + i);
					islandBackpack.shrink_to_fit();
					itemsRemoved++;
				}
			}
		}
	}
}

/*
** Returns: bool value indicating if the backpack is empty
*/
bool Backpack::isPackEmpty()
{
	return islandBackpack.empty();
}


int Backpack::getInventoryLimit()
{
	return inventoryLimit;
}


int Backpack::getPackSize()
{
	return islandBackpack.size();
}


// Destructor that removes backpack items if there are any
Backpack::~Backpack()
{
	int packSize = getPackSize();

	if (!isPackEmpty())
	{ 
		for (int i = (packSize-1); i > -1; i--)
		{
			removeFromPack(i);
		}
	}
}


