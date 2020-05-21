#include "XgProjectPanel.h"

#include <wx/treectrl.h>

XgProjectPanel::XgProjectPanel(wxWindow *parent) :
	wxPanel(
		parent,
		wxID_ANY,
		wxDefaultPosition,
		wxDefaultSize,
		wxTAB_TRAVERSAL | wxNO_BORDER
	)
{
	wxTreeCtrl *treeCntrl = new wxTreeCtrl(
		this, 
		wxID_ANY, 
		wxDefaultPosition, 
		wxDefaultSize, 
		wxTR_HAS_BUTTONS | wxTR_SINGLE
	);

	wxTreeItemId treeRoot = treeCntrl->AddRoot(wxT("Project FirstGame"), 0, 0, new wxTreeItemData());

	wxTreeItemId environment = treeCntrl->AppendItem(treeRoot, wxT("Environment"), 1, 1, new wxTreeItemData());

	wxTreeItemId objects = treeCntrl->AppendItem(treeRoot, wxT("Objects"), 1, 1, new wxTreeItemData());

	wxStaticBoxSizer *sizer = new wxStaticBoxSizer(wxVERTICAL, this, _T("Project"));

	sizer->Add(treeCntrl, 1, wxALL | wxEXPAND, 5);

	SetSizer(sizer);
}


XgProjectPanel::~XgProjectPanel()
{
}
