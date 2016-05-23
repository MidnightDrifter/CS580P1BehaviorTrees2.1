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
static bool jog = false;
LEAF_UPDATE_FUNC(FleeCop)
{
	if (currentStatus == NS_OnEnter)
	{
		copID = -1;
		timeAcc = 0.f;
	}

  GameObject *me = g_database.Find(self);
  GameObject *c = NULL;

  

  float randomScale = 0.5 * (rand() % 13);


  if (copID != -1)
  {
	  c = g_database.Find(copID);
  }

  if (timeAcc >= 3000) //Time in ms?
  {
	  currentStatus = NS_Completed;
	  IBTNode::SendMsg(VICTIM_KILLED_BROADCAST, copID, self, "ArrestTarget", MSG_Data(self));
  }
  else if (me)
  {

	  me->GetMovement().SetJogSpeed();
	  if (copID != -1)
	  {
		  me->GetMovement().SetTarget(me->GetTargetPOS() - randomScale * (c->GetBody().GetDir()));
		  timeAcc = dt;
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