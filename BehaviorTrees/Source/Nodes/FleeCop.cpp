#include "DXUT.h"
#include "../gameobject.h"
#include "../BehaviorTree.h"
#include "../database.h"
#include "../body.h"
#include "../movement.h"
#include "../GUIWindow.h"
//
//bool isNear(D3DXVECTOR3 &pos, D3DXVECTOR3 &target, float nearDist = 1.f / 100.f)
//{
//  return
//    (abs(pos.x - target.x) < nearDist) &&
//    (abs(pos.y - target.y) < nearDist) &&
//    (abs(pos.z - target.z) < nearDist);
//}
//static bool jog = false;
LEAF_UPDATE_FUNC(FleeCop)
{
	if (currentStatus == NS_OnEnter)
	{
		copID = -1;
		timeAcc =0.f;
		timer = 0;
		currentStatus = NS_Running;
	}


	if(timeAcc > 1.0f)
	{
		//timeAcc = 0.f;

		if (timer < 3.0f)
		{
			GameObject *me = g_database.Find(self);
			GameObject *c = NULL;



			float randomScale = 0.5 * (rand() % 13);


			if (copID != -1)
			{
				c = g_database.Find(static_cast<objectID>(copID));
			}

			if (timer >= 3.f) //Time in ms?
			{
				
				IBTNode::SendMsg(VICTIM_KILLED_BROADCAST, static_cast<objectID>(copID), self, "ArrestTarget", MSG_Data(self));
				timer = 0.f;
				timeAcc = 0.f;
				currentStatus = NS_Completed;
			}
			else if (me)
			{
				timer += dt;
				me->GetMovement().SetJogSpeed();
				if (copID != -1)
				{
					me->GetMovement().SetTarget(me->GetTargetPOS() - randomScale * (c->GetBody().GetDir()));
					//timeAcc = dt;
					currentStatus = NS_Running;
				}

				else
				{
					currentStatus = NS_Failed;
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
				//    /*if (isNear(me->GetBody().GetPos(), me->GetTargetPOS()))
				//    {
				//      currentStatus = NS_Completed;
				//      me->GetMovement().SetIdleSpeed();
				//    }*/
				//  }
				//}
				//else
				//{
				//  currentStatus = NS_Failed;
			}

			else
			{
				currentStatus = NS_Failed;
			}
		}
		else
		{
			timer += dt;
			currentStatus = NS_Running;
		}
	}
	else {
		timeAcc += dt;
		currentStatus = NS_Running;
		
	}

}
END_LEAF_UPDATE_FUNC
ON_EDIT_FUNC(FleeCop)
{
 // ImGui::Checkbox("Jog", &jog);
}
END_ON_EDIT_FUNC
NODE_MSG_RECEIVED(FleeCop)
{
	if(name == VICTIM_KILLED_RESPONSE)
	{
		copID = data.GetObjectID();
	}
}
END_NODE_MSG_RECEIVED