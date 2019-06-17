/*************************** GamePlayer ******************************
** The GamePlayer class represents the player within the game that
** has two member variables: healthPT and maxPt indicating their 
** current health and max health.
*********************************************************************/

#ifndef GAMEPLAYER_HPP
#define GAMEPLAYER_HPP

class GamePlayer
{
private:
	int healthPt, maxPt;
public:
	GamePlayer(int startHealth, int startMaxPt);
	int getHealthPt();
	int getMaxPt();
	void setHealthPt(int hitPoint);
};
#endif