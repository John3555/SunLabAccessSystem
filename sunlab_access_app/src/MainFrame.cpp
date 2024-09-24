#include "MainFrame.h"
#include "AccessHistoryPanel.h"
#include "StudentManagementPanel.h"

MainFrame::MainFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600)) {
    wxPanel* panel = new wxPanel(this, wxID_ANY);
    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

    wxButton* viewLogsButton = new wxButton(panel, wxID_ANY, wxT("View Access Logs"));
    wxButton* manageStudentsButton = new wxButton(panel, wxID_ANY, wxT("Manage Students"));

    vbox->Add(viewLogsButton, 0, wxEXPAND | wxALL, 10);
    vbox->Add(manageStudentsButton, 0, wxEXPAND | wxALL, 10);

    panel->SetSizer(vbox);

    // Bind buttons to methods
    Connect(viewLogsButton->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnViewLogs));
    Connect(manageStudentsButton->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnManageStudents));
}

void MainFrame::OnViewLogs(wxCommandEvent& event) {
    wxPanel* accessPanel = new AccessHistoryPanel(this);
    accessPanel->Show();
}

void MainFrame::OnManageStudents(wxCommandEvent& event) {
    wxPanel* studentPanel = new StudentManagementPanel(this);
    studentPanel->Show();
}
