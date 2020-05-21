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
	virtual bool OnInit();

	void createFrameworks(wxFrame *frame);

	wxFrame *frame;

private:
	void createMenu(wxFrame *frame);
	wxPanel *createFrameworksView(wxSplitterWindow *splittermain);
	wxPanel *createWorkSpace(wxSplitterWindow *splittermain);
	wxWindow *createFrameworksPanel(wxSplitterWindow *splittermain);
	wxPanel *createInspectorPanel(wxSplitterWindow *splittermain);
	wxWindow *createWorkSpacePanel(wxSplitterWindow *splittermain);
	wxPanel *createMessagePanel(wxSplitterWindow *splittermain);
};

IMPLEMENT_APP(XgRender)


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

	createFrameworks(frame);

	//frame->SetSizer(sizer);
	frame->SetAutoLayout(true);

	frame->Show();
	return true;
}

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

void XgRender::createFrameworks(wxFrame *frame)
{
	wxBoxSizer *sizer = new wxBoxSizer(wxHORIZONTAL);

	wxSplitterWindow *splitter = new wxSplitterWindow(frame, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_LIVE_UPDATE);

	sizer->Add(splitter, 1, wxBOTTOM | wxLEFT | wxEXPAND, 5);

	wxWindow *frameWorkPanel = createFrameworksPanel(splitter);

	wxWindow *workSpacePanel = createWorkSpacePanel(splitter);

	splitter->SplitVertically(frameWorkPanel, workSpacePanel);
	splitter->SetSashPosition(300, true);

	frame->SetSizer(sizer);
}

wxWindow *XgRender::createFrameworksPanel(wxSplitterWindow *splittermain)
{
	wxBoxSizer *sizer = new wxBoxSizer(wxHORIZONTAL);

	wxPanel *panel = new wxPanel(splittermain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL | wxNO_BORDER);

	wxSplitterWindow *splitter = new wxSplitterWindow(panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_LIVE_UPDATE);

	wxPanel *topPanel = createFrameworksView(splitter);

	wxPanel *bottomPanel = createInspectorPanel(splitter);

	splitter->SplitHorizontally(topPanel, bottomPanel);
	splitter->SetSashPosition(300, true);

	sizer->Add(splitter, 1, wxBOTTOM | wxLEFT | wxEXPAND, 5);

	panel->SetSizer(sizer);

	return(panel);
}

wxWindow *XgRender::createWorkSpacePanel(wxSplitterWindow *splittermain)
{
	wxPanel *panel = new wxPanel(splittermain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL | wxNO_BORDER);

	wxSplitterWindow *splitter = new wxSplitterWindow(panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_LIVE_UPDATE);

	wxPanel *topPanel = createWorkSpace(splitter);

	wxPanel *bottomPanel = createMessagePanel(splitter);

	splitter->SplitHorizontally(topPanel, bottomPanel);
	splitter->SetSashPosition(300, true);

	wxBoxSizer *sizer = new wxBoxSizer(wxHORIZONTAL);

	sizer->Add(splitter, 1, wxBOTTOM | wxLEFT | wxEXPAND, 5);

	panel->SetSizer(sizer);

	return(panel);
}

wxPanel *XgRender::createInspectorPanel(wxSplitterWindow *splittermain)
{
	XgInspectorPanel *inspectorPanel = new XgInspectorPanel(splittermain);

	return(inspectorPanel);
}

wxPanel *XgRender::createWorkSpace(wxSplitterWindow *splittermain)
{
	//wxPanel* noteBookPanel = new wxPanel(splittermain, wxID_ANY);
	wxPanel *noteBookPanel =
		new wxPanel(splittermain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL | wxNO_BORDER);

	wxNotebook* notebook = new wxNotebook(noteBookPanel, wxID_ANY);

	//wxPanel *canvasPanel = new wxPanel(notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL | wxNO_BORDER);

	int args[] = { WX_GL_RGBA, WX_GL_DOUBLEBUFFER, WX_GL_DEPTH_SIZE, 16, 0 };

	XgCanvas *canvas = new XgCanvas(notebook, args);

	wxTextCtrl* textCtrl1 = new wxTextCtrl(notebook, wxID_ANY, L"Tab 1 Contents");

	notebook->AddPage(canvas, L"Game");
	notebook->AddPage(textCtrl1, L"Tab 1");

	wxStaticBoxSizer *sizer = new wxStaticBoxSizer(wxVERTICAL, noteBookPanel, _T("Workspace"));

	sizer->Add(notebook, 1, wxALL | wxEXPAND, 5);

	noteBookPanel->SetSizer(sizer);

	return(noteBookPanel);
}

wxPanel *XgRender::createMessagePanel(wxSplitterWindow *splittermain)
{
	XgMessagePanel *messagePanel = new XgMessagePanel(splittermain);

	return(messagePanel);
}

wxPanel *XgRender::createFrameworksView(wxSplitterWindow *splittermain)
{
	wxPanel *panel = new wxPanel(splittermain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL | wxNO_BORDER);

	wxTreeCtrl *treeCntrl = new wxTreeCtrl(panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_HAS_BUTTONS | wxTR_SINGLE);

	wxTreeItemId treeRoot = treeCntrl->AddRoot(wxT("Project FirstGame"), 0, 0, new wxTreeItemData());

	wxTreeItemId environment = treeCntrl->AppendItem(treeRoot, wxT("Environment"), 1, 1, new wxTreeItemData());

	wxTreeItemId objects = treeCntrl->AppendItem(treeRoot, wxT("Objects"), 1, 1, new wxTreeItemData());

	wxStaticBoxSizer *sizer = new wxStaticBoxSizer(wxVERTICAL, panel, _T("Project"));

	sizer->Add(treeCntrl, 1, wxALL | wxEXPAND, 5);

	panel->SetSizer(sizer);

	return(panel);
}
