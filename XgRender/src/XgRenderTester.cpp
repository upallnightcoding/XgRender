/*#ifndef _glpane_
#define _glpane_

#include "wx/wx.h"
#include "wx/glcanvas.h"


#endif*/

#include <wx/wx.h>
#include <wx/sizer.h>
#include <wx/glcanvas.h>
#include <wx/menu.h>
#include <wx/splitter.h>
#include <wx/treectrl.h>
#include <wx/grid.h>
#include <wx/notebook.h>

#include "XgMessagePanel.h"
#include "XgInspectorPanel.h"
#include "XgProjectPanel.h"
#include "XgWorkSpacePanel.h"

// include OpenGL
#ifdef __WXMAC__
#include "OpenGL/glu.h"
#include "OpenGL/gl.h"
#else
#include <GL/glu.h>
#include <GL/gl.h>
#endif

#include "XgCanvas.h"

class XgRender : public wxApp
{
public:
	XgRender();

public:
	virtual bool OnInit();

	void createRenderGUI(wxFrame *frame);

	wxFrame *frame;

private:
	void createMenu(wxFrame *frame);
	wxPanel *createProjectPanel(wxSplitterWindow *splittermain);
	wxPanel *createWorkSpacePanel(wxSplitterWindow *splittermain, XgMessagePanel *messagePanel);
	wxWindow *createProjectArea(wxSplitterWindow *splittermain);
	wxPanel *createInspectorPanel(wxSplitterWindow *splittermain);
	wxWindow *createWorkSpaceArea(wxSplitterWindow *splittermain);
	XgMessagePanel *createMessagePanel(wxSplitterWindow *splittermain);

private:
	XgProjectPanel *projectPanel;
	XgMessagePanel *messagePanel;
	XgWorkSpacePanel *workSpacePanel;
	XgInspectorPanel *inspectorPanel;
};

IMPLEMENT_APP(XgRender)

XgRender::XgRender()
{
	projectPanel = NULL;
	messagePanel = NULL;
	workSpacePanel = NULL;
	inspectorPanel = NULL;
}

/*****************************************************************************
setScale() -
*****************************************************************************/
bool XgRender::OnInit()
{
	wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
	frame = new wxFrame((wxFrame *)NULL, -1, wxT("XgRender v1.0"), wxPoint(50, 50), wxSize(700, 500));

	int args[] = { WX_GL_RGBA, WX_GL_DOUBLEBUFFER, WX_GL_DEPTH_SIZE, 16, 0 };

	createMenu(frame);

	//glPane = new BasicGLPane((wxFrame*)frame, args);
	//glPane = new XgCanvas((wxFrame*)frame, args);
	//glPane = NULL;
	//sizer->Add(glPane, 1, wxEXPAND);

	createRenderGUI(frame);

	//frame->SetSizer(sizer);
	frame->SetAutoLayout(true);

	frame->Show();
	return true;
}

/*****************************************************************************
setScale() -
*****************************************************************************/
void XgRender::createMenu(wxFrame *frame)
{
	wxMenuBar *menuBar = new wxMenuBar();

	wxMenu *fileMenu = new wxMenu();
	fileMenu->Append(wxID_OPEN, wxT("&Open..."), wxT("Opens a file"));
	fileMenu->AppendSeparator();
	fileMenu->Append(wxID_EXIT, wxT("&Exit..."), wxT("Close program ..."));

	menuBar->Append(fileMenu, wxT("&File"));

	frame->SetMenuBar(menuBar);
}

/*****************************************************************************
setScale() -
*****************************************************************************/
void XgRender::createRenderGUI(wxFrame *frame)
{
	wxBoxSizer *sizer = new wxBoxSizer(wxHORIZONTAL);

	wxSplitterWindow *splitter = new wxSplitterWindow(frame, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_LIVE_UPDATE);

	sizer->Add(splitter, 1, wxBOTTOM | wxLEFT | wxEXPAND, 5);

	wxWindow *frameWorkPanel = createProjectArea(splitter);

	wxWindow *workSpacePanel = createWorkSpaceArea(splitter);

	splitter->SplitVertically(frameWorkPanel, workSpacePanel);
	splitter->SetSashPosition(300, true);

	frame->SetSizer(sizer);
}

/*****************************************************************************
setScale() -
*****************************************************************************/
wxWindow *XgRender::createProjectArea(wxSplitterWindow *splittermain)
{
	wxBoxSizer *sizer = new wxBoxSizer(wxHORIZONTAL);

	wxPanel *panel = new wxPanel(splittermain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL | wxNO_BORDER);

	wxSplitterWindow *splitter = new wxSplitterWindow(panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_LIVE_UPDATE);

	wxPanel *projectPanel = createProjectPanel(splitter);

	wxPanel *inspectorPanel = createInspectorPanel(splitter);

	splitter->SplitHorizontally(projectPanel, inspectorPanel);
	splitter->SetSashPosition(300, true);

	sizer->Add(splitter, 1, wxBOTTOM | wxLEFT | wxEXPAND, 5);

	panel->SetSizer(sizer);

	return(panel);
}

/*****************************************************************************
setScale() -
*****************************************************************************/
wxWindow *XgRender::createWorkSpaceArea(wxSplitterWindow *splittermain)
{
	wxPanel *panel = new wxPanel(splittermain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL | wxNO_BORDER);

	wxSplitterWindow *splitter = new wxSplitterWindow(panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_LIVE_UPDATE);

	XgMessagePanel *messagePanel = createMessagePanel(splitter);

	wxPanel *workSpacePanel = createWorkSpacePanel(splitter, messagePanel);

	splitter->SplitHorizontally(workSpacePanel, messagePanel);
	splitter->SetSashPosition(300, true);

	wxBoxSizer *sizer = new wxBoxSizer(wxHORIZONTAL);

	sizer->Add(splitter, 1, wxBOTTOM | wxLEFT | wxEXPAND, 5);

	panel->SetSizer(sizer);

	return(panel);
}

/*****************************************************************************
createInspectorPanel() -
*****************************************************************************/
wxPanel *XgRender::createInspectorPanel(wxSplitterWindow *splittermain)
{
	inspectorPanel = new XgInspectorPanel(splittermain);

	return(inspectorPanel);
}

/*****************************************************************************
createWorkSpacePanel() -
*****************************************************************************/
wxPanel *XgRender::createWorkSpacePanel(wxSplitterWindow *splittermain, XgMessagePanel *messagePanel)
{
	workSpacePanel = new XgWorkSpacePanel(splittermain, messagePanel);

	return(workSpacePanel);
}

/*****************************************************************************
createMessagePanel() -
*****************************************************************************/
XgMessagePanel *XgRender::createMessagePanel(wxSplitterWindow *splittermain)
{
	messagePanel = new XgMessagePanel(splittermain);

	return(messagePanel);
}

/*****************************************************************************
createProjectPanel() -
*****************************************************************************/
wxPanel *XgRender::createProjectPanel(wxSplitterWindow *splittermain)
{
	projectPanel = new XgProjectPanel(splittermain);

	return(projectPanel);
}
