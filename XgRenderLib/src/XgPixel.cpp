#include "XgPixel.h"

#include "XgConstants.h"
#include "XgShaderObject.h"

XgPixel::XgPixel(std::string title, int screenWidth, int screenHeight)
	: XgWindow(title, screenWidth, screenHeight)
{

}

XgPixel::~XgPixel()
{
	delete paper;
}

/*****************************************************************************
render()
*****************************************************************************/
void XgPixel::initRender(GLFWwindow* window)
{
	paper->create();

	camera.setPosition(5.0);

	camera.create(window);
}

/*****************************************************************************
render()
*****************************************************************************/
void XgPixel::renderScreen(float &deltaTime, int &fps)
{
	//shader->use();

	//shader->uniform("u_View", camera.getView());

	//shader->uniform("u_Projection", screenSize->getPerspective());

	updateDeltaTime(deltaTime, fps);

	paper->animate(&camera, screenSize);
}

/*****************************************************************************
render()
*****************************************************************************/
void XgPixel::closeRender()
{

}

/*****************************************************************************
add() -
*****************************************************************************/
void XgPixel::add(XgPaper *paper)
{
	this->paper = paper;
}

/*****************************************************************************
render()
*****************************************************************************/
void XgPixel::updateDeltaTime(float &deltaTime, int &fps)
{
	while (deltaTime >= 1.0) {
		//camera.update(renderContext);
		//light.update();

		paper->update(deltaTime);

		//for (auto object : objectList) {
			//object->update(deltaTime);
		//}

		fps++;
		deltaTime--;
	}
}