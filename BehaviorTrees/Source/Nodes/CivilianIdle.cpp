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


//NOTE TO SELF:   CivilianIdle WILL BE THE HEAD OF BOTH THE CIVILIAN AND COP NODES


//static bool jog = false;
LEAF_UPDATE_FUNC(CivilianIdle)
{
 // GameObject *me = g_database.Find(self);
 // if (me)
 // {
    if (currentStatus == NS_OnEnter)
    {
		timeAcc = dt;
      currentStatus = NS_Running;
    }

	

    if(timeAcc >= ((rand() % 2500)/1000.f))
    {
		currentStatus = NS_Completed;
    }
 // }
  else
  {
	  //timeAcc = dt;
    currentStatus = NS_Running;
  }
}
END_LEAF_UPDATE_FUNC
ON_EDIT_FUNC(CivilianIdle)
{
  //ImGui::Checkbox("Jog", &jog);
}
END_ON_EDIT_FUNC



NODE_MSG_RECEIVED(CivilianIdle)
{
	if (name == AGENT_TARGETED_PING)
	{
		IBTNode::SendMsg(AGENT_TARGETED_RESPONSE, data.GetObjectID(), self, "SelectRandomVictim", MSG_Data(0));
	}

	//else if (name == ARREST_TARGET)
	//{
	//	IBTNode::SendMsg(,data.GetObjectID(),self,"")
	//}
}
END_NODE_MSG_RECEIVED