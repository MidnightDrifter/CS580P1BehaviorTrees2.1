#include "DXUT.h"
#include "../BehaviorTree.h"

LOGIC_UPDATE_FUNC(DecoratorRunXTimesOrUntilSucceed)
{
	if (currentStatus == NS_OnEnter)
	{
		currentStatus = NS_Running;
		(currX) = 0;
		m_currentChildIndex = 0;
	}
	else
	{
		if (childStatus == NS_Running)
		{
			currentStatus = NS_Running;
		}
		

		else if (childStatus == NS_Failed)
		{
			printf("%d %d\n", currX, x);
			//currentStatus = NS_Failed;
			if ((currX) < x)
			{
				(currX)++;
				//[tell child to run again here?]
				//m_currentChildIndex = 0;
				currentStatus = NS_Running;
			}

			else
			{
				currentStatus = NS_Completed;
			}

		}
		else if(childStatus != NS_OnEnter)
		{
			currentStatus = NS_Completed;


		}
	}
}
END_LOGIC_UPDATE_FUNC

ON_EDIT_FUNC(DecoratorRunXTimesOrUntilSucceed)
{

}
END_ON_EDIT_FUNC

NODE_MSG_RECEIVED(DecoratorRunXTimesOrUntilSucceed)
{

}
END_NODE_MSG_RECEIVED