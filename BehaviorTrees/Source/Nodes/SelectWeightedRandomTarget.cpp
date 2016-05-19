#include "DXUT.h"
#include "../gameobject.h"
#include "../BehaviorTree.h"
#include "../database.h"
#include "../body.h"
#include "../movement.h"
LEAF_UPDATE_FUNC(SelectWeightedRandomTarget)
{
  GameObject *me = g_database.Find(self);
  if (me)
  {
    D3DXVECTOR3 target(0, 0, 0);
    target.x = weight1*((float)(rand() % 256) / 256.f);  //Only added the weight1 & weight2, may need to re-check this
    target.z = weight2*((float)(rand() % 256) / 256.f);
    me->SetTargetPOS(target);
    currentStatus = NS_Completed;
  }
  else
  {
    return NS_Failed;
  }
}
END_LEAF_UPDATE_FUNC

ON_EDIT_FUNC(SelectWeightedRandomTarget)
{

}
END_ON_EDIT_FUNC

NODE_MSG_RECEIVED(SelectWeightedRandomTarget)
{

}
END_NODE_MSG_RECEIVED