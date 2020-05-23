#include "XgTestCase.h"

#include "XgBackGround.h"
#include "XgActionChangeAnimation.h"

XgTestCase::XgTestCase()
{
}


XgTestCase::~XgTestCase()
{
}

XgPaper *XgTestCase::characterIdle()
{
	std::string IDLE_STATE = "IDLE";

	XgBackGround *bg = new XgBackGround("BG.png");
	bg->setScale(5.0, 5.0);

	//XgFlipBook *idleFlipBook = new XgFlipBook(1.0f);
	XgFlipBook *idleFlipBook = new XgFlipBook(30.0f);
	idleFlipBook->add("Idle__000.png");
	idleFlipBook->add("Idle__001.png");
	idleFlipBook->add("Idle__002.png");
	idleFlipBook->add("Idle__003.png");
	idleFlipBook->add("Idle__004.png");
	idleFlipBook->add("Idle__005.png");
	idleFlipBook->add("Idle__006.png");
	idleFlipBook->add("Idle__007.png");
	idleFlipBook->add("Idle__008.png");
	idleFlipBook->add("Idle__009.png");

	XgState *idleState = new XgState(IDLE_STATE);
	idleState->add(new XgActionChangeAnimation(idleFlipBook));

	XgFramework *framework = new XgFramework();
	framework->add(idleState);

	XgCharacter *character = new XgCharacter();
	character->setScale(0.25f, 0.25f);
	//character->setScale(1.0f, 1.0f);
	character->add(framework);
	character->add(idleFlipBook);

	XgPaper *paper = new XgPaper();
	paper->add(character);
	//paper->add(bg);				// Background has to be last character added

	return(paper);
}
