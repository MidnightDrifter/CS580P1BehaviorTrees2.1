DEFINE_LEAF_NODE(PursueSuspect, "Officer chases another actor for a time", void OnEdit();)
//Broadcast pursuit mode
//Get another actor--the killer--and pursue them
//Chase for certain amount of time
//If get within X distance, arrest them
//Else, if someone else is within that distance at the end, arrest them--should be a civilian
//Move from Pursuing to checking the arrest--if killer, he 'loses'.  If civilian, move to FalseArrest node