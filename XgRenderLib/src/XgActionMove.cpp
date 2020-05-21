#include "XgActionMove.h"



XgActionMove::XgActionMove(float speed)
{
	this->speed = speed;
}

XgActionMove::~XgActionMove()
{
}

/*****************************************************************************
update() -
*****************************************************************************/
void XgActionMove::update(float deltaTime, XgCharacter *character)
{
	character->getTransform()->move(speed, deltaTime);
}
