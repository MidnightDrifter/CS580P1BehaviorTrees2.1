#include "DXUT.h"
#include "../BehaviorTree.h"
LOGIC_UPDATE_FUNC(SequencerRegardlessOfFail)
{
	if (currentStatus == NS_OnEnter)
	{
		currentStatus = NS_Running;
		m_currentChildIndex = 0;
	}
	else
	{
		if (childStatus != NS_OnEnter && childStatus != NS_Running)
		{
			m_currentChildIndex++;

			if (m_currentChildIndex >= (int)m_children.size())
			{
				currentStatus = NS_Completed;
			}

		}

		else
		{
			currentStatus = NS_Running;
		}
	
	}
}
END_LOGIC_UPDATE_FUNC

ON_EDIT_FUNC(SequencerRegardlessOfFail)
{
  
}
END_ON_EDIT_FUNC

NODE_MSG_RECEIVED(SequencerRegardlessOfFail)
{

}
END_NODE_MSG_RECEIVED