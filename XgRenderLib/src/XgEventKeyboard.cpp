#include "XgEventKeyboard.h"
#include "XgKeyboard.h"


XgEventKeyboard::XgEventKeyboard(std::string nextState, int targetKey) 
	: XgEvent(nextState)
{
	this->targetKey = targetKey;
	this->keyHasAlreadyBeenPressed = false;
}


XgEventKeyboard::~XgEventKeyboard()
{
}

/*****************************************************************************
hasOccured() -
*****************************************************************************/
bool XgEventKeyboard::hasOccured()
{
	bool occured = false;

	bool keyPressed = XgKeyboard::getInstance()->isKeyPressed(targetKey);

	if (keyPressed && !keyHasAlreadyBeenPressed) {
		occured = true;
		keyHasAlreadyBeenPressed = true;
	}
	else if (keyPressed) {
		occured = false;
		keyHasAlreadyBeenPressed = true;
	}
	else {
		occured = false;
		keyHasAlreadyBeenPressed = false;
	}

	return(occured);
}
