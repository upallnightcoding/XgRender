#include "XgTransform.h"

XgTransform::XgTransform()
{
	translateObj = glm::vec3(0.0f);
	rotateObj = glm::vec3(0.0f);
	scaleObj = glm::vec3(1.0);
	colourObj = glm::vec4(0.0, 0.0, 0.0, 1.0);

	direction = glm::vec3(0.0, 0.0, 0.0);
}

XgTransform::~XgTransform()
{
}

/******************************************************************************
setDirection() -
******************************************************************************/
void XgTransform::setDirection(float x, float y, float z)
{
	direction = glm::vec3(x, y, z);
}

/******************************************************************************
getTransformMatrix() - Create the transform matrix to manipulate the model
coordinates.  The model coordinates can be translated, rotated, and scaled.
This matrix is needed for the uniform calculation.
******************************************************************************/
glm::mat4 XgTransform::getTransformMatrix()
{
	// Set the transform identity matrix
	//----------------------------------
	glm::mat4 transform = glm::mat4(1.0f);

	// Set the transform tranlation
	//-----------------------------
	transform = glm::translate(transform, translateObj);

	// Set the transforma rotation (x, y z)
	//-------------------------------------
	transform = glm::rotate(transform, rotateObj.x, glm::vec3(1.0f, 0.0f, 0.0f));
	transform = glm::rotate(transform, rotateObj.y, glm::vec3(0.0f, 1.0f, 0.0f));
	transform = glm::rotate(transform, rotateObj.z, glm::vec3(0.0f, 0.0f, 1.0f));

	// Set the transform scale
	//------------------------
	transform = glm::scale(transform, scaleObj);

	return(transform);
}

/******************************************************************************
set() -
******************************************************************************/
void XgTransform::sety(float value)
{
	translateObj.y = value;
}

/******************************************************************************
move() -
******************************************************************************/
void XgTransform::move(float x, float y, float z)
{
	translateObj.x += x;
	translateObj.y += y;
	translateObj.z += z;
}

/******************************************************************************
move() - Adjust the position of the object based on the speed and current
delta time of the render loop.  
******************************************************************************/
void XgTransform::move(float speed, float deltaTime)
{
	translateObj.x += direction.x * speed * deltaTime;
	translateObj.y += direction.y * speed * deltaTime;
	translateObj.z += direction.z * speed * deltaTime;
}

/******************************************************************************
flipDirection() - 
******************************************************************************/
void XgTransform::flipDirection()
{
	direction.x *= -1.0;
	direction.y *= -1.0;
	direction.z *= -1.0;
}

/******************************************************************************
turn() -
******************************************************************************/

void XgTransform::turn(float x, float y, float z)
{
	rotateObj.x += glm::radians(x);
	rotateObj.y += glm::radians(y);
	rotateObj.z += glm::radians(z);
}

/******************************************************************************
position() -
******************************************************************************/
void XgTransform::position(glm::vec3 point)
{
	position(point.x, point.y, point.z);
}

/******************************************************************************
position() -
******************************************************************************/
void XgTransform::position(float x, float y, float z)
{
	translateObj.x = x;
	translateObj.y = y;
	translateObj.z = z;
}

/******************************************************************************
scale() - Multiplies the current scale values by new scales values.  This 
allows scaling to happen at multiple levels.
******************************************************************************/
void XgTransform::scale(float x, float y, float z)
{
	scaleObj.x = x;
	scaleObj.y = y;
	scaleObj.z = z;
}

/******************************************************************************
paint() -
******************************************************************************/
void XgTransform::paint(glm::vec4 &colourObj)
{
	this->colourObj = colourObj;
}

/*****************************************************************************
size() - Return the scaled size of the current objeft with x, y, and z 
scaling values equal.
*****************************************************************************/
void XgTransform::scale(float value)
{
	scale(value, value, value);
}

/*****************************************************************************
scale() -
*****************************************************************************/
void XgTransform::scale(float x, float y)
{
	scale(x, y, 1.0);
}

/*****************************************************************************
getPosition() - Returns the model position of the current object.
*****************************************************************************/
glm::vec3 XgTransform::getPosition()
{
	return(translateObj);
}

/*****************************************************************************
getColour() - Returns the current object color value.  This value is used to
determine the "uniform" color of the current object.
*****************************************************************************/
glm::vec4 XgTransform::getColour()
{
	return(colourObj);
}