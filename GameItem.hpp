/************************** GameItem *****************************
** The GameItem class represents items in the game the player can
** collect and use. There is a special type, known as food that the 
** player can consume. This is defined by isEdible bool variable.
*********************************************************************/

#ifndef GAMEITEM_HPP
#define GAMEITEM_HPP

#include <string>

class GameItem
{
private:
	std::string itemName;
	int healthRecoverPt;
	bool isEdible;
public:
	GameItem(std::string setName, int setRecoverHP, bool setEdible);
	std::string getItemName();
	int getHealthRecoverPt();
	bool getIsEdible();
};

#endif
