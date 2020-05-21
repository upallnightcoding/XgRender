#pragma once

#include "Xg.h"
#include "XgTransform.h"
#include "XgCamera.h"
//#include "XgLighting.h"
#include "XgScreenSize.h"
#include "XgFlipBook.h"

/*****************************************************************************
class XgShader
*****************************************************************************/
class XgShader
{
public:
	XgShader(std::string pathName);
	virtual ~XgShader();

public:
	virtual void apply(XgFlipBook *flipBook, XgCamera *camera, XgScreenSize *screenSize, XgTransform &transform) = 0;

	void use();
	void create();

public:
	void uniform(std::string name, glm::vec3 value);
	void uniform(std::string name, glm::vec4 value);
	void uniform(std::string name, glm::mat4 value);
	void uniform(std::string name, int value);
	void uniform(std::string name, float value);
	
private:
	std::string readShaderFile(const std::string pathname);
	int compile(const char *source, GLenum shaderType);
	void link(int vertexShader, int fragmentShader);

protected:
	int shaderProgram;
	std::string pathName;
};

