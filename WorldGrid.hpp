/************************** WorldGrid *****************************
** The WorldGrid class represents the world the player is in and
** also handles gameplay interactions as it moves across each
** space. 
*********************************************************************/

#ifndef WORLDGRID_HPP
#define WORLDGRID_HPP

#include "Space.hpp"
#include "Beach.hpp"
#include "Ocean.hpp"
#include "Plains.hpp"
#include "Forest.hpp"
#include "River.hpp"
#include "Hut.hpp"
#include "Backpack.hpp"


#include <iostream>

class WorldGrid
{
private:
	Beach * beachSpace;
	Ocean * oceanSpace;
	Plains * plainSpace;
	Forest * forSpace;
	River * riverSpace;
	Hut * hutSpace;

	Space * currentSpace;

	GamePlayer * islandExplorer;
	Backpack playerBackpack;

	bool completeGame;
public:
	WorldGrid();

	// Space and Movement
	void printLocation();
	void printMap();
	void walkGrid(int playerDirect);
	void getValidWalk(int *& refArray, int & sizeOfArray);

	// Backpack
	void viewAllItems();
	void viewFood();
	void removeItem(int userRemove);
	void eatSomething(int userFood);
	bool isThereFood();
	bool isItemFood(int itemIndex);
	bool areThereItems();
	int getBackPackSize();
	void getFoodArray(int *& refArray, int & sizeOfArray);

	// Player Action
	void specialAction();
	void specialAction2();

	// Setters and Getters
	Space * getCurrentSpace();
	void setCurrentSpace(Space * spaceName);
	bool getCompleteGame();
	int getPlayerHealth();
	~WorldGrid();
};
#endif

