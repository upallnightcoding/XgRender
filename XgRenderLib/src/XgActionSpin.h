#pragma once
#include "XgAction.h"
#include "XgCharacter.h"

class XgActionSpin :
	public XgAction
{
public:
	XgActionSpin(float dx, float dy, float dz);
	virtual ~XgActionSpin();

public:
	virtual void update(float deltaTime, XgCharacter *item);

private:
	float dx;
	float dy;
	float dz;
};

