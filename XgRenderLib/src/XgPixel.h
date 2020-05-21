#pragma once

#include "XgCamera.h"
#include "XgPaper.h"

class XgPixel 
{
public:
	XgPixel(std::string title, int screenWidth, int screenHeight);
	virtual ~XgPixel();

public:
	void add(XgPaper *paper);

protected:
	virtual void initRender(GLFWwindow* window);
	virtual void renderScreen(float &deltaTime, int &fps);
	virtual void closeRender();

private:
	void updateDeltaTime(float &deltaTime, int &updates);

private:
	XgPaper *paper;
	XgCamera camera;
};

