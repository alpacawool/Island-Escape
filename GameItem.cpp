/************************** GameItem *****************************
** The GameItem class represents items in the game the player can
** collect and use. There is a special type, known as food that the
** player can consume. This is defined by isEdible bool variable.
*********************************************************************/

#include "GameItem.hpp"

/*
** Parameters: string of item name, int of item recovery HP, and 
** bool indicating whether the item is edible. TRUE means the item is
** edible. This constructor initializes an item and their traits.
*/
GameItem::GameItem(std::string setName, int setRecoverHP, bool setEdible)
{
	itemName = setName;
	healthRecoverPt = setRecoverHP;
	isEdible = setEdible;
}

// Getters for item traits

std::string GameItem::getItemName()
{
	return itemName;
}

int GameItem::getHealthRecoverPt()
{
	return healthRecoverPt;
}

bool GameItem::getIsEdible()
{
	return isEdible;
}
