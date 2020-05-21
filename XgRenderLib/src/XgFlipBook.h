#pragma once

#include "XgTransform.h"
#include "XgTexture.h"

/*****************************************************************************
XgFlipBook
*****************************************************************************/
class XgFlipBook
{
public:
	XgFlipBook(float speed);
	virtual ~XgFlipBook();

public:
	void add(std::string texturePath);
	
	void draw();
	void collision();
	void create();
	void update(float deltaTime);

	void setId(int flipBookId);
	int *getId();

	void worldCord(XgTransform &transform);

	float getHeightWidthRatio();

	void bindVao();

private:
	// List of animation images
	XgTexture texture;

	std::vector<std::string> texturePaths;

	// Current speed of animation
	float animationSpeed;
	float speedBuffer;
	float speed;

	int *spriteId;
};


