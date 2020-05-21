#include "XgBehavior.h"



XgBehavior::XgBehavior()
{
}


XgBehavior::~XgBehavior()
{
}

/*****************************************************************************
add() - 
*****************************************************************************/
void XgBehavior::add(XgAction *action)
{
	if (action != NULL) {
		behaviorList.push_back(action);
	}
}

/*****************************************************************************
update() - 
*****************************************************************************/
void XgBehavior::update(float deltaTime, XgCharacter *item)
{
	for (auto action : behaviorList) {
		action->update(deltaTime, item);
	}
}

