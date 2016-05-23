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
//static bool jog = false;
LEAF_UPDATE_FUNC(FalseArrest)
{
	if (currentStatus == NS_OnEnter)
	{
		timeAcc = 0.f;

	 }

	if (timeAcc >= 2000)
	{
		currentStatus = NS_Completed;
	}

	else
	{
		timeAcc = dt;
		currentStatus = NS_Running;
	}

  // if
  //  {

  //   /* if (isNear(me->GetBody().GetPos(), me->GetTargetPOS()))
  //    {
  //      currentStatus = NS_Completed;
  //      me->GetMovement().SetIdleSpeed();
  //    }*/
  //  
  //}
  //else
  //{
  //  currentStatus = NS_Failed;
  //}
}
END_LEAF_UPDATE_FUNC
ON_EDIT_FUNC(FalseArrest)
{
  //ImGui::Checkbox("Jog", &jog);
}
END_ON_EDIT_FUNC
NODE_MSG_RECEIVED(FalseArrest)
{
	//GameObject *me = g_database.Find(self);
	//if (name == MSG_Arrived)
	//{
	//	currentStatus = NS_Completed;
	//	me->GetMovement().SetIdleSpeed();

	//}
}
END_NODE_MSG_RECEIVED