#include "DXUT.h"
#include "../gameobject.h"
#include "../BehaviorTree.h"
#include "../database.h"
#include "../body.h"
#include "../movement.h"
#include "../GUIWindow.h"

bool isNearTarget(D3DXVECTOR3 &pos, D3DXVECTOR3 &target, float nearDist)
{
	return
		(abs(pos.x - target.x) < nearDist) &&
		(abs(pos.y - target.y) < nearDist) &&
		(abs(pos.z - target.z) < nearDist);
}

//static bool jog = false;
LEAF_UPDATE_FUNC(ArrestTarget)
{

	if (currentStatus == NS_OnEnter)
	{
		killerID = static_cast<objectID>(-1);
	}



  //GameObject *me = g_database.Find(self);
  //GameObject *v = g_database.Find(victimID);
  //float nearDist = 1.f / 100.f;
  //if (me && v && isNearVictim(me->GetBody().GetPos(), v->GetBody().GetPos(), nearDist )  )
  //{
	 // //Kill target
	 // v->MarkForDeletion();
	 // 
	 // for (int i = 0; i < g_database.GetSize(); i++)
	 // {
		//  IBTNode::SendMsg(VICTIM_KILLED_BROADCAST, static_cast<objectID>(i), self,"MessageReceiver", MSG_Data(me->GetID()));
	 // }
	 // currentStatus = NS_Completed;
	GameObject* me = g_database.Find(self);
	if (me)
	{
		for (int i = 0; i < g_database.GetSize(); ++i)
		{
			GameObject* g = g_database.Find(i);
			if (g)
			{
				if (isNearTarget(g->GetBody().GetPos(), me->GetBody().GetPos(), 0.01f))
				{
					if (killerID == g->GetID())
					{
						IBTNode::SendMsg(ARREST_SUCCESSFUL_MESSAGE, g->GetID(), self, "MessageReader", MSG_Data());
						currentStatus = NS_Completed;

						i = g_database.GetSize();

					}

					else
					{
						IBTNode::SendMsg(FALSE_ARREST_MESSAGE, g->GetID(), self, "MessageReader", MSG_Data());
						currentStatus = NS_Completed;
						i = g_database.GetSize();
					}

				}
				else
				{
					currentStatus = NS_Failed;
				}
			}
			else
			{
				currentStatus = NS_Failed;
			}
		}


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
}
END_LEAF_UPDATE_FUNC
	  
	  






ON_EDIT_FUNC(ArrestTarget)
{
  //ImGui::Checkbox("Jog", &jog);
}
END_ON_EDIT_FUNC

NODE_MSG_RECEIVED(ArrestTarget)
{
	if (name == VICTIM_KILLED_BROADCAST)
	{
		killerID = data.GetObjectID();
	}


	/*GameObject *me = g_database.Find(self);
	if (name == MSG_Arrived)
	{
		currentStatus = NS_Completed;
		me->GetMovement().SetIdleSpeed();

	}*/
}
END_NODE_MSG_RECEIVED