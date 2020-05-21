#pragma once

class XgCharacter;

class XgAction
{
public:
	XgAction();
	virtual ~XgAction();

public:
	virtual void update(float deltaTime, XgCharacter *character) = 0;
};

#include "XgCharacter.h"