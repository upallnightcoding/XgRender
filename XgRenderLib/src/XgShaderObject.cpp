#include "XgShaderObject.h"

#include "XgConstants.h"

XgShaderObject::XgShaderObject(std::string pathName)
	: XgShader(pathName)
{
	
}


XgShaderObject::~XgShaderObject()
{
}

void XgShaderObject::apply(
	XgFlipBook *flipBook, 
	XgCamera *camera, 
	XgScreenSize *screenSize, 
	XgTransform &transform
)
{
	//flipBook->worldCord(transform);

	use();

	uniform("u_View", camera->getView());

	uniform("u_Projection", screenSize->getPerspective());

	uniform(XgConstant::UNIFORM_TRANSFORM, transform.getTransformMatrix());
}
