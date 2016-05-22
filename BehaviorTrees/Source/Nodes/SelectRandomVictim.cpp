#include "DXUT.h"
#include "../gameobject.h"
#include "../BehaviorTree.h"
#include "../database.h"
#include "../body.h"
#include "../movement.h"
#include "../GUIWindow.h"

//bool isNear(D3DXVECTOR3 &pos, D3DXVECTOR3 &target, float nearDist = 1.f / 100.f)
//{
//  return
//    (abs(pos.x - target.x) < nearDist) &&
//    (abs(pos.y - target.y) < nearDist) &&
//    (abs(pos.z - target.z) < nearDist);
//}
static bool jog = false;
LEAF_UPDATE_FUNC(SelectRandomVictim)
{
	if (currentStatus == NS_OnEnter)
	{
		victim = NULL;
	}


  GameObject *me = g_database.Find(self);
  
  GameObject *t = g_database.Find(static_cast<objectID>(rand() % g_database.GetSize()));
  if (me && t)
  {
	  IBTNode::SendMsg(AGENT_TARGETED_PING, (t->GetID()), self, "", MSG_Data(self));
	  //In root nodes put:
	  //  if cop:   if(node msg received == AGENT_TARGETED_PING), return data = -1
	  //  if civilian or killer:  if(node msg received == AGENT_TARGETED_PING), return data = 1

	


  }
  currentStatus = NS_Running;
}
END_LEAF_UPDATE_FUNC
ON_EDIT_FUNC(SelectRandomVictim)
{
  //ImGui::Checkbox("Jog", &jog);
}
END_ON_EDIT_FUNC

//NOTE:  THIS ASSUMES THAT THIS NODE WILL BE THE ROOT OF THE KILLER TREE

NODE_MSG_RECEIVED(SelectRandomVictim)
{
	GameObject *me = g_database.Find(self);
	if (name == AGENT_TARGETED_RESPONSE)
	{
		if(data.GetInt() == -1)
		{
			currentStatus = NS_Failed;
		}

		else
		{
			currentStatus = NS_Completed;
		}

	}

	else if (name == AGENT_TARGETED_PING)
	{
		currentStatus = NS_Failed;
	}
}
END_NODE_MSG_RECEIVED