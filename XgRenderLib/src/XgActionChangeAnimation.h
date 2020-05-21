#pragma once
#include "XgAction.h"
#include "XgCharacter.h"
#include "XgFlipBook.h"

class XgActionChangeAnimation :
	public XgAction
{
public:
	XgActionChangeAnimation(XgFlipBook *flipBook);
	virtual ~XgActionChangeAnimation();

public:
	void update(float deltaTime, XgCharacter *item);

private:
	XgFlipBook *flipBook;
};

