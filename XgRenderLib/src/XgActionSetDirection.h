#pragma once
#include "XgAction.h"
#include "XgCharacter.h"

class XgActionSetDirection :
	public XgAction
{
public:
	XgActionSetDirection(float x, float y, float z);
	virtual ~XgActionSetDirection();

public:
	virtual void update(float deltaTime, XgCharacter *item);

private:
	float x, y, z;
	bool firstTime;
};

