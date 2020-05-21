#include "XgWorkSpacePanel.h"

#include <wx/notebook.h>
#include <wx/glcanvas.h>

#include "XgCanvas.h"

XgWorkSpacePanel::XgWorkSpacePanel(wxWindow *parent) :
	wxPanel(
		parent,
		wxID_ANY,
		wxDefaultPosition,
		wxDefaultSize,
		wxTAB_TRAVERSAL | wxNO_BORDER
	)
{
	wxNotebook* notebook = new wxNotebook(this, wxID_ANY);

	int args[] = { WX_GL_RGBA, WX_GL_DOUBLEBUFFER, WX_GL_DEPTH_SIZE, 16, 0 };

	wxStaticBoxSizer *sizer = new wxStaticBoxSizer(wxVERTICAL, this, _T("Workspace"));

	sizer->Add(notebook, 1, wxALL | wxEXPAND, 5);

	SetSizer(sizer);

	XgCanvas *canvas = new XgCanvas(notebook, args);

	wxTextCtrl* textCtrl1 = new wxTextCtrl(notebook, wxID_ANY, L"Tab 1 Contents");

	notebook->AddPage(canvas, L"Game");
	notebook->AddPage(textCtrl1, L"Tab 1");
}


XgWorkSpacePanel::~XgWorkSpacePanel()
{
}
