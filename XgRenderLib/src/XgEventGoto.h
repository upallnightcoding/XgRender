#pragma once
#include "XgEvent.h"

class XgEventGoto :
	public XgEvent
{
public:
	XgEventGoto(std::string nextState);
	virtual ~XgEventGoto();

public:
	bool hasOccured();
};

