#include "DXUT.h"
#include "../BehaviorTree.h"
LOGIC_UPDATE_FUNC(MessageReader)
{
	if (currentStatus == NS_OnEnter)
	{
		//currentStatus = NS_Running;
		childIndex = 1;
		currentStatus = NS_Running;
		m_currentChildIndex = childIndex;
		timeAcc = 0.f;
	}

	if (timeAcc > 4.5f)
	{
		currentStatus =NS_Completed;
		timeAcc = 0.f;
	}

	else
	{
		timeAcc += dt;
		currentStatus = NS_Running;
	}

	//if (childStatus != NS_OnEnter || childStatus != NS_Running)
	//{
	//	currentStatus = childStatus;
	//}
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
		m_currentChildIndex = 0;
	}

}
END_NODE_MSG_RECEIVED