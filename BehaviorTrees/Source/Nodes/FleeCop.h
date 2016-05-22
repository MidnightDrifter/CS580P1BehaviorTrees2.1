DEFINE_LEAF_NODE(FleeCop, "Killer flees cop for duration of chase", objectID cID; void OnEdit();)

//Flee movement
//Suspect estimates cop's speed, gauges where the cop will go based on suspect's own speed, move in the opposite direction +/- some randomness
//  i.e.  Suspect knows cop will try to stop him a short ways ahead, find that spot, move in the vector AWAY from that spot for some time
//  May need a timer to keep them moving in a given direction for X time before re-evaluating