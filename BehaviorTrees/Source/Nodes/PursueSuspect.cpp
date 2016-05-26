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
LEAF_UPDATE_FUNC(PursueSuspect)
{
	if (currentStatus == NS_OnEnter)
	{
		currentStatus = NS_Running;
		suspectID = -1;
		//timeAcc = dt;
	}


  GameObject *me = g_database.Find(self);
  GameObject *s = NULL;
  if (suspectID != -1)
  {
	  s = g_database.Find(suspectID);
  }


  float randomScale = 0.5f * (rand() % 13);
  //if (timeAcc >= ((rand() % 3000)/1000.f))  //Time is in ms?
  //{
	 // currentStatus = NS_Completed;
  //}

  //else if (me)
  if(me)
  {
   
      
       me->GetMovement().SetJogSpeed();
	   if (suspectID != -1)
	   {
		   me->GetMovement().SetTarget(me->GetTargetPOS() + randomScale * (s->GetBody().GetDir()));
		   //timeAcc = dt;
		   currentStatus = NS_Running;
	   }

	   else
	   {
		   currentStatus = NS_Failed;
	   }
      
    
   
      /*if (isNear(me->GetBody().GetPos(), me->GetTargetPOS()))
      {
        currentStatus = NS_Completed;
        me->GetMovement().SetIdleSpeed();
      }*/
    
  }

 
  else
  {
    currentStatus = NS_Failed;
  }
}
END_LEAF_UPDATE_FUNC
ON_EDIT_FUNC(PursueSuspect)
{
//  ImGui::Checkbox("Jog", &jog);
}
END_ON_EDIT_FUNC
NODE_MSG_RECEIVED(PursueSuspect)
{
if (name == VICTIM_KILLED_BROADCAST)
	{
		suspectID = data.GetObjectID();
		IBTNode::SendMsg(VICTIM_KILLED_RESPONSE, data.GetObjectID(), self, "FleeCop", MSG_Data(self));

		/*for (int i = 0; i < g_database.GetSize(); ++i)
		{
			if (i != static_cast<int>(self) && i != static_cast<int>(suspectID))
			{
				IBTNode::SendMsg(VICTIM_KILLED_RESPONSE, static_cast<objectID>(i), self, "CivilianIdle", MSG_Data(self));
			}
		}*/
	}
}
END_NODE_MSG_RECEIVED