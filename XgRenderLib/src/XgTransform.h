#pragma once

#include "Xg.h"

class XgTransform
{
public:
	XgTransform();
	virtual ~XgTransform();

	glm::mat4 getTransformMatrix();
	glm::vec3 getPosition();
	glm::vec4 getColour();

	void setDirection(float x, float y, float z);

	void move(float x, float y, float z);
	void move(float speed, float deltaTime);

	void flipDirection();

	void turn(float x, float y, float z);

	void scale(float value);
	void scale(float x, float y);
	void scale(float x, float y, float z);
	
	void position(float x, float y, float z);
	void position(glm::vec3 point);
	void paint(glm::vec4 &colourObj);

	void sety(float value);

	void debugIt();

private:
	glm::vec3 translateObj;
	glm::vec3 rotateObj;
	glm::vec3 scaleObj;
	glm::vec4 colourObj;

	glm::vec3 direction;
};

inline void XgTransform::debugIt()
{
	std::cout << "Scale: " << scaleObj.x << ":" << scaleObj.y << ":" << scaleObj.z << std::endl;
}

