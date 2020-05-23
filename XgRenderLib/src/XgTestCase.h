#pragma once

#include "XgPaper.h"

class XgTestCase
{
public:
	XgTestCase();
	virtual ~XgTestCase();

public:
	static XgPaper *characterIdle();
};

