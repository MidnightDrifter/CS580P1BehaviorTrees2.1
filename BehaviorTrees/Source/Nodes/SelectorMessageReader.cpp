#include "DXUT.h"
#include "../BehaviorTree.h"
LOGIC_UPDATE_FUNC(MessageReader)
{
	if (currentStatus == NS_OnEnter)
	{
		currentStatus = NS_Running;
		childIndex=1;
	}
	else
	{
		m_currentChildIndex = childIndex;
			
	}
}
END_LOGIC_UPDATE_FUNC

ON_EDIT_FUNC(MessageReader)
{
  
}
END_ON_EDIT_FUNC

NODE_MSG_RECEIVED(MessageReader)
{
	if(name == ARREST_SUCCESSFUL_MESSAGE  || FALSE_ARREST_MESSAGE)
	{
		childIndex = 0;
	}

}
END_NODE_MSG_RECEIVED