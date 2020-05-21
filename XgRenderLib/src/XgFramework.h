#pragma once

#include "Xg.h"
#include "XgState.h"

class XgFramework
{
public:
	XgFramework();
	virtual ~XgFramework();

public:
	void add(XgState *state);
	XgBehavior *update();

private:
	std::map<std::string, XgState*> states;
	XgState *currentState;
};

