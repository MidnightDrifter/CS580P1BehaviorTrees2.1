// Include all node files here.
// Node files should have no include guard in them.
#ifndef BEHAVIOR_TREE_NODES_H
#define BEHAVIOR_TREE_NODES_H

//Selectors
#include "Nodes/SelectorRandomUntilFail.h"  //SH added selector
#include "Nodes/SelectorRandom.h"
#include "Nodes/SelectorSequencer.h"


//Decorators
#include "Nodes/DecoratorInverter.h"
#include "Nodes/DecoratorRunUntilSucceed.h"
#include "Nodes/DecoratorRunXTimes.h"  //SH added decorator
#include "Nodes/DecoratorRunUntilFail.h"  //SH added decorator
#include "Nodes/DecoratorRunXTimesOrUntilSucceed.h"  //SH added decorator


//General leaf nodes
#include "Nodes/PathToTarget.h"
#include "Nodes/SelectRandomTarget.h"
#include "Nodes/SelectFurthestTarget.h"
#include "Nodes/SelectNearestTarget.h"  //SH added leaf node
#include "Nodes/FleeCop.h"  //SH added leaf node
#include "Nodes/PursueSuspect.h"  //SH added leaf node


#include "Nodes/KillVictim.h" //SH added leaf node
#include "Nodes/Victory.h"  //SH added leaf node
#include "Nodes/Defeat.h"  //SH added leaf node
#include "Nodes/FalseArrest.h"  //SH added leaf node
#include "Nodes/SelectRandomVictim.h"  //SH added leaf node
#include "Nodes/Idle.h" //SH added leaf node


//IGNORE THESE
/*
#include "Nodes/BroadcastKillerStatus.h"  //SH added leaf node
#include "Nodes/BroadcastCivilianStatus.h"  //SH added leaf node
#include "Nodes/BroadcastCopStatus.h" //SH added leaf node
*/



#endif
