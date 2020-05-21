#include "XgActionChangeAnimation.h"

#include "XgConstants.h"

XgActionChangeAnimation::XgActionChangeAnimation(XgFlipBook *flipBook)
{
	this->flipBook = flipBook;
}


XgActionChangeAnimation::~XgActionChangeAnimation()
{
}

/*****************************************************************************
update() -
*****************************************************************************/
void XgActionChangeAnimation::update(float deltaTime, XgCharacter *item)
{
	item->changeFlipBook(*flipBook->getId());
}