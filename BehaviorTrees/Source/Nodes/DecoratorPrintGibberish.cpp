#include "DXUT.h"
#include "../BehaviorTree.h"

LOGIC_UPDATE_FUNC(DecoratorPrintGibberish)
{
	if (currentStatus == NS_OnEnter)
	{
		currentStatus = NS_Running;
		printf("Habbala babbala.");
	}
	else
	{
		currentStatus = childStatus;
	}
	
}
END_LOGIC_UPDATE_FUNC

ON_EDIT_FUNC(DecoratorPrintGibberish)
{

}
END_ON_EDIT_FUNC

NODE_MSG_RECEIVED(DecoratorPrintGibberish)
{

}
END_NODE_MSG_RECEIVED