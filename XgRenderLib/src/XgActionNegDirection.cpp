#include "XgActionNegDirection.h"



XgActionNegDirection::XgActionNegDirection()
{
}


XgActionNegDirection::~XgActionNegDirection()
{
}

/*****************************************************************************
add() -
*****************************************************************************/
void XgActionNegDirection::update(float deltaTime, XgCharacter *character)
{
	character->getTransform()->flipDirection();
}
