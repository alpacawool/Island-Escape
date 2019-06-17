/*************************** GamePlayer ******************************
** The GamePlayer class represents the player within the game that
** has two member variables: healthPT and maxPt indicating their
** current health and max health.
*********************************************************************/

#include "GamePlayer.hpp"

/*
** Parameters: integers for current health and max health
** Initializes the traits of the player
*/
GamePlayer::GamePlayer(int startHealth, int startMaxPt)
{
	healthPt = startHealth;
	maxPt = startMaxPt;
}

// Setters and getters

int GamePlayer::getHealthPt()
{
	return healthPt;
}

int GamePlayer::getMaxPt()
{
	return maxPt;
}

void GamePlayer::setHealthPt(int hitPoint)
{
	healthPt = hitPoint;
}
