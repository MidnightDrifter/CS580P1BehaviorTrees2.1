#include "DXUT.h"
#include "../BehaviorTree.h"
#include "../gameobject.h"
#include "../database.h"
LOGIC_UPDATE_FUNC(DataInitializer)
{
	if(currentStatus = NS_OnEnter)
	{
		copID = static_cast<objectID>(-1);
		killerID = copID;
		targetID = copID;
		branchToVictory = false;
		branchToDefeat = false;

	}

		currentStatus = NS_Running;
		m_currentChildIndex = 0;

	
}
END_LOGIC_UPDATE_FUNC

ON_EDIT_FUNC(DataInitializer)
{
  
}
END_ON_EDIT_FUNC

NODE_MSG_RECEIVED(DataInitializer)
{

}
END_NODE_MSG_RECEIVED