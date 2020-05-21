#include "XgFramework.h"

#include "XgConstants.h"

XgFramework::XgFramework()
{
	this->currentState = NULL;
}


XgFramework::~XgFramework()
{
}

/*****************************************************************************
add()
*****************************************************************************/
void XgFramework::add(XgState *state)
{
	if (state != NULL) {
		if (currentState == NULL) {
			currentState = state;
		}

		states[state->name()] = state;
	}
}

/*****************************************************************************
update()
*****************************************************************************/
XgBehavior *XgFramework::update()
{
	XgBehavior *behavior = currentState->behavior();

	std::string nextState = currentState->update();

	if (nextState != XgConstant::EMPTY_STRING) {
		currentState = states[nextState];

		if (currentState != NULL) {
			behavior = currentState->behavior();
			//behavior->init();
		}
	}

	return(behavior);
}
