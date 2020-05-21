#include "XgPaper.h"



XgPaper::XgPaper()
{
	
}


XgPaper::~XgPaper()
{
	
}

/*****************************************************************************
animate()
*****************************************************************************/
void XgPaper::animate(XgCamera *camera, XgScreenSize *screenSize)
{
	// Animate all sprites that are on the paper
	//------------------------------------------
	for (auto item : itemList) {
		item->render(camera, screenSize);
	}
}

/*****************************************************************************
update() -
*****************************************************************************/
void XgPaper::update(float deltaTime)
{
	// Animate all entities that are on the paper
	//-------------------------------------------
	for (auto item : itemList) {
		item->update(deltaTime);
	}
}

/*****************************************************************************
create() -
*****************************************************************************/
void XgPaper::create()
{
	// Animate all entities that are on the paper
	//-------------------------------------------
	for (auto item : itemList) {
		item->create();
	}
}