#include "XgEventGoto.h"



XgEventGoto::XgEventGoto(std::string nextState) 
	: XgEvent(nextState)
{
}


XgEventGoto::~XgEventGoto()
{
}

/*****************************************************************************
hasOccured() -
*****************************************************************************/
bool XgEventGoto::hasOccured()
{
	return(true);
}
