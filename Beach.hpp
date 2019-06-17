/***************************** Beach ********************************
** The Beach class is a child of the Space class. The special features
** of the beach are that you can build a raft or gather coconut leaves.
*********************************************************************/

#ifndef BEACH_HPP
#define BEACH_HPP

#include "Space.hpp"

class Beach : public Space
{
private:
	bool knowledgeRaft;
	bool raftBuilt;
	bool haveRaft;
public:
	Beach(int spaceType);
	std::string getType();
	std::string getActionName();
	std::string getActionName2();
	void spaceDescript();
	// Beach Specific Functions
	void buildRaft();
	GameItem * gatherLeaves();
	GameItem * giveRaft();
	void setknowledgeRaft(bool userSet);
	void setRaftBuilt(bool userSet);
	void setHaveRaft(bool userSet);
	bool getKnowledgeRaft();
	bool getRaftBuilt();
	

};

#endif

