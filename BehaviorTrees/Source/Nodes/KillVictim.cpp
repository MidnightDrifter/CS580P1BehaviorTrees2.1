#include "DXUT.h"
#include "../gameobject.h"
#include "../BehaviorTree.h"
#include "../database.h"
#include "../body.h"
#include "../movement.h"
#include "../GUIWindow.h"

bool isNearVictim(D3DXVECTOR3 &pos, D3DXVECTOR3 &target, float nearDist)
{
	return
		(abs(pos.x - target.x) < nearDist) &&
		(abs(pos.y - target.y) < nearDist) &&
		(abs(pos.z - target.z) < nearDist);
}

//static bool jog = false;
LEAF_UPDATE_FUNC(KillVictim)
{
  GameObject *me = g_database.Find(self);
  GameObject *v = g_database.Find(victimID);
  float nearDist = 1.f / 100.f;
  if (me && v && isNearVictim(me->GetBody().GetPos(), v->GetBody().GetPos(), nearDist )  )
  {
	  //Kill target
	  v->MarkForDeletion();
	  
	  for (int i = 0; i < g_database.GetSize(); i++)
	  {
		  IBTNode::SendMsg(VICTIM_KILLED_BROADCAST, static_cast<objectID>(i), self,"PursueSuspect", MSG_Data(me->GetID()));
		 // IBTNode::SendMsg(VICTIM_KILLED_BROADCAST, static_cast<objectID>(i), self,)
	  }
	  currentStatus = NS_Completed;
	  
	  
	  
	  
	  
	  //  if (currentStatus == NS_OnEnter)
	  //  {
	  //    if (jog)me->GetMovement().SetJogSpeed();
	  //    else me->GetMovement().SetWalkSpeed();
	  //    me->GetMovement().SetTarget(me->GetTargetPOS());
	  //    currentStatus = NS_Running;
	  //  }
	  //  else
	  //  {
	  //   /* if (isNear(me->GetBody().GetPos(), me->GetTargetPOS()))
	  //    {
	  //      currentStatus = NS_Completed;
	  //      me->GetMovement().SetIdleSpeed();
	  //    }*/
	  //  }
	  //}
	  //else
	  //{
	  //  currentStatus = NS_Failed;
	  //}
  }

  else
  {
	  currentStatus = NS_Failed;
  }
}
END_LEAF_UPDATE_FUNC




ON_EDIT_FUNC(KillVictim)
{
  //ImGui::Checkbox("Jog", &jog);
}
END_ON_EDIT_FUNC

NODE_MSG_RECEIVED(KillVictim)
{
	/*GameObject *me = g_database.Find(self);
	if (name == MSG_Arrived)
	{
		currentStatus = NS_Completed;
		me->GetMovement().SetIdleSpeed();

	}*/
}
END_NODE_MSG_RECEIVED