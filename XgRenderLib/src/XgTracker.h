#pragma once

#include "Xg.h"
//#include "XgRenderContext.h"

class XgTracker
{
public:
	XgTracker();
	virtual ~XgTracker();

public:
	void set(GLFWwindow* window);

	virtual void update() = 0;

protected:
	GLFWwindow* window;
};

