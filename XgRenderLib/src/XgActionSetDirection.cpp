#include "XgActionSetDirection.h"



XgActionSetDirection::XgActionSetDirection(float x, float y, float z)
{
	firstTime = true;

	this->x = x;
	this->y = y;
	this->z = z;
}


XgActionSetDirection::~XgActionSetDirection()
{
}

/*****************************************************************************
update() -
*****************************************************************************/
void XgActionSetDirection::update(float deltaTime, XgCharacter *character)
{
	if (firstTime) {
		firstTime = false;

		character->getTransform()->setDirection(x, y, z);
	}
}