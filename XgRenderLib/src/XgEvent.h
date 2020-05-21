#pragma once

#include "Xg.h"

class XgEvent
{
public:
	XgEvent(std::string nextState);
	virtual ~XgEvent();

public:
	virtual bool hasOccured() = 0;
	std::string getNextState();

private:
	std::string nextState;
};

