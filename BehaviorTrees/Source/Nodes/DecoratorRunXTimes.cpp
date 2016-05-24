#include "DXUT.h"
#include "../BehaviorTree.h"



LOGIC_UPDATE_FUNC(DecoratorRunXTimes)
{
	if (currentStatus == NS_OnEnter)
	{
		currentStatus = NS_Running;
		(currX) = 0;
		//m_currentChildIndex = 0;
	}
	else
	{
		if (childStatus == NS_Running)
		{
			currentStatus = NS_Running;
		}
		

		else if (childStatus == NS_Completed)
		{
			//currentStatus = NS_Failed;
			if ((currX) < x)
			{
				(currX)++;
			//	m_currentChildIndex = 0;
				//[tell child to run again here?]
			}

			else
			{
				currentStatus = NS_Completed;
			}

		}
		else if (childStatus == NS_Failed)
		{
			//currentStatus = NS_Completed;

			//currentStatus = NS_Failed;
			if ((currX) < x)
			{
				(currX)++;
				//[tell child to run again here?]
				currentStatus = NS_Running;
			}

			else
			{
				currentStatus = NS_Failed;
			}

		}
	}
}
END_LOGIC_UPDATE_FUNC

ON_EDIT_FUNC(DecoratorRunXTimes)
{

}
END_ON_EDIT_FUNC

NODE_MSG_RECEIVED(DecoratorRunXTimes)
{

}
END_NODE_MSG_RECEIVED