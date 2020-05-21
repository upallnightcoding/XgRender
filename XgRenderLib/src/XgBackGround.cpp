#include "XgBackGround.h"



XgBackGround::XgBackGround(std::string imageName)
{
	flipBook = new XgFlipBook(1.0f);

	flipBook->add(imageName);

	this->add(flipBook);
}


XgBackGround::~XgBackGround()
{
	delete flipBook;
}


