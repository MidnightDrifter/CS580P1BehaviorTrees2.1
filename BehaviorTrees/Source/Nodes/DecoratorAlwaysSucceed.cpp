#include "DXUT.h"
#include "../BehaviorTree.h"
LOGIC_UPDATE_FUNC(DecoratorAlwaysSucceed)
{
	if (currentStatus == NS_OnEnter)
	{
		currentStatus = NS_Running;
		m_currentChildIndex = 0;
	}
	else if (childStatus == NS_Running)
	{
		currentStatus = NS_Running;
	}

		else 
		{
			currentStatus = NS_Completed;
		}
}
END_LOGIC_UPDATE_FUNC
ON_EDIT_FUNC(DecoratorAlwaysSucceed)
{

}
END_ON_EDIT_FUNC
NODE_MSG_RECEIVED(DecoratorAlwaysSucceed)
{

}
END_NODE_MSG_RECEIVED