#pragma once

#include <wx/wx.h>

#include "XgMessagePanel.h"

class XgWorkSpacePanel :
	public wxPanel
{
public:
	XgWorkSpacePanel(wxWindow *parent, XgMessagePanel *messagePanel);
	virtual ~XgWorkSpacePanel();
};

