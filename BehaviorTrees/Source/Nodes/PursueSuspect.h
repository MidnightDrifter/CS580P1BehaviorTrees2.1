DEFINE_LEAF_NODE(PursueSuspect, "Officer chases another actor for a time", objectID suspectID; float timeAcc; void OnEdit();)
//Broadcast pursuit mode
//Get another actor--the killer--and pursue them
//Chase for certain amount of time
//If get within X distance, arrest them
//Else, if someone else is within that distance at the end, arrest them--should be a civilian
//Move from Pursuing to checking the arrest--if killer, he 'loses'.  If civilian, move to FalseArrest node, broadcast end of pursuit

//Pursuit movement
//Similar to regular movement--can probably copy-paste most of the code, just extend out the vector the suspect is moving in a bit, have the cop path to that instead
//  i.e.  suspect is at X moving at some speed, path to the suspect's current position PLUS some small offset in the direction they're moving
//  May need a timer to keep them moving in a given direction for X time before re-evaluating