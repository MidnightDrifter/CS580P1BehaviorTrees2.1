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


//NOTE TO SELF:   CivilianMessageReceiver WILL BE THE HEAD OF BOTH THE CIVILIAN AND COP NODES


static bool jog = false;
LEAF_UPDATE_FUNC(CivilianMessageReceiver)
{
//{
//  GameObject *me = g_database.Find(self);
//  if (me)
//  {
//    if (currentStatus == NS_OnEnter)
//    {
//      if (jog)me->GetMovement().SetJogSpeed();
//      else me->GetMovement().SetWalkSpeed();
//      me->GetMovement().SetTarget(me->GetTargetPOS());
//      currentStatus = NS_Running;
//    }
//    else
//    {
//     /* if (isNear(me->GetBody().GetPos(), me->GetTargetPOS()))
//      {
//        currentStatus = NS_Completed;
//        me->GetMovement().SetCivilianMessageReceiverSpeed();
//      }*/
//    }
//  }
//  else
//  {
//    currentStatus = NS_Failed;
//  }
}
END_LEAF_UPDATE_FUNC
ON_EDIT_FUNC(CivilianMessageReceiver)
{
  //ImGui::Checkbox("Jog", &jog);
}
END_ON_EDIT_FUNC



NODE_MSG_RECEIVED(CivilianMessageReceiver)
{
	//GameObject* me = g_database.Find(self);
	if (name == AGENT_TARGETED_PING)
	{
		IBTNode::SendMsg(AGENT_TARGETED_RESPONSE, data.GetObjectID(), self, "MessageReceiver", MSG_Data(self));
	}


}
END_NODE_MSG_RECEIVED