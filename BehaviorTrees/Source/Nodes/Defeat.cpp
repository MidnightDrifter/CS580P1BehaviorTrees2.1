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
LEAF_UPDATE_FUNC(Defeat)
{
  GameObject *me = g_database.Find(self);
  if (me)
  {
	  me->GetTiny().SetDiffuse(0.9f, 0.9f, 0.9f);  //Color my Tiny black
  }
}
END_LEAF_UPDATE_FUNC
ON_EDIT_FUNC(Defeat)
{
  ImGui::Checkbox("Jog", &jog);
}
END_ON_EDIT_FUNC
NODE_MSG_RECEIVED(Defeat)
{
	GameObject *me = g_database.Find(self);
	if (name == MSG_Arrived)
	{
		currentStatus = NS_Completed;
		me->GetMovement().SetIdleSpeed();

	}
}
END_NODE_MSG_RECEIVED