Student Name:  Sean Higgins
 
Project Name:	Dumbed Down Party Hard - Attempted

What I implemented:	I was able to implement basic messaging, acquisition and following of one actor by another, color changing, various conditional branchings, timers.  I attempted to implement a win condition, a lose condition, and a pursue-evade style of motion, but did not succeed.

Directions (if needed):  N/A, should run on its own

What I liked about the project and framework:	Once I got the macros down, it was relatively straightforward to go and create the various nodes.

What I disliked about the project and framework:  The major things I disliked were the shaky messaging system and the initial difficulty with the macros--things are SO abstracted it gets difficult to tell where a given data structure is and how to use it

Any difficulties I experienced while doing the project:	Messaging--synchronization issues, infinite loops

Hours spent:  30-35+

Agent Communication (file and line number):  Numerous, numerous files:

	SelectorMessageReader.cpp (and, SMRCop, SMRCivilian, by extension) - lines 29-37, NODE_MSG_RECEIVED block
	KillVictim.cpp - line 37, broadcast to all other actors
	FleeCop.cpp - line 41, respond to a broadcast; lines 93-100, get data from incoming message  NODE_MSG_RECEIVED block
	PursueSuspect.cpp - lines 81-97, get data from incoming message and respond with own message NODE_MSG_RECEIVED block
	SelectRandomVictim.cpp - line 30, ping a potential target for killer to stalk & kill; lines 53-89, store data from response, re-ping if necessary
	

New selector node (name):  SelectorSequencerRegardlessOfFail, SelectorMessageReader, SelectorMessageReaderCop,SelectorMessageReaderCivilian

New decorator nodes (names):  DecoratorRunXTimes, DecoratorRunXTimesOrUntilSucceed, DecoratorAlwaysSucceed

10 total nodes (names):  Along with the above nodes, I have:  ArrestTarget, CivilianIdle, Defeat, FalseArrest, FleeCop, KillVictim, PursueSuspect, SelectNearestTarget, SelectRandomVictim

3 Behavior trees (names):  Killer, Cop, Civilian

Extra credit:   N/A, basic steering motions were attempted