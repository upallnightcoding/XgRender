#pragma once

#include "Xg.h"

class XgCameraTelemetry
{
public:
	XgCameraTelemetry();
	virtual ~XgCameraTelemetry() {}

public:
	glm::mat4 getLookAt();

	glm::vec3 eye();

	void set(float x, float y, float z);

	void set(glm::vec3 eye, glm::vec3 center);

private:
	glm::vec3 pEye;
	glm::vec3 pCenter;
	glm::vec3 pUp;
};

/*****************************************************************************
set() - Sets the "eye" and "center" camera position and viewing direction.
*****************************************************************************/
inline void XgCameraTelemetry::set(glm::vec3 eye, glm::vec3 center)
{
	pEye = eye;
	pCenter = center;
}

/*****************************************************************************
getView() - Return the "lookAt" position of the camera telemetry.
*****************************************************************************/
inline glm::mat4 XgCameraTelemetry::getLookAt()
{
	return(glm::lookAt(pEye, pCenter, pUp));
}

/*****************************************************************************
eye() - Return the eye position of the camera.
*****************************************************************************/
inline glm::vec3 XgCameraTelemetry::eye()
{
	return(pEye);
}

/*****************************************************************************
set() - Set the "eye" position of the camera.  The "eye" position is 
defeined by the x, y, z components.
*****************************************************************************/
inline void XgCameraTelemetry::set(float x, float y, float z)
{
	pEye.x = x;
	pEye.y = y;
	pEye.z = z;
}

