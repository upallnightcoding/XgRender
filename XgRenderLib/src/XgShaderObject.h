#pragma once
#include "XgShader.h"
#include "XgCamera.h"
#include "XgFlipBook.h"

class XgShaderObject :
	public XgShader
{
public:
	XgShaderObject(std::string pathName);
	virtual ~XgShaderObject();

public:
	virtual void apply(
		XgFlipBook *flipBook, 
		XgCamera *camera, 
		XgScreenSize *screenSize, 
		XgTransform &transform
	);
};

