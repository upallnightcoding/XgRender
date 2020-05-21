#pragma once
#include "XgAction.h"
#include "XgCharacter.h"

class XgActionMove :
	public XgAction
{
public:
	XgActionMove(float speed);
	virtual ~XgActionMove();

public:
	virtual void update(float deltaTime, XgCharacter *item);

private:
	float speed;
};

