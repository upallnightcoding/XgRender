#include "XgCharacter.h"

#include "XgConstants.h"
#include "XgShaderObject.h"

XgCharacter::XgCharacter()
{
	localBehavior = new XgBehavior();
	shaderObject = new XgShaderObject(XgConstant::SPRITE_SHADER);
	collisionShader = new XgShaderObject("collision.shader");

	framework = NULL;
	flipBook = XgConstant::NO_FLIP_BOOK;
}

XgCharacter::~XgCharacter()
{
	delete localBehavior;

	if (framework != NULL) {
		delete framework;
	}

	delete shaderObject;

	delete collisionShader;
}

/*****************************************************************************
setScale() -
*****************************************************************************/
void XgCharacter::setScale(float xScale, float yScale)
{
	transform.scale(xScale, yScale);
}

/*****************************************************************************
add() -
*****************************************************************************/
void XgCharacter::add(XgFlipBook *flipBook)
{
	if (flipBook != NULL) {
		flipBook->setId(flipBookList.size());

		flipBookList.push_back(flipBook);
	}
}

/*****************************************************************************
update()
*****************************************************************************/
void XgCharacter::changeFlipBook(int flipBook)
{
	this->flipBook = flipBook;
}

/*****************************************************************************
animate()
*****************************************************************************/
void XgCharacter::dispose()
{

}

/*****************************************************************************
create() -
*****************************************************************************/
void XgCharacter::create()
{
	for (auto flipBook : flipBookList) {
		flipBook->create();
	}

	shaderObject->create();

	collisionShader->create();

	flipBook = 0;
}

/*****************************************************************************
render() - Renders the current image in the active flip book.  The scale of 
the image is set via the transform and the shader is then applied.  
*****************************************************************************/
void XgCharacter::render(XgCamera *camera, XgScreenSize *screenSize)
{
	if (flipBook != XgConstant::NO_FLIP_BOOK) {
		//flipBookList.at(flipBook)->setScale(&transform);

		//float hwRatio = flipBookList.at(flipBook)->getHeightWidthRatio();
		//hwRatio = 0.75;

		//flipBookList.at(flipBook)->setScale(hwRatio, hwRatio);

		//flipBookItem->bindVoa();

		XgFlipBook *flipBookItem = flipBookList.at(flipBook);

		flipBookItem->bindVao();

		collisionShader->apply(flipBookItem, camera, screenSize, transform);

		flipBookItem->collision();

		shaderObject->apply(flipBookItem, camera, screenSize, transform);

		flipBookItem->draw();

		glBindVertexArray(0);
	}
}

/*****************************************************************************
add() -
*****************************************************************************/
void XgCharacter::add(XgAction *action)
{
	if (action != NULL) {
		localBehavior->add(action);
	}
}

/*****************************************************************************
add() - Adds a framework object to an item.  The item can now be manipulated
by using the states and action of a framework.  If the object framework is
NULL, it is not added to the item object.
*****************************************************************************/
void XgCharacter::add(XgFramework *framework)
{
	if (framework != NULL) {
		this->framework = framework;
	}
}

/*****************************************************************************
update() -
*****************************************************************************/
void XgCharacter::update(float deltaTime)
{
	if (framework != NULL) {
		XgBehavior *behavior = framework->update();

		if (behavior != NULL) {
			behavior->update(deltaTime, this);
		}
	}

	localBehavior->update(deltaTime, this);

	flipBookList.at(flipBook)->update(deltaTime);
}

/*****************************************************************************
getTransform() - Returns a reference to the transform object.  This 
function should always return a non-NULL object.
*****************************************************************************/
XgTransform *XgCharacter::getTransform()
{
	return(&transform);
}
