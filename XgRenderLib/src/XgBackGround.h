#pragma once
#include "XgCharacter.h"
class XgBackGround :
	public XgCharacter
{
public:
	XgBackGround(std::string imageName);
	virtual ~XgBackGround();

private:
	XgFlipBook *flipBook;
};

