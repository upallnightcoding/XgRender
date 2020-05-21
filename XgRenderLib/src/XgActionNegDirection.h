#pragma once
#include "XgAction.h"
#include "XgCharacter.h"

class XgActionNegDirection :
	public XgAction
{
public:
	XgActionNegDirection();
	virtual ~XgActionNegDirection();

public:
	virtual void update(float deltaTime, XgCharacter *item);
};

