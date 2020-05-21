#include "XgKeyboard.h"

#include "Xg.h"

XgKeyboard *XgKeyboard::instance = 0;

/*****************************************************************************
getInstance() -
*****************************************************************************/
XgKeyboard *XgKeyboard::getInstance()
{
	if (instance == 0) {
		instance = new XgKeyboard();
	}

	return(instance);
}

/*****************************************************************************
setKey() -
*****************************************************************************/
void XgKeyboard::setKey(int key, int scancode, int action, int mods)
{
	this->key = key;
	this->scancode = scancode;
	this->action = action;
	this->mods = mods;
}

/*****************************************************************************
getKey() -
*****************************************************************************/
void XgKeyboard::getKey(int &key, int &scancode, int &action, int &mods)
{
	key = this->key;
	scancode = this->scancode;
	action = this->action;
	mods = this->mods;
}

bool XgKeyboard::isKeyPressed(int targetKey)
{
	return((targetKey == key) && (action == GLFW_PRESS));
}

/*****************************************************************************
zeroOffSet() -
*****************************************************************************/
void XgKeyboard::zeroOffSet()
{
	pXoffset = 0.0;
	pYoffset = 0.0;
}

/*****************************************************************************
setMousePosition() -
*****************************************************************************/
void XgKeyboard::setMousePosition(double xpos, double ypos)
{
	this->pMouseXpos = xpos;
	this->pMouseYpos = ypos;
}

/*****************************************************************************
setScrollPosition() -
*****************************************************************************/
void XgKeyboard::setScrollPosition(double xoffset, double yoffset)
{
	this->pXoffset = xoffset;
	this->pYoffset = yoffset;
}

/*****************************************************************************
getXpos()
*****************************************************************************/
double XgKeyboard::mouseXpos()
{
	return(pMouseXpos);
}

/*****************************************************************************
mouseYpos()
*****************************************************************************/
double XgKeyboard::mouseYpos()
{
	return(pMouseYpos);
}

/*****************************************************************************
xOffset()
*****************************************************************************/
double XgKeyboard::xOffset()
{
	return(pXoffset);
}

/*****************************************************************************
yOffSet()
*****************************************************************************/
double XgKeyboard::yOffSet()
{
	return(pYoffset);
}
