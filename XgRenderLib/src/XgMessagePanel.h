#pragma once

#include <wx/wx.h>

class XgMessagePanel :
	public wxPanel
{
public:
	XgMessagePanel(wxWindow *parent);
	virtual ~XgMessagePanel();

public:
	void displayText(wxString text);

private:
	wxListBox *listBox;
};

