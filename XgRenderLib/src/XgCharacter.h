#pragma once

#include "XgTransform.h"
#include "XgShader.h"
#include "XgAction.h"
#include "XgFlipBook.h"
#include "XgCamera.h"

class XgBehavior;
class XgFramework;

class XgCharacter
{
public:
	XgCharacter();
	virtual ~XgCharacter();

public:
	virtual void create();
	virtual void dispose();

	virtual void update(float deltaTime);

public:
	void add(XgFlipBook *flipBook);
	void add(XgAction *action);

	void changeFlipBook(int flipBook);

	void add(XgFramework *framework);

	void render(XgCamera *camera, XgScreenSize *screenSize);

	XgTransform *getTransform();

	void setScale(float xScale, float yScale);

private:
	std::vector<XgFlipBook*> flipBookList;
	int flipBook;

	XgTransform transform;

	XgFramework *framework;

	XgBehavior *localBehavior;

	XgShader *shaderObject;
	XgShader *collisionShader;
};

#include "XgBehavior.h"
#include "XgFramework.h"