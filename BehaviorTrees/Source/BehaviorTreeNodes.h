// Include all node files here.
// Node files should have no include guard in them.
#ifndef BEHAVIOR_TREE_NODES_H
#define BEHAVIOR_TREE_NODES_H

//Selectors
#include "Nodes/SelectorWeightedRandom.h"  //SH added selecter
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
#include "Nodes/SelectWeightedRandomTarget.h"  //SH added leaf node

#endif
