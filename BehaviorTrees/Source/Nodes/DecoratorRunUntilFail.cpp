#include "DXUT.h"
#include "../BehaviorTree.h"


LOGIC_UPDATE_FUNC(DecoratorRunUntilFail)
{
	if (currentStatus == NS_OnEnter)
	{
		currentStatus = NS_Running;
		m_currentChildIndex = 0;
	}
	else
	{
		if (childStatus == NS_Failed)
		{
			currentStatus = NS_Completed;
		}
	}
}
END_LOGIC_UPDATE_FUNC
ON_EDIT_FUNC(DecoratorRunUntilFail)
{

}
END_ON_EDIT_FUNC
NODE_MSG_RECEIVED(DecoratorRunUntilFail)
{

}
END_NODE_MSG_RECEIVED