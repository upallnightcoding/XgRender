#include "XgFlipBook.h"


XgFlipBook::XgFlipBook(float speed)
{
	this->speed = speed;
	this->spriteId = new int();
}

XgFlipBook::~XgFlipBook()
{
}

/*****************************************************************************
setId() -
*****************************************************************************/
void XgFlipBook::setId(int flipBookId)
{
	*(this->spriteId) = flipBookId;
}

/*****************************************************************************
getId() -
*****************************************************************************/
int *XgFlipBook::getId()
{
	return(spriteId);
}


/*****************************************************************************
add() -
*****************************************************************************/
void XgFlipBook::add(std::string texturePath)
{
	texturePaths.push_back(texturePath);
}

/*****************************************************************************
create() -
*****************************************************************************/
void XgFlipBook::create()
{
	texture.create();

	for (std::string texturePath : texturePaths) {
		texture.add(texturePath);
	}

	animationSpeed = 60 / speed;
	speedBuffer = 0.0;
}

/*****************************************************************************
draw() - Executes the animation of a flipbook.  The transformation of the
object is set first via a uniform and the current sprite of the flipbook is
drawn with the current shader.
*****************************************************************************/
void XgFlipBook::draw()
{
	texture.draw();
}

void XgFlipBook::bindVao()
{
	texture.bindVao();
}

/*****************************************************************************
worldCord() -
*****************************************************************************/
void XgFlipBook::worldCord(XgTransform &transform)
{
	//spriteList.at(currentSprite)->worldCord(transform);
	texture.worldCord(transform);
}

/*****************************************************************************
getHeightWidthRatio() -
*****************************************************************************/
float XgFlipBook::getHeightWidthRatio()
{
	//return(spriteList.at(currentSprite)->getHeightWidthRatio());
	return(0.0f);
}

/*****************************************************************************
collision() -
*****************************************************************************/
void XgFlipBook::collision()
{
	//spriteList.at(currentSprite)->collision();
	texture.collision();
}

/*****************************************************************************
update() -
*****************************************************************************/
void XgFlipBook::update(float deltaTime)
{
	speedBuffer += deltaTime;

	if (speedBuffer > animationSpeed) {
		texture.nextTexture();
		speedBuffer = 0.0;
	}
}