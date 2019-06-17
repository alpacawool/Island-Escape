/************************** Backpack *****************************
** The Backpack class represents the player inventory in the game
** Island Escape. The backpack class uses the STL container vector 
** and has functions to add and remove items from the backpack.
*********************************************************************/

#ifndef BACKPACK_HPP
#define BACKPACK_HPP

#include "GameItem.hpp"
#include "GamePlayer.hpp"

#include <iostream>
#include <vector>

class Backpack 
{
private:
	std::vector<GameItem*> islandBackpack;
	int inventoryLimit;
public:
	Backpack();
	// Add and remove items to backpack
	void addToPack(GameItem* itemToAdd);
	void removeFromPack(int itemIndex);
	void removeGameItem(int itemChoice);
	// Food type item related functions
	int countManyFood();
	void generateFoodArray(int *& arrayEdited, int & arraySize);
	void eatFood(int itemChoice, GamePlayer * myPlayer);
	bool foodCheck(int itemIndex);
	// Printing
	void printPack();
	void printFood();
	// Quest Related
	bool countReqItem(std::string itemName, int itemQty);
	void removeByName(std::string itemName, int itemQty);
	bool isPackEmpty();
	// Setters and Getters
	int getInventoryLimit();
	int getPackSize();
	~Backpack();
};

#endif
