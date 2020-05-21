#pragma once

#include "Xg.h"
#include "XgTransform.h"

class XgTexture
{
public:
	XgTexture();
	virtual ~XgTexture();

public:
	void create();
	void add(std::string texturePath);
	void dispose();
	void draw();
	void bindVao();
	void nextTexture();
	void collision();
	void worldCord(XgTransform &transform);

private:
	std::string imagePath;

	unsigned int vbo, vao, ebo;

	//unsigned int texture;
	std::vector<GLuint> textures;

	int activeTexture;
	int nTextures;

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

