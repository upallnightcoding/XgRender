#pragma once

#include <wx/wx.h>
#include <wx/grid.h>

class XgInspectorPanel :
	public wxPanel
{
public:
	XgInspectorPanel(wxWindow *parent);
	virtual ~XgInspectorPanel();

private:
	void tableOnSize(wxSizeEvent &event);

	wxGrid *grid;
};

