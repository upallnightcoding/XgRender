#pragma once

#include "Xg.h"
#include "XgAction.h"

class XgBehavior
{
public:
	XgBehavior();
	virtual ~XgBehavior();

public:
	void add(XgAction *action);

	void update(float deltaTime, XgCharacter *item);

private:
	std::vector<XgAction*> behaviorList;
};

