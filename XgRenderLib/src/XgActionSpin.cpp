#include "XgActionSpin.h"



XgActionSpin::XgActionSpin(float dx, float dy, float dz)
{
	this->dx = dx;
	this->dy = dy;
	this->dz = dz;
}

XgActionSpin::~XgActionSpin()
{
}

/*****************************************************************************
update()
*****************************************************************************/
void XgActionSpin::update(float deltaTime, XgCharacter *character)
{
	//transform.turn(dx, dy, dz);

	character->getTransform()->turn(dx, dy, dz);
}
