#include "XgCamera.h"



XgCamera::XgCamera()
{
	
}

XgCamera::~XgCamera()
{
}

/******************************************************************************
add() -
******************************************************************************/
void XgCamera::add(XgTracker *track)
{
	tracking.push_back(track);
}

/******************************************************************************
create() -
******************************************************************************/
void XgCamera::create(GLFWwindow* window)
{
	for (auto tracker : tracking) {
		tracker->set(window);
	}
}

/******************************************************************************
getView() - Returns the view matrix, based on the eye, center and up vector
position.
******************************************************************************/
glm::mat4 XgCamera::getView()
{
	return(telemetry.getLookAt());
}

/******************************************************************************
getViewPosition() - Returns the current position of the camera.
******************************************************************************/
glm::vec3 XgCamera::getPosition()
{
	return(telemetry.eye());
}

/******************************************************************************
update() - Updates the camera eye, center and up vector based on the virtual
function of the track object.  The "update" function executes each track
object.  Order of the track objects is based on the a first-in-first-out
processing rule.
******************************************************************************/
void XgCamera::update()
{
	// TODO This should be placed in the create() function
	//context->cameraTelemetry(&telemetry);

	for (auto track : tracking) {
		track->update();
	}
}
