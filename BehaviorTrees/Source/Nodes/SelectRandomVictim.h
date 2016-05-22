DEFINE_LEAF_NODE(SelectRandomVictim, "Select a random civilian to try and kill", GameObject* victim; void OnEdit();)
//Figure out how to send a message to a given target AND ensure that message is received and acted upon properly no matter what node you're in
//Current idea:  get # of game characters--size of game objects array, I presume--randomly choose one.
//				 Ping with a 'targeted' message
//				 All other actors should respond with their status--either civilian or cop
//				 Only want to target civilians, so, if the message returned is 'cop', fail and run it again
//				 This broadcast message should NOT care what state each other actor is in, nor should it alert the actor as to who is the killer--it is only for the killer's targeting and pathing purposes