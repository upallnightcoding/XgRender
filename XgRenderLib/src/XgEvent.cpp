#include "XgEvent.h"



XgEvent::XgEvent(std::string nextState)
{
	this->nextState = nextState;
}


XgEvent::~XgEvent()
{
}

/*****************************************************************************
getNextState() -
*****************************************************************************/
std::string XgEvent::getNextState()
{
	return(nextState);
}
