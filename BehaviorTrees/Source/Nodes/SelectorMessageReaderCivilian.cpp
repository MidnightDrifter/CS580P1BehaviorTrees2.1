#include "DXUT.h"
#include "../BehaviorTree.h"
LOGIC_UPDATE_FUNC(MessageReaderCivilian)
{
	if (currentStatus == NS_OnEnter)
	{
		//currentStatus = NS_Running;
		childIndex = 1;
		currentStatus = NS_Running;
		m_currentChildIndex = childIndex;
	}




	if (childStatus != NS_OnEnter || childStatus != NS_Running)
	{
		currentStatus = childStatus;
	}
}
END_LOGIC_UPDATE_FUNC

ON_EDIT_FUNC(MessageReaderCivilian)
{
  
}
END_ON_EDIT_FUNC

NODE_MSG_RECEIVED(MessageReaderCivilian)
{
	if(name == ARREST_SUCCESSFUL_MESSAGE  || FALSE_ARREST_MESSAGE)
	{
		childIndex = 0;
	}

}
END_NODE_MSG_RECEIVED