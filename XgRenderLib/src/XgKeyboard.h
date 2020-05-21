#pragma once

/*****************************************************************************
classs XgKeyboardEvent
*****************************************************************************/

class XgKeyboard
{
public:
	static XgKeyboard *instance;

	// Private constructor
	XgKeyboard()
	{
		pMouseXpos = pMouseYpos = 0.0;
		pXoffset = pYoffset = 0.0;

		key = scancode = action = mods = 0;
	}

public:
	static XgKeyboard *getInstance();

	void setMousePosition(double xpos, double ypos);
	void setScrollPosition(double xoffset, double yoffset);

	void zeroOffSet();

	double mouseXpos();
	double mouseYpos();

	double xOffset();
	double yOffSet();

	void setKey(int key, int scancode, int action, int mods);
	void getKey(int &key, int &scancode, int &action, int &mods);
	bool isKeyPressed(int targetKey);

private:
	double pMouseXpos;
	double pMouseYpos;
	double pXoffset;
	double pYoffset;

	int key;
	int scancode;
	int action;
	int mods;
};

