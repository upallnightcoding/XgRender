#include "XgInspectorPanel.h"

//#include <wx/headerctrl.h>

XgInspectorPanel::XgInspectorPanel(wxWindow *parent) :
	wxPanel(
		parent,
		wxID_ANY,
		wxDefaultPosition,
		wxDefaultSize,
		wxTAB_TRAVERSAL | wxNO_BORDER
)
{
	grid = new wxGrid(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE);
	grid->CreateGrid(5, 2);
	grid->SetColLabelValue(0, wxT("Parameter"));
	grid->SetColLabelValue(1, wxT("Value"));
	grid->HideRowLabels();

	grid->SetCellRenderer(0, 1, new wxGridCellFloatRenderer(7, 2));
	grid->SetCellEditor(0, 1, new wxGridCellFloatEditor(7, 2));
	grid->SetCellAlignment(0, 1, wxALIGN_LEFT, wxALIGN_CENTRE);
	grid->SetCellRenderer(1, 1, new wxGridCellBoolRenderer());
	grid->SetCellEditor(1, 1, new wxGridCellBoolEditor());

	const wxString choices[] =
	{
		"Please select a choice",
		"This takes two cells",
		"Another choice",
	};
	grid->SetCellEditor(2, 1, new wxGridCellChoiceEditor(WXSIZEOF(choices), choices));

	wxFont font(wxFontInfo().Bold());

	grid->SetCellValue(3, 0, "Label ...");
	grid->SetCellFont(3, 0, font);

	//grid->SetWindowStyleFlag(grid->GetWindowStyle() & ~wxHSCROLL);
	//grid->ShowScrollbars(wxSHOW_SB_NEVER, wxSHOW_SB_DEFAULT);

	//wxSize fixed_size(300, 300);
	//grid->SetMinSize(fixed_size);
	//grid->SetMaxSize(fixed_size);
	//grid->SetSize(fixed_size);

	//grid->SetCellValue(0, 0, wxT("Translation"));
	//grid->SetCellValue(1, 0, wxT("Ratation"));
	//grid->SetCellValue(2, 0, wxT("Scaling"));

	wxStaticBoxSizer *sizer = new wxStaticBoxSizer(wxVERTICAL, this, _T("Inspector"));
	//wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
	sizer->Add(grid, 1, wxALL | wxEXPAND, 0);
	SetSizer(sizer);

	Bind(wxEVT_SIZE, &XgInspectorPanel::tableOnSize, this);
}


XgInspectorPanel::~XgInspectorPanel()
{
}

void XgInspectorPanel::tableOnSize(wxSizeEvent &event)
{
	grid->AutoSizeColumn(0);
	int columnWidth = grid->GetColSize(0);

	int scrollBarWidth = 0;
	if (grid->IsScrollbarShown(wxSYS_VSCROLL_X)) {
		scrollBarWidth = wxSystemSettings::GetMetric(wxSYS_VSCROLL_X);
	}

	int clientWidth = GetClientSize().GetWidth();

	int gapWidth = clientWidth - columnWidth - scrollBarWidth + 6;

	if (gapWidth > 0) {
		grid->SetColSize(1, gapWidth);
	}

	event.Skip();
}