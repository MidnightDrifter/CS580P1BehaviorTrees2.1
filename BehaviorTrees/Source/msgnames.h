/* Copyright Steve Rabin, 2013. 
 * All rights reserved worldwide.
 *
 * This software is provided "as is" without express or implied
 * warranties. You may freely copy and compile this source into
 * applications you distribute provided that the copyright text
 * below is included in the resulting source code, for example:
 * "Portions Copyright Steve Rabin, 2013"
 */

//These message names are processed inside msg.h

REGISTER_MESSAGE_NAME(MSG_NULL)							//Reserved message name
REGISTER_MESSAGE_NAME(MSG_GENERIC_TIMER)				//Reserved message name
REGISTER_MESSAGE_NAME(MSG_SPAWN_GENERIC_TIMER)			//Reserved message name
REGISTER_MESSAGE_NAME(MSG_CHANGE_STATE_DELAYED)			//Reserved message name
REGISTER_MESSAGE_NAME(MSG_CHANGE_SUBSTATE_DELAYED)		//Reserved message name

//Add new messages here

REGISTER_MESSAGE_NAME(MSG_EATEN)
REGISTER_MESSAGE_NAME(VICTIM_KILLED_BROADCAST) //  SH added name--killer broadcasts on successful kill, civilians run, cop starts pursuit
REGISTER_MESSAGE_NAME(PURSUIT_START_BROADCAST) //  SH added name--cop responds to victim killed broadcast, broadcasts start of pursuit step
REGISTER_MESSAGE_NAME(PURSUIT_IN_PROGRESS_BROADCAST)  //SH added name--cop broadcasts that pursuit is in-progress, gives killer position data to move them properly
REGISTER_MESSAGE_NAME(PURSUIT_IN_PROGRESS_RESPONSE)  //SH added name--killer responds to pursuit in progress broadcast, gives cop position data to move properly
REGISTER_MESSAGE_NAME(PURSUIT_END_BROADCAST)  //SH added name--cop broadcasts that pursuit phase is over, cop and killer can return to normal behaviors
REGISTER_MESSAGE_NAME(AGENT_TARGETED_PING)  //SH added name--killer pings a given agent, returns objectID if not cop, fails otherwise
REGISTER_MESSAGE_NAME(AGENT_TARGETED_RESPONSE) //SH added name--how to respond to a 'you've been targeted' ping
//Used for Zombie and Human demo state machines
REGISTER_MESSAGE_NAME(MSG_CheckTouch)
REGISTER_MESSAGE_NAME(MSG_Tagged)
REGISTER_MESSAGE_NAME(MSG_SetTargetPosition)
REGISTER_MESSAGE_NAME(MSG_Arrived)
REGISTER_MESSAGE_NAME(MSG_Reset)
REGISTER_MESSAGE_NAME(MSG_MouseClick)


//Unit test messages
REGISTER_MESSAGE_NAME(MSG_UnitTestMessage)
REGISTER_MESSAGE_NAME(MSG_UnitTestMessage2)
REGISTER_MESSAGE_NAME(MSG_UnitTestMessage3)
REGISTER_MESSAGE_NAME(MSG_UnitTestMessage4)
REGISTER_MESSAGE_NAME(MSG_UnitTestMessage5)
REGISTER_MESSAGE_NAME(MSG_UnitTestMessage6)
REGISTER_MESSAGE_NAME(MSG_UnitTestMessage7)
REGISTER_MESSAGE_NAME(MSG_UnitTestMessage8)
REGISTER_MESSAGE_NAME(MSG_UnitTestMessage9)
REGISTER_MESSAGE_NAME(MSG_UnitTestBroken)
REGISTER_MESSAGE_NAME(MSG_UnitTestPing)
REGISTER_MESSAGE_NAME(MSG_UnitTestAck)
REGISTER_MESSAGE_NAME(MSG_UnitTestDone)
REGISTER_MESSAGE_NAME(MSG_UnitTestTimer)
