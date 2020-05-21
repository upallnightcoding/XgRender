#include "XgState.h"

#include "XgConstants.h"

XgState::XgState(std::string name)
{
	this->pName = name;
	this->pBehavior = new XgBehavior();
}


XgState::~XgState()
{
	if (pBehavior != NULL) {
		delete pBehavior;
	}

	for (XgEvent *event : pEventList) {
		if (event != NULL) {
			delete event;
		}
	}
}

/*****************************************************************************
update() - Traverses through each event until it one of the events has 
become true.  The first event the has come true, will end the loop and 
determine the next state of the framework.  If all events are false, the 
behavior remains in the current state.
*****************************************************************************/
std::string XgState::update()
{
	std::string nextState = XgConstant::EMPTY_STRING;

	int nEvents = pEventList.size();

	// Loop through each state event, until a true event has been found
	//-----------------------------------------------------------------
	for (int i = 0; (i < nEvents) && (nextState == XgConstant::EMPTY_STRING); i++) {
		XgEvent *event = pEventList.at(i);
		if (event->hasOccured()) {
			nextState = event->getNextState();
		}
	}

	return(nextState);
}

/*****************************************************************************
add() - Adds an event to the current state.  The events are executed in the 
order inwhich they were inserted.  A null event, can not be added to a
state.  
*****************************************************************************/
void XgState::add(XgEvent *event)
{
	if (event != NULL) {
		pEventList.push_back(event);
	}
}

/*****************************************************************************
add() -
*****************************************************************************/
void XgState::add(XgAction *action)
{
	pBehavior->add(action);
}

/*****************************************************************************
add() -
*****************************************************************************/
//void XgState::add(XgBehavior *behavior)
//{
	//pBehavior = behavior;
//}

/*****************************************************************************
getName() - Returns the name of the state.
*****************************************************************************/
std::string XgState::name()
{
	return(pName);
}

/*****************************************************************************
getBehavior() - Returns the behavior of the state
*****************************************************************************/
XgBehavior *XgState::behavior()
{
	return(pBehavior);
}
