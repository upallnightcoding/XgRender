#include "XgMessagePanel.h"



XgMessagePanel::XgMessagePanel(wxWindow *parent) : 
	wxPanel(
		parent, 
		wxID_ANY, 
		wxDefaultPosition, 
		wxDefaultSize, 
		wxTAB_TRAVERSAL | wxNO_BORDER
)
{
	listBox = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);

	listBox->Append(wxT("Testing 1"));
	listBox->Append(wxT("Testing 2"));
	listBox->Append(wxT("Testing 3"));
	listBox->Append(wxT("Testing 4"));
	listBox->Append(wxT("Testing 5"));

	displayText("Place this at the end ...");

	wxStaticBoxSizer *sizer = new wxStaticBoxSizer(wxVERTICAL, this, _T("Message Panel"));

	sizer->Add(listBox, 1, wxALL | wxEXPAND, 5);

	SetSizer(sizer);
}


XgMessagePanel::~XgMessagePanel()
{
}

void XgMessagePanel::displayText(wxString text)
{
	listBox->Append(text);
}
