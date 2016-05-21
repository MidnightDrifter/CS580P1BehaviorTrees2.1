#include "DXUT.h"
#include "../gameobject.h"
#include "../BehaviorTree.h"
#include "../database.h"
#include "../body.h"
#include "../movement.h"
#include <imgui_impl_dx9.h>

// helper function, copied from example.cpp with slight modifications.
objectID GetNearestAgent(objectID);

LEAF_UPDATE_FUNC(SelectNearestTarget)
{
  if (currentStatus == NS_OnEnter)
  {
    timeAccumulator = dt;
    currentStatus = NS_Running;
  }
  else if (currentStatus == NS_Running)
  {
    // The time accumulator isn't necessary, it is there so you can see it happening in 
    timeAccumulator += dt;
    float waitTime = static_cast<float>(rand() % 2000) / 1000.f;
    if (timeAccumulator >waitTime)
    {
      GameObject *me = g_database.Find(self);
      if (me)
      {
        objectID nearestAgent = GetNearestAgent(self);
        D3DXVECTOR3 target = g_database.Find(nearestAgent)->GetBody().GetPos();
        me->SetTargetPOS(target);
        currentStatus = NS_Completed;
      }
      else
      {
        currentStatus = NS_Failed;
      }
    }
  }
}
END_LEAF_UPDATE_FUNC


objectID GetNearestAgent(objectID self)
{
  float nearestDistance = 9999.0f;
  GameObject* nearestGameObject = 0;
  GameObject* m_owner = g_database.Find(self);
  dbCompositionList list;
  g_database.ComposeList(list, OBJECT_NPC);

  dbCompositionList::iterator i;
  for (i = list.begin(); i != list.end(); ++i)
  {
    if ((*i)->GetID() != self)
    {
      D3DXVECTOR3 npcPos = (*i)->GetBody().GetPos();
      D3DXVECTOR3 myPos = m_owner->GetBody().GetPos();
      D3DXVECTOR3 diff = npcPos - myPos;
      float distance = D3DXVec3Length(&diff);

      if (nearestGameObject)
      {
        if (distance < nearestDistance)
        {
          nearestDistance = distance;
          nearestGameObject = *i;
        }
      }
      else
      {
        nearestDistance = distance;
        nearestGameObject = *i;
      }
    }
  }

  return(nearestGameObject->GetID());
}

ON_EDIT_FUNC(SelectNearestTarget)
{
  
}
END_ON_EDIT_FUNC

NODE_MSG_RECEIVED(SelectNearestTarget)
{

}
END_NODE_MSG_RECEIVED