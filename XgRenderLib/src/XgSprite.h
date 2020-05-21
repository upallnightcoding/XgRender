#pragma once

#include "Xg.h"
#include "XgTransform.h"

class XgSprite 
{
public:
	XgSprite(std::string texturePath);
	virtual ~XgSprite();

public:
	virtual void dispose();
	virtual void draw();
	virtual void create();

	virtual void collision();

	float getHeightWidthRatio();

	void worldCord(XgTransform &transform);

	void bindVao();

private:
	void dataFormat();
	void loadTexture();

private:
	std::string imagePath;

	unsigned int vbo, vao, ebo;

	unsigned int texture;

	int width, height;
	
	float vertices[32] = {
		// Positions          // Colors           // Texture Coordinates
		 1.0f,  1.0f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // Top Right
		 1.0f, -1.0f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // Bottom Right
		-1.0f, -1.0f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // Bottom Left
		-1.0f,  1.0f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // Top Left 
	};

	unsigned int indices[6] = {
		0, 1, 3, // First Triangle
		1, 2, 3  // Second Triangle
	};
};



